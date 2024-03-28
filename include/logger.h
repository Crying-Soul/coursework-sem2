/**
 * @file logger.h
 * @brief Заголовочный файл, содержащий определения структур и классов.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// Enum для цветов
enum class Color {
    RED, /**< Красный цвет */
    GREEN, /**< Зеленый цвет */
    YELLOW, /**< Желтый цвет */
    BLUE, /**< Синий цвет */
    MAGENTA, /**< Пурпурный цвет */
    CYAN, /**< Голубой цвет */
    WHITE /**< Белый цвет */
};

class Logger {
private:
    static bool colorsEnabled; /**< Флаг, определяющий, разрешены ли цвета в выводе. */

public:
    /**
     * @brief Конструктор для класса Logger.
     * @param enableColors Если true, разрешает использование цветов в логах, иначе - нет.
     */
    Logger(bool enableColors = true);

    /**
     * @brief Устанавливает разрешение использования цветов в выводе.
     * @param enableColors Если true, разрешает использование цветов в логах, иначе - нет.
     */
    static void setColorsEnabled(bool enableColors);

    /**
     * @brief Записывает сообщение в лог с определенным цветом.
     * @param message Сообщение для записи в лог.
     * @param color Цвет сообщения (по умолчанию GREEN).
     */
    static void log(const std::string& message, Color color = Color::GREEN);

    /**
     * @brief Записывает предупреждение в лог с желтым цветом.
     * @param message Сообщение предупреждения для записи в лог.
     */
    static void warn(const std::string& message);

    /**
     * @brief Записывает ошибку в лог с красным цветом.
     * @param message Сообщение ошибки для записи в лог.
     */
    static void error(const std::string& message);

    /**
     * @brief Записывает сообщение и завершает программу с заданным кодом выхода.
     * @param exitCode Код выхода.
     * @param exitMessage Сообщение о завершении программы.
     */
    static void exit(int exitCode, const std::string& exitMessage = "");
};

#endif // LOGGER_H
