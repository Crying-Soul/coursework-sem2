/**
 * @file bmp.cpp
 * @brief Реализация методов класса BMP для работы с изображениями в формате BMP.
 */

#include "bmp.h"
#include "logger.h"
#include "messages.h"
#include <cstring>
#include <fstream>

BMP::BMP(const std::string &fileName) : header(), pixelData()
{
  std::ifstream file(fileName, std::ios::binary);
  if (!file.is_open())
  {
    Logger::exit(1, open_bmp_error + fileName);
  }

  file.read(reinterpret_cast<char *>(&header), sizeof(header));

  if (!validateHeader())
  {
    Logger::exit(1, invalid_header_error + fileName);
  }

  int rowSize = ((header.width * header.bitsPerPixel + 31) / 32) * 4;

  int imageSize = rowSize * header.height;

  pixelData.resize(imageSize - header.dataOffset);
  file.read(reinterpret_cast<char *>(pixelData.data()), pixelData.size());

  file.close();
}

bool BMP::validateHeader() const
{
  if (std::strncmp(header.signature, "BM", 2) != 0)
  {
    Logger::exit(1, invalid_signature_error);
    return false;
  }

  if (header.width <= 0 || header.height <= 0)
  {
    Logger::exit(1, invalid_dimensions_error);
    return false;
  }

  if (header.bitsPerPixel != 24)
  {
    Logger::warn(invalid_bpp_warning);
  }

  if (header.compression != 0)
  {
    Logger::exit(1, unsupported_compression_error);
    return false;
  }

  unsigned int expectedImageSize =
      header.width * header.height * (header.bitsPerPixel / 8);
  if (header.imageSize != expectedImageSize)
  {

    Logger::warn(invalid_image_size_error);
  }

  return true;
}

bool BMP::isValid() const { return !pixelData.empty(); }

RGB BMP::getColor(int x, int y) const
{
  if ((x < 0 || x >= header.width) || (y < 0 || y >= header.height))
  {
    Logger::warn(access_outside_bounds_warning);
    return RGB();
  }

  unsigned int index =
      ((header.height - 1 - y) * header.width + x) * (header.bitsPerPixel / 8);

  RGB color;
  color.blue = pixelData[index];
  color.green = pixelData[index + 1];
  color.red = pixelData[index + 2];
  return color;
}

void BMP::setColor(int x, int y, const RGB &newColor)
{
  if (x < 0 || x >= header.width || y < 0 || y >= header.height)
  {
    Logger::warn(set_outside_bounds_warning);
    return;
  }

  unsigned int index =
      ((header.height - 1 - y) * header.width + x) * (header.bitsPerPixel / 8);

  pixelData[index] = newColor.blue;
  pixelData[index + 1] = newColor.green;
  pixelData[index + 2] = newColor.red;
}

void BMP::colorReplace(const RGB &old_color, const RGB &new_color)
{
  for (int y = 0; y < header.height; y++)
  {
    for (int x = 0; x < header.width; x++)
    {
      RGB current_color = getColor(x, y);
      if (current_color.red == old_color.red &&
          current_color.green == old_color.green &&
          current_color.blue == old_color.blue)
      {
        setColor(x, y, new_color);
      }
    }
  }
}

void BMP::mirror(const std::string &axis, const Coordinate &left_up,
                 const Coordinate &right_down)
{
  int width = right_down.x - left_up.x;
  int height = right_down.y - left_up.y;

  if (axis != "x" && axis != "y")
  {
    Logger::exit(1, invalid_mirror_axis_error);
  }

  if (axis == "x")
  {
    for (int y = left_up.y; y < right_down.y; ++y)
    {
      for (int x = left_up.x; x < left_up.x + width / 2; ++x)
      {
        int mirroredX = right_down.x - (x - left_up.x) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(mirroredX, y));
        setColor(mirroredX, y, tempColor);
      }
    }
  }
  else if (axis == "y")
  {
    for (int y = left_up.y; y < left_up.y + height / 2; ++y)
    {
      for (int x = left_up.x; x < right_down.x; ++x)
      {
        int mirroredY = right_down.y - (y - left_up.y) - 1;

        RGB tempColor = getColor(x, y);
        setColor(x, y, getColor(x, mirroredY));
        setColor(x, mirroredY, tempColor);
      }
    }
  }
}

