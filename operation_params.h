#ifndef OPERATION_PARAMS_H
#define OPERATION_PARAMS_H

#include <string>
#include <vector> 

struct OperationParams {
    bool mirror = false;
    std::string axis;
    std::vector<int> left_up; 
    std::vector<int> right_down; 
    bool copy = false;
    std::vector<int> dest_left_up; 
    bool color_replace = false;
    std::vector<int> old_color; 
    std::vector<int> new_color; 
    bool split = false;
    int number_x = 1;
    int number_y = 1;
    int thickness = 1;
    std::vector<int> line_color; 

    OperationParams() : mirror(false), axis(), left_up(), right_down(), copy(false), dest_left_up(), color_replace(false), old_color(), new_color(), split(false), number_x(1), number_y(1), thickness(1), line_color() {}
};

OperationParams parseCommandLine(int argc, char* argv[]);

#endif 
