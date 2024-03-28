#ifndef OPERATION_PARAMS_H
#define OPERATION_PARAMS_H

#include "structures.h"
#include <string>
#include <vector>

OperationParams parseCommandLine(int argc, char *argv[]);
std::vector<int> parseValues(const std::string &str);
RGB parseRGB(const std::string &str);
void displayHelp();

#endif
