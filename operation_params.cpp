#include "operation_params.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

// Функция для парсинга строки в массив координат или цветов
std::vector<int> parseValues(const std::string &str) {
  std::vector<int> values;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, '.')) {
    values.emplace_back(std::stoi(token));
  }
  return values;
}

OperationParams parseCommandLine(int argc, char *argv[]) {
  OperationParams params;

  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];

    if (arg == "--help" || arg == "-h") {
      std::cout << "Usage: program_name [options] filename\n"
                << "Options:\n"
                << "  --mirror               Mirror operation\n"
                << "  --axis <value>         Axis of operation\n"
                << "  --left_up <x.y>        Coordinates of left-up corner\n"
                << "  --right_down <x.y>     Coordinates of right-down corner\n"
                << "  --dest_left_up <x.y>   Coordinates of destination "
                   "left-up corner\n"
                << "  --old_color <r.g.b>    Old color to replace\n"
                << "  --new_color <r.g.b>    New color to replace with\n"
                << "  --color <r.g.b>        Color of line\n"
                << "  --copy                 Copy operation\n"
                << "  --color_replace        Color replace operation\n"
                << "  --split                Split operation\n"
                << "  --number_x <value>     Number of elements along x-axis\n"
                << "  --number_y <value>     Number of elements along y-axis\n"
                << "  --thickness <value>    Thickness of operation\n"
                << "  -o, --output <file>    Output file\n"
                << "  -h, --help             Display this information\n";
      return params;
    } else if (arg == "-info") {
      params.info = true;
    } else if (arg == "--output" || arg == "-o") {
      if (i + 1 < argc) {
        params.output_file = argv[++i];
      }
    } else if (arg == "--mirror") {
      params.mirror = true;
    } else if (arg == "--axis") {
      if (i + 1 < argc) {
        params.axis = argv[++i];
      }
    } else if (arg == "--left_up" || arg == "--right_down" ||
               arg == "--dest_left_up" || arg == "--old_color" ||
               arg == "--new_color" || arg == "--color") {
      if (i + 1 < argc) {
        try {
          std::string value = argv[++i];
          std::vector<int> parsed_values = parseValues(value);
          if (arg == "--left_up")
            params.left_up = parsed_values;
          else if (arg == "--right_down")
            params.right_down = parsed_values;
          else if (arg == "--dest_left_up")
            params.dest_left_up = parsed_values;
          else if (arg == "--old_color")
            params.old_color = parsed_values;
          else if (arg == "--new_color")
            params.new_color = parsed_values;
          else if (arg == "--color")
            params.line_color = parsed_values;
        } catch (const std::invalid_argument& e) {
          std::cerr << "Error: Invalid argument for " << arg << std::endl;
        }
      }
    } else if (arg == "--copy") {
      params.copy = true;
    } else if (arg == "--color_replace") {
      params.color_replace = true;
    } else if (arg == "--split") {
      params.split = true;
    } else if (arg == "--number_x" || arg == "--number_y" ||
               arg == "--thickness") {
      if (i + 1 < argc) {
        try {
          std::string value = argv[++i];
          if (arg == "--number_x")
            params.number_x = std::stoi(value);
          else if (arg == "--number_y")
            params.number_y = std::stoi(value);
          else if (arg == "--thickness")
            params.thickness = std::stoi(value);
        } catch (const std::invalid_argument& e) {
          std::cerr << "Error: Invalid argument for " << arg << std::endl;
        }
      }
    } else {
      
      params.input_file = arg;
    }
  }

  return params;
}
