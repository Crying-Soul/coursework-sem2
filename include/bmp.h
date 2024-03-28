#ifndef BMP_H
#define BMP_H

#include "operation_params.h"
#include "structures.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class BMP {
private:
  BMPHeader header;
  bool validateHeader() const;
  std::vector<char> pixelData;

public:
  BMP(const std::string &fileName);

  void getInfo() const;

  void mirror(const std::string &axis, const Coordinate &left_up,
              const Coordinate &right_down);

  void save(const std::string &fileName);

  

  bool isValid() const;
 
  void copy(const Coordinate &src_left_up, const Coordinate &src_right_down,
            const Coordinate &dest_left_up);

  void colorReplace(const RGB &old_color, const RGB &new_color);

  void split(int number_x, int number_y, int thickness, const RGB &color);

private:
  RGB getColor(int x, int y) const;

  void setColor(int x, int y, const RGB &newColor);
};

#endif
