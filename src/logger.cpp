/**
 * @file logger.cpp
 * @brief Файл реализации класса Logger.
 */

#include "logger.h"
#include "messages.h"
#include <iostream>

/**
 * @brief Инициализация статического члена colorsEnabled значением false.
 */
bool Logger::colorsEnabled = false;

/**
 * @brief Установить использование цветов для логирования.
 */
void Logger::setColorsEnabled(bool enableColors)
{
  colorsEnabled = enableColors;
}

/**
 * @brief Залогировать сообщение в консоль.

 */
void Logger::log(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << GREEN << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}

/**
 * @brief Залогировать предупреждение в консоль.

 */
void Logger::warn(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << YELLOW << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}

/**
 * @brief Залогировать сообщение об ошибке в консоль.
 */
void Logger::error(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << RED << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}

/**
 * @brief Залогировать сообщение об ошибке и завершить программу с указанным кодом завершения.
 */
void Logger::exit(const int exitCode, const std::string &exitMessage)
{
  if (!exitMessage.empty())
  {
    Logger::error(exitMessage);
  }
  std::exit(exitCode);
}
