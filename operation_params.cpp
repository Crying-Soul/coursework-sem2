#include "operation_params.h"
#include <vector>
#include <sstream>

// Функция для парсинга строки в массив координат или цветов
std::vector<int> parseValues(const std::string& str) {
    std::vector<int> values;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, '.')) {
        values.push_back(std::stoi(token));
    }
    return values;
}

OperationParams parseCommandLine(int argc, char* argv[]) {
    OperationParams params;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--mirror") {
            params.mirror = true;
        } else if (arg == "--axis") {
            if (i + 1 < argc) {
                std::string value = argv[++i];
                params.axis = value;
            }
        } else if (arg == "--left_up" || arg == "--right_down" || arg == "--dest_left_up" ||
                   arg == "--old_color" || arg == "--new_color" || arg == "--color") {
            if (i + 1 < argc) {
                std::string value = argv[++i];
                std::vector<int> parsed_values = parseValues(value);
                if (arg == "--left_up") params.left_up = parsed_values;
                else if (arg == "--right_down") params.right_down = parsed_values;
                else if (arg == "--dest_left_up") params.dest_left_up = parsed_values;
                else if (arg == "--old_color") params.old_color = parsed_values;
                else if (arg == "--new_color") params.new_color = parsed_values;
                else if (arg == "--color") params.line_color = parsed_values;
            }
        } else if (arg == "--copy") {
            params.copy = true;
        } else if (arg == "--color_replace") {
            params.color_replace = true;
        } else if (arg == "--split") {
            params.split = true;
        } else if (arg == "--number_x" || arg == "--number_y" || arg == "--thickness") {
            if (i + 1 < argc) {
                std::string value = argv[++i];
                if (arg == "--number_x") params.number_x = std::stoi(value);
                else if (arg == "--number_y") params.number_y = std::stoi(value);
                else if (arg == "--thickness") params.thickness = std::stoi(value);
            }
        }
    }

    return params;
}
