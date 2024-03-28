/**
 * @file logger.h
 * @brief Заголовочный файл, содержащий определения структур и классов.
 */


#ifndef LOGGER_H
#define LOGGER_H

#include <string>

/**
 * @brief Класс для записи логов.
 */
class Logger {
private:
  static bool colorsEnabled; /**< Флаг, определяющий, разрешены ли цвета в выводе. */
  static constexpr const char *RESET = "\033[0m"; /**< Сброс цветов. */
  static constexpr const char *BLACK = "\033[30m"; /**< Черный цвет. */
  static constexpr const char *RED = "\033[31m"; /**< Красный цвет. */
  static constexpr const char *GREEN = "\033[32m"; /**< Зеленый цвет. */
  static constexpr const char *YELLOW = "\033[33m"; /**< Желтый цвет. */
  static constexpr const char *BLUE = "\033[34m"; /**< Синий цвет. */
  static constexpr const char *MAGENTA = "\033[35m"; /**< Пурпурный цвет. */
  static constexpr const char *CYAN = "\033[36m"; /**< Голубой цвет. */
  static constexpr const char *WHITE = "\033[37m"; /**< Белый цвет. */

public:
  /**
   * @brief Устанавливает разрешение использования цветов в выводе.
   * 
   * @param enableColors true, если цвета разрешены, false в противном случае.
   */
  static void setColorsEnabled(bool enableColors);

  /**
   * @brief Записывает сообщение в лог.
   * 
   * @param message Сообщение для записи в лог.
   */
  static void log(const std::string &message);

  /**
   * @brief Записывает предупреждение в лог.
   * 
   * @param message Сообщение предупреждения для записи в лог.
   */
  static void warn(const std::string &message);

  /**
   * @brief Записывает ошибку в лог.
   * 
   * @param message Сообщение ошибки для записи в лог.
   */
  static void error(const std::string &message);

  /**
   * @brief Записывает сообщение и завершает программу с заданным кодом выхода.
   * 
   * @param exitCode Код выхода.
   * @param exitMessage Сообщение о завершении программы.
   */
  static void exit(const int exitCode, const std::string &exitMessage);
};

#endif // LOGGER_H
