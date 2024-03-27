#ifndef OPERATION_PARAMS_H
#define OPERATION_PARAMS_H

#include "structures.h"
#include <string>
#include <vector>

OperationParams parseCommandLine(int argc, char *argv[]);

RGB parseRGB(const std::string &str);

#endif
