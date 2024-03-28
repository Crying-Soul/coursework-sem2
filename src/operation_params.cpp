/**
 * @file operation_params.cpp
 * @brief Определяет функции для анализа параметров операций из командной строки.
 */

#include "operation_params.h"
#include "logger.h"
#include "messages.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


std::vector<int> parseValues(const std::string &str)
{
  std::vector<int> values;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, '.'))
  {
    values.emplace_back(std::stoi(token));
  }
  return values;
}


RGB parseRGB(const std::string &str)
{
  std::vector<int> values = parseValues(str);
  if (values.size() != 3)
  {
    Logger::exit(1, invalid_color_format_error);
  }
  for (int value : values)
  {
    if (value < 0 || value > 255)
    {
      Logger::exit(1, invalid_color_range_error + std::to_string(value));
    }
  }
  return {static_cast<uint8_t>(values[0]), static_cast<uint8_t>(values[1]),
          static_cast<uint8_t>(values[2])};
}

void displayHelp()
{
  Logger::log(help_usage_description);
  Logger::log(help_usage_start);
  Logger::log(mirror_option_description);
  Logger::log(axis_option_description);
  Logger::log(left_up_option_description);
  Logger::log(right_down_option_description);
  Logger::log(dest_left_up_option_description);
  Logger::log(old_color_option_description);
  Logger::log(new_color_option_description);
  Logger::log(color_option_description);
  Logger::log(copy_option_description);
  Logger::log(color_replace_option_description);
  Logger::log(split_option_description);
  Logger::log(number_x_option_description);
  Logger::log(number_y_option_description);
  Logger::log(thickness_option_description);
  Logger::log(output_option_description);
  Logger::log(input_option_description);
  Logger::log(help_option_description);
}


OperationParams parseCommandLine(int argc, char *argv[])
{
  OperationParams params;

  for (int i = 1; i < argc; ++i)
  {
    const std::string arg = argv[i];

    if (arg == "--help" || arg == "-h")
    {
      displayHelp();
      Logger::exit(0, "");
    }
    else if (arg == "-colorful")
    {
      Logger::setColorsEnabled(true);
    }
    else if (arg == "-info")
    {
      params.info = true;
    }
    else if (arg == "--mirror")
    {
      params.mirror = true;
    }
    else if (arg == "--axis")
    {
      if (i + 1 < argc)
      {
        params.axis = argv[++i];
      }
    }
    else if (arg == "--left_up" || arg == "--right_down" ||
             arg == "--dest_left_up")
    {
      if (i + 1 < argc)
      {
        try
        {
          std::string value = argv[++i];
          Coordinate coord;
          std::vector<int> parsed_values = parseValues(value);
          if (parsed_values.size() != 2)
          {
            Logger::exit(1, invalid_coordinate_format_error);
          }
          coord.x = parsed_values[0];
          coord.y = parsed_values[1];
          if (arg == "--left_up")
            params.left_up = coord;
          else if (arg == "--right_down")
            params.right_down = coord;
          else if (arg == "--dest_left_up")
            params.dest_left_up = coord;
        }
        catch (const std::invalid_argument &e)
        {

          Logger::exit(1, invalid_argument_error + arg);
        }
      }
    }
    else if (arg == "--old_color" || arg == "--new_color" ||
             arg == "--color")
    {
      if (i + 1 < argc)
      {
        try
        {
          std::string value = argv[++i];
          RGB color = parseRGB(value);
          if (arg == "--old_color")
            params.old_color = color;
          else if (arg == "--new_color")
            params.new_color = color;
          else if (arg == "--color")
            params.line_color = color;
        }
        catch (const std::invalid_argument &e)
        {
          Logger::exit(1, invalid_argument_error + arg);
        }
      }
    }
    else if (arg == "--copy")
    {
      params.copy = true;
    }
    else if (arg == "--color_replace")
    {
      params.color_replace = true;
    }
    else if (arg == "--split")
    {
      params.split = true;
    }
    else if (arg == "--number_x" || arg == "--number_y" ||
             arg == "--thickness")
    {
      if (i + 1 < argc)
      {
        try
        {
          std::string value = argv[++i];
          int intValue = std::stoi(value);
          if (arg == "--number_x")
            params.number_x = intValue;
          else if (arg == "--number_y")
            params.number_y = intValue;
          else if (arg == "--thickness")
            params.thickness = intValue;
        }
        catch (const std::invalid_argument &e)
        {
          Logger::exit(1, invalid_argument_error + arg);
        }
      }
    }
    else if (arg == "--output" || arg == "-o")
    {
      if (i + 1 < argc)
      {
        params.output_file = argv[++i];
      }
    }
    else if (arg == "--input" || arg == "-i")
    {
      if (i + 1 < argc)
      {
        params.input_file = argv[++i];
      }
    }
    else
    {
      Logger::warn(unexpected_option_warning + arg);
    }
  }

  return params;
}
