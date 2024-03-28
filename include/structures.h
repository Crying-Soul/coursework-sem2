/**
 * @file structures.h
 * @brief Заголовочный файл, содержащий определения структур и классов.
 */

#pragma once

#include <cstdint>
#include <string>

#pragma pack(push, 1)

/**
 * @brief Структура, представляющая заголовок BMP-файла.
 */
struct BMPHeader {
  char signature[2]; /**< Сигнатура файла BMP. */
  uint32_t fileSize; /**< Размер файла в байтах. */
  uint16_t reserved1; /**< Зарезервировано для использования. */
  uint16_t reserved2; /**< Зарезервировано для использования. */
  uint32_t dataOffset; /**< Смещение, с которого начинаются данные изображения. */
  uint32_t headerSize; /**< Размер заголовка в байтах. */
  int32_t width; /**< Ширина изображения в пикселях. */
  int32_t height; /**< Высота изображения в пикселях. */
  uint16_t planes; /**< Количество плоскостей. */
  uint16_t bitsPerPixel; /**< Глубина цвета пикселя в битах. */
  uint32_t compression; /**< Тип сжатия. */
  uint32_t imageSize; /**< Размер данных изображения. */
  int32_t xPixelsPerMeter; /**< Горизонтальное разрешение в пикселях на метр. */
  int32_t yPixelsPerMeter; /**< Вертикальное разрешение в пикселях на метр. */
  uint32_t colorsUsed; /**< Количество используемых цветов изображения. */
  uint32_t colorsImportant; /**< Количество важных цветов изображения. */
};

#pragma pack(pop)

/**
 * @brief Структура, представляющая цвет в формате RGB.
 */
struct RGB {
  uint8_t red; /**< Компонента красного цвета. */
  uint8_t green; /**< Компонента зеленого цвета. */
  uint8_t blue; /**< Компонента синего цвета. */
};

/**
 * @brief Структура, представляющая координаты точки на плоскости.
 */
struct Coordinate {
  int x; /**< Координата x. */
  int y; /**< Координата y. */
};

/**
 * @brief Структура, представляющая параметры операции над изображением.
 */
struct OperationParams {
  std::string input_file; /**< Путь к входному файлу. */
  std::string output_file = "out.bmp"; /**< Путь к выходному файлу (по умолчанию "out.bmp"). */
  bool info = false; /**< Флаг вывода информации о изображении. */
  bool mirror = false; /**< Флаг отражения изображения. */
  std::string axis; /**< Ось отражения (горизонтальная или вертикальная). */
  Coordinate left_up; /**< Левая верхняя точка для выделения области. */
  Coordinate right_down; /**< Правая нижняя точка для выделения области. */
  bool copy = false; /**< Флаг копирования выделенной области. */
  Coordinate dest_left_up; /**< Левая верхняя точка для вставки скопированной области. */
  bool color_replace = false; /**< Флаг замены цвета. */
  RGB old_color; /**< Старый цвет, который будет заменен. */
  RGB new_color; /**< Новый цвет, на который будет заменен старый цвет. */
  bool split = false; /**< Флаг разделения изображения на части. */
  int number_x = 1; /**< Количество частей по горизонтали. */
  int number_y = 1; /**< Количество частей по вертикали. */
  int thickness = 1; /**< Толщина линии при разделении изображения на части. */
  RGB line_color; /**< Цвет линии разделения. */

  /**
   * @brief Конструктор по умолчанию для инициализации параметров операции.
   */
  OperationParams()
      : input_file(), output_file("out.bmp"), info(false), mirror(false),
        axis(), left_up(), right_down(), copy(false), dest_left_up(),
        color_replace(false), old_color(), new_color(), split(false),
        number_x(1), number_y(1), thickness(1), line_color() {}
};

