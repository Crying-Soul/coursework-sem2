#include "bmp.h"
#include "logger.h"
#include <fstream>

BMP::BMP(const std::string &fileName) : header(), pixelData() {
  std::ifstream file(fileName, std::ios::binary);
  if (!file.is_open()) {
    Logger::error("Failed to open input BMP file.");
    return;
  }

  file.read(reinterpret_cast<char *>(&header), sizeof(header));

  pixelData.resize(header.fileSize - header.dataOffset);
  file.read(reinterpret_cast<char *>(pixelData.data()), pixelData.size());

  file.close();
}

void BMP::mirror(const std::string &axis, const Coordinate &left_up,
                 const Coordinate &right_down) {
  int width = right_down.x - left_up.x;
  int height = right_down.y - left_up.y;
  if (axis == "x") {
    for (int y = left_up.y; y < right_down.y; ++y) {
      for (int x = left_up.x; x < left_up.x + width / 2; ++x) {
        int mirroredX = right_down.x - (x - left_up.x) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(mirroredX, y));
        setColor(mirroredX, y, tempColor);
      }
    }
  } else if (axis == "y") {
    for (int y = left_up.y; y < left_up.y + height / 2; ++y) {
      for (int x = left_up.x; x < right_down.x; ++x) {
        int mirroredY = right_down.y - (y - left_up.y) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(x, mirroredY));
        setColor(x, mirroredY, tempColor);
      }
    }
  }
}

void BMP::save(const std::string &fileName) {
  std::ofstream file(fileName, std::ios::binary);
  if (!file.is_open()) {
    Logger::error("Failed to create output BMP file.");
    return;
  }

  file.write(reinterpret_cast<char *>(&header), sizeof(header));
  file.write(reinterpret_cast<char *>(pixelData.data()), pixelData.size());

  file.close();
}

bool BMP::isValid() const { return !pixelData.empty(); }

RGB BMP::getColor(int x, int y) const {
  unsigned int index =
      ((header.height - 1 - y) * header.width + x) * (header.bitsPerPixel / 8);

  RGB color;
  color.blue = pixelData[index];
  color.green = pixelData[index + 1];
  color.red = pixelData[index + 2];
  return color;
}

void BMP::setColor(int x, int y, const RGB &newColor) {
  unsigned int index =
      ((header.height - 1 - y) * header.width + x) * (header.bitsPerPixel / 8);

  pixelData[index] = newColor.blue;
  pixelData[index + 1] = newColor.green;
  pixelData[index + 2] = newColor.red;
}
void BMP::colorReplace(const RGB &old_color, const RGB &new_color) {
  for (int y = 0; y < header.height; y++) {
    for (int x = 0; x < header.width; x++) {
      RGB current_color = getColor(x, y);
      if (current_color.red == old_color.red &&
          current_color.green == old_color.green &&
          current_color.blue == old_color.blue) {
        setColor(x, y, new_color);
      }
    }
  }
}
void BMP::split(int number_x, int number_y, int thickness, const RGB &color) {

  for (int i = 1; i < number_y; i++) {
    int gap = header.height / number_y;
    for (int x = 0; x < header.width; x++) {
      for (int y = 0; y < thickness; y++) {
        setColor(x, i * gap + y, color);
      }
    }
  }
  for (int i = 1; i < number_x; i++) {
    int gap = header.width / number_x;
    for (int x = 0; x < thickness; x++) {
      for (int y = 0; y < header.height; y++) {
        setColor(i * gap + x, y, color);
      }
    }
  }
}
void BMP::getInfo() const {

  Logger::log("Signature: " + std::string(header.signature, 2));
  Logger::log("File size: " + std::to_string(header.fileSize) + " bytes");
  Logger::log("Data offset: " + std::to_string(header.dataOffset) + " bytes");
  Logger::log("Header size: " + std::to_string(header.headerSize) + " bytes");
  Logger::log("Image dimensions: " + std::to_string(header.width) + "x" +
              std::to_string(header.height));
  Logger::log("Bits per pixel: " + std::to_string(header.bitsPerPixel));
  Logger::log("Compression: " + std::to_string(header.compression));
  Logger::log("Image size: " + std::to_string(header.imageSize) + " bytes");
  Logger::log("Pixels per meter (X axis): " +
              std::to_string(header.xPixelsPerMeter));
  Logger::log("Pixels per meter (Y axis): " +
              std::to_string(header.yPixelsPerMeter));
  Logger::log("Colors used: " + std::to_string(header.colorsUsed));
  Logger::log("Important colors: " + std::to_string(header.colorsImportant));
}
