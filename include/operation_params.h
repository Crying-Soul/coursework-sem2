#ifndef OPERATION_PARAMS_H
#define OPERATION_PARAMS_H

#include "structures.h" // Включаем определение структур
#include <string>
#include <vector>

/**
 * @brief Парсинг командной строки и создание объекта OperationParams.
 * 
 * @param argc Количество аргументов командной строки.
 * @param argv Массив строк, содержащих аргументы командной строки.
 * @return OperationParams объект, содержащий параметры операции.
 */
OperationParams parseCommandLine(int argc, char *argv[]);

/**
 * @brief Парсинг строки с числами, разделенными пробелами.
 * 
 * @param str Строка, содержащая числа, разделенные пробелами.
 * @return Вектор целых чисел, полученных из строки.
 */
std::vector<int> parseValues(const std::string &str);

/**
 * @brief Парсинг строки с RGB-значением цвета.
 * 
 * @param str Строка, содержащая RGB-значение цвета в формате "R,G,B".
 * @return Структура RGB, представляющая цвет.
 */
RGB parseRGB(const std::string &str);

/**
 * @brief Отображение справки о возможных параметрах командной строки.
 */
void displayHelp();

#endif // OPERATION_PARAMS_H
