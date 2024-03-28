#include "operation_params.h"
#include "logger.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<int> parseValues(const std::string &str) {
  std::vector<int> values;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, '.')) {
    values.emplace_back(std::stoi(token));
  }
  return values;
}

RGB parseRGB(const std::string &str) {
  std::vector<int> values = parseValues(str);
  if (values.size() != 3) {
    Logger::exit(1, "Invalid color format");
  }
  for (int value : values) {
    if (value < 0 || value > 255) {
      Logger::exit(1, "Color out of range [0-255]");
    }
  }
  return {static_cast<uint8_t>(values[0]), static_cast<uint8_t>(values[1]),
          static_cast<uint8_t>(values[2])};
}
void displayHelp() {
  Logger::log("Usage: program_name [options] filename");
  Logger::log("Options:");
  Logger::log("  --mirror               Mirror operation");
  Logger::log("  --axis <value>         Axis of operation");
  Logger::log("  --left_up <x.y>        Coordinates of left-up corner");
  Logger::log("  --right_down <x.y>     Coordinates of right-down corner");
  Logger::log(
      "  --dest_left_up <x.y>   Coordinates of destination left-up corner");
  Logger::log("  --old_color <r.g.b>    Old color to replace");
  Logger::log("  --new_color <r.g.b>    New color to replace with");
  Logger::log("  --color <r.g.b>        Color of line");
  Logger::log("  --copy                 Copy operation");
  Logger::log("  --color_replace        Color replace operation");
  Logger::log("  --split                Split operation");
  Logger::log("  --number_x <value>     Number of elements along x-axis");
  Logger::log("  --number_y <value>     Number of elements along y-axis");
  Logger::log("  --thickness <value>    Thickness of operation");
  Logger::log("  -o, --output <file>    Output file");
  Logger::log("  -i, --input <file>     Input file");
  Logger::log("  -h, --help             Display this information");
}

OperationParams parseCommandLine(int argc, char *argv[]) {
  OperationParams params;

  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];

    if (arg == "--help" || arg == "-h") {
      displayHelp();
      Logger::exit(0, "");
    } else if (arg == "-colorful") {
      Logger::setColorsEnabled(true);

    } else if (arg == "-info") {
      params.info = true;
    } else if (arg == "--mirror") {
      params.mirror = true;
    } else if (arg == "--axis") {
      if (i + 1 < argc) {
        params.axis = argv[++i];
      }
    } else if (arg == "--left_up" || arg == "--right_down" ||
               arg == "--dest_left_up") {
      if (i + 1 < argc) {
        try {
          std::string value = argv[++i];
          Coordinate coord;
          std::vector<int> parsed_values = parseValues(value);
          if (parsed_values.size() != 2) {
            Logger::exit(1, "Invalid coordinate format");
          }
          coord.x = parsed_values[0];
          coord.y = parsed_values[1];
          if (arg == "--left_up")
            params.left_up = coord;
          else if (arg == "--right_down")
            params.right_down = coord;
          else if (arg == "--dest_left_up")
            params.dest_left_up = coord;
        } catch (const std::invalid_argument &e) {

          Logger::exit(1, "Invalid argument for " + arg);
        }
      }
    } else if (arg == "--old_color" || arg == "--new_color" ||
               arg == "--color") {
      if (i + 1 < argc) {
        try {
          std::string value = argv[++i];
          RGB color = parseRGB(value);
          if (arg == "--old_color")
            params.old_color = color;
          else if (arg == "--new_color")
            params.new_color = color;
          else if (arg == "--color")
            params.line_color = color;
        } catch (const std::invalid_argument &e) {
          Logger::exit(1, "Invalid argument for " + arg);
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
          int intValue = std::stoi(value);
          if (arg == "--number_x")
            params.number_x = intValue;
          else if (arg == "--number_y")
            params.number_y = intValue;
          else if (arg == "--thickness")
            params.thickness = intValue;
        } catch (const std::invalid_argument &e) {
          Logger::exit(1, "Invalid argument for " + arg);
        }
      }
    } else if (arg == "--output" || arg == "-o") {
      if (i + 1 < argc) {
        params.output_file = argv[++i];
      }
    } else if (arg == "--input" || arg == "-i") {
      if (i + 1 < argc) {

        params.input_file = argv[++i];
      }
    } else {
      Logger::warn("Unexpected option " + arg);
    }
  }

  return params;
}
