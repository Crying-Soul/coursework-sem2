#ifndef BMP_H
#define BMP_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

#pragma pack(push, 1)
struct RGB {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
};
#pragma pack(pop)

class BMP {
private:
  BMPHeader header;
  std::vector<char> pixelData;

public:
  BMP(const std::string &fileName);
  void mirror(const std::string& axis, const std::vector<int>& left_up, const std::vector<int>& right_down);

  void save(const std::string &fileName);

  bool isValid() const;

private:
  RGB getColor(int x, int y) const;

  void setColor(int x, int y, const RGB &newColor);

};

#endif // BMP_H