void BMP::split(int number_x, int number_y, int thickness, const RGB &color)
{
  if ((number_x <= 0 || number_x > header.width) ||
      (number_y <= 0 || number_y > header.height) ||
      (thickness <= 0 || thickness > header.width))
  {
    Logger::exit(1, invalid_split_parameters_error);
  }

  int gap;

  for (int i = 1; i < number_y; i++)
  {
    gap = header.height / number_y;
    for (int x = 0; x < header.width; x++)
    {
      for (int y = 0; y < thickness; y++)
      {
        setColor(x, i * gap + y, color);
      }
    }
  }

  for (int i = 1; i < number_x; i++)
  {
    gap = header.width / number_x;
    for (int x = 0; x < thickness; x++)
    {
      for (int y = 0; y < header.height; y++)
      {
        setColor(i * gap + x, y, color);
      }
    }
  }
}

void BMP::copy(const Coordinate &src_left_up, const Coordinate &src_right_down,
               const Coordinate &dest_left_up)
{
  if (src_left_up.x < 0 || src_left_up.y < 0 || dest_left_up.x <= 0 ||
      dest_left_up.x < 0)
  {
    Logger::exit(1, invalid_copy_region);
    return;
  }
  int src_width = src_right_down.x - src_left_up.x;
  int src_height = src_right_down.y - src_left_up.y;
  int dest_width = header.width - dest_left_up.x;
  int dest_height = header.height - dest_left_up.y;

  if (src_width <= 0 || src_height <= 0 || dest_width <= 0 ||
      dest_height <= 0)
  {
    Logger::exit(1, invalid_copy_region);
    return;
  }

  if (src_width > dest_width || src_height > dest_height)
  {
    Logger::warn(copy_exceeds_bounds_error);
  }
  else
  {
    int offsetX = 0;
    for (int x = src_left_up.x; x < src_right_down.x; x++)
    {
      int offsetY = 0;
      for (int y = src_left_up.y; y < src_right_down.y; y++)
      {
        setColor(dest_left_up.x + offsetX, dest_left_up.y + offsetY,
                 getColor(x, y));
        offsetY++;
      }
      offsetX++;
    }
  }
}

void BMP::save(const std::string &fileName)
{
  std::ofstream file(fileName, std::ios::binary);
  if (!file.is_open())
  {
    Logger::exit(1, failed_create_output_file + fileName);
    return;
  }

  int rowSize = ((header.width * header.bitsPerPixel + 31) / 32) * 4;

  int imageSize = rowSize * header.height;

  header.fileSize = header.dataOffset + imageSize;
  header.imageSize = imageSize;

  file.write(reinterpret_cast<const char *>(&header), sizeof(header));

  for (int y = 0; y < header.height; ++y)
  {
    file.write(reinterpret_cast<const char *>(pixelData.data() + y * rowSize),
               rowSize);
  }

  file.close();
}

void BMP::getInfo() const
{
  Logger::log(signature_message + std::string(header.signature, 2));
  Logger::log(file_size_message + std::to_string(header.fileSize) + " bytes");
  Logger::log(data_offset_message + std::to_string(header.dataOffset) + " bytes");
  Logger::log(header_size_message + std::to_string(header.headerSize) + " bytes");
  Logger::log(image_dimensions_message + std::to_string(header.width) + "x" +
              std::to_string(header.height));
  Logger::log(bits_per_pixel_message + std::to_string(header.bitsPerPixel));
  Logger::log(compression_message + std::to_string(header.compression));
  Logger::log(image_size_message + std::to_string(header.imageSize) + " bytes");
  Logger::log(pixels_per_meter_x_message +
              std::to_string(header.xPixelsPerMeter));
  Logger::log(pixels_per_meter_y_message +
              std::to_string(header.yPixelsPerMeter));
  Logger::log(colors_used_message + std::to_string(header.colorsUsed));
  Logger::log(important_colors_message + std::to_string(header.colorsImportant));
}
