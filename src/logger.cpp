/**
 * @file logger.cpp
 * @brief Implementation file for the Logger class.
 */

#include "logger.h"
#include "messages.h"
#include <iostream>

// Объявление функций setColor и resetColor перед их использованием
inline void setColor(const Color color);
inline void resetColor();

// Инициализация статической переменной colorsEnabled
bool Logger::colorsEnabled = true;

// Определение конструктора для класса Logger
Logger::Logger(bool enableColors) {
  colorsEnabled = enableColors; // Установка значения colorsEnabled при создании
                                // объекта Logger
}

// Установка флага colorsEnabled
void Logger::setColorsEnabled(bool enableColors) {
  colorsEnabled = enableColors;
}

// Функция записи сообщения в лог с определенным цветом
void Logger::log(const std::string &message, Color color) {
  if (colorsEnabled) {
    setColor(color);
  }
  std::cout << message << std::endl;
  if (colorsEnabled) {
    resetColor();
  }
}

// Функция записи предупреждения в лог (с желтым цветом)
void Logger::warn(const std::string &message) { log(message, Color::YELLOW); }

// Функция записи ошибки в лог (с красным цветом)
void Logger::error(const std::string &message) { log(message, Color::RED); }

// Функция записи сообщения и завершения программы с заданным кодом выхода
void Logger::exit(int exitCode, const std::string &exitMessage) {
  if (!exitMessage.empty()) {
    error(exitMessage);
  }
  std::exit(exitCode);
}

// Определение функции setColor
inline void setColor(const Color color) {
  switch (color) {
  case Color::RED:
    std::cout << "\033[31m"; // Red
    break;
  case Color::GREEN:
    std::cout << "\033[32m"; // Green
    break;
  case Color::YELLOW:
    std::cout << "\033[33m"; // Yellow
    break;
  case Color::BLUE:
    std::cout << "\033[34m"; // Blue
    break;
  case Color::MAGENTA:
    std::cout << "\033[35m"; // Magenta
    break;
  case Color::CYAN:
    std::cout << "\033[36m"; // Cyan
    break;
  case Color::WHITE:
    std::cout << "\033[37m"; // White
    break;
  default:
    break;
  }
}

// Определение функции resetColor
inline void resetColor() {
  std::cout << "\033[0m"; // Reset color
}
