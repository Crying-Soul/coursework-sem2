#pragma once

#include <cstdint>
#include <string>

#pragma pack(push, 1)
struct BMPHeader {
  char signature[2];
  uint32_t fileSize;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t dataOffset;
  uint32_t headerSize;
  int32_t width;
  int32_t height;
  uint16_t planes;
  uint16_t bitsPerPixel;
  uint32_t compression;
  uint32_t imageSize;
  int32_t xPixelsPerMeter;
  int32_t yPixelsPerMeter;
  uint32_t colorsUsed;
  uint32_t colorsImportant;
};
#pragma pack(pop)

struct RGB {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

struct Coordinate {
  int x;
  int y;
};

struct OperationParams {
  std::string input_file;
  std::string output_file = "out.bmp";
  bool info = false;
  bool colorful = false;
  bool mirror = false;
  std::string axis;
  Coordinate left_up;
  Coordinate right_down;
  bool copy = false;
  Coordinate dest_left_up;
  bool color_replace = false;
  RGB old_color;
  RGB new_color;
  bool split = false;
  int number_x = 1;
  int number_y = 1;
  int thickness = 1;
  RGB line_color;

  OperationParams()
      : input_file(), output_file("out.bmp"), info(false), colorful(false),
        mirror(false), axis(), left_up(), right_down(), copy(false),
        dest_left_up(), color_replace(false), old_color(), new_color(),
        split(false), number_x(1), number_y(1), thickness(1), line_color() {}
};
