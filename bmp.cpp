#include "bmp.h"

BMP::BMP(const std::string &fileName) : header(), pixelData() {
  std::ifstream file(fileName, std::ios::binary);
  if (!file) {
    std::cerr << "Failed to open input BMP file." << std::endl;
    return;
  }

  file.read(reinterpret_cast<char *>(&header), sizeof(header));

  pixelData.resize(header.fileSize - header.dataOffset);
  file.read(pixelData.data(), pixelData.size());

  file.close();
}

void BMP::mirror(const std::string &axis, const std::vector<int> &left_up,
                 const std::vector<int> &right_down) {
  int width = right_down[0] - left_up[0];
  int height = right_down[1] - left_up[1];
  if (axis == "x") {
    for (int y = left_up[1]; y < right_down[1]; ++y) {
      for (int x = left_up[0]; x < left_up[0] + width / 2; ++x) {
        int mirroredX = right_down[0] - (x - left_up[0]) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(mirroredX, y));
        setColor(mirroredX, y, tempColor);
      }
    }
  } else if (axis == "y") {
    for (int y = left_up[1]; y < left_up[1] + height / 2; ++y) {
      for (int x = left_up[0]; x < right_down[0]; ++x) {

        int mirroredY = right_down[1] - (y - left_up[1]) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(x, mirroredY));
        setColor(x, mirroredY, tempColor);
      }
    }
  }
}

void BMP::save(const std::string &fileName) {
  std::ofstream file(fileName, std::ios::binary);
  if (!file) {
    std::cerr << "Failed to create output BMP file." << std::endl;
    return;
  }

  file.write(reinterpret_cast<char *>(&header), sizeof(header));
  file.write(pixelData.data(), pixelData.size());

  file.close();
}

bool BMP::isValid() const { return !pixelData.empty(); }

RGB BMP::getColor(int x, int y) const {
  int index = (y * header.width + x) * (header.bitsPerPixel / 8);
  RGB color;
  color.blue = pixelData[index];
  color.green = pixelData[index + 1];
  color.red = pixelData[index + 2];
  return color;
}

void BMP::setColor(int x, int y, const RGB &newColor) {
  unsigned int index = (y * header.width + x) * (header.bitsPerPixel / 8);

  pixelData[index] = newColor.blue;
  pixelData[index + 1] = newColor.green;
  pixelData[index + 2] = newColor.red;
}
