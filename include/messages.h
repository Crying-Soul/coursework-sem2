/**
 * @file messages.h
 * @brief Заголовочный файл, содержащий определения структур и классов.
 */

#pragma once

#ifdef RU
// MAIN

#define ERR_FILE_NOT_FOUND 40
#define ERR_INCORRECT_FILE_FORMAT 41
#define ERR_FILE_WRITE_ERROR 42
#define ERR_INVALID_ARGUMENT 43
#define ERR_INSUFFICIENT_ARGUMENTS 45


/**
 * @brief Сообщение о неверном файле BMP.
 */
const std::string invalid_bmp_message = "Неверный файл bmp!";

/**
 * @brief Сообщение о том, что входной файл совпадает с выходным файлом.
 */
const std::string same_input_output_message = "Входной файл совпадает с выходным файлом!";

/**
 * @brief Сообщение об успешном выполнении операции.
 */
const std::string success_message = "Успех!";

/**
 * @brief Предупреждение о запрошенной операции зеркального отражения.
 */
const std::string mirror_warning = "=Запрошена операция зеркального отражения!=";

/**
 * @brief Предупреждение о запрошенной операции замены цвета.
 */
const std::string color_replace_warning = "=Запрошена операция замены цвета!=";

/**
 * @brief Предупреждение о запрошенной операции разделения изображения.
 */
const std::string image_split_warning = "=Запрошена операция разделения изображения=.";

/**
 * @brief Предупреждение о запрошенной операции копирования изображения.
 */
const std::string image_copy_warning = "=Запрошена операция копирования изображения=.";

// OPERSTIONS

/**
 * @brief Ошибка при неверном формате цвета.
 */
const std::string invalid_color_format_error = "Неверный формат цвета";

/**
 * @brief Ошибка при выходе цвета за допустимый диапазон [0-255].
 */
const std::string invalid_color_range_error = "Цвет вне диапазона [0-255]: ";

/**
 * @brief Ошибка при неверном формате координаты.
 */
const std::string invalid_coordinate_format_error = "Неверный формат координаты";

/**
 * @brief Ошибка при неверном аргументе для определенной операции.
 */
const std::string invalid_argument_error = "Неверный аргумент для ";

/**
 * @brief Предупреждение о неожиданном параметре.
 */
const std::string unexpected_option_warning = "Неожиданный параметр: ";

// BMP

/**
 * @brief Ошибка при открытии входного файла BMP.
 */
const std::string open_bmp_error = "Ошибка открытия входного файла BMP: ";

/**
 * @brief Ошибка при недопустимом заголовке файла BMP.
 */
const std::string invalid_header_error = "Недопустимый заголовок файла BMP: ";

/**
 * @brief Ошибка при недопустимой сигнатуре файла BMP.
 */
const std::string invalid_signature_error = "Недопустимая сигнатура файла BMP";

/**
 * @brief Ошибка при недопустимых размерах BMP.
 */
const std::string invalid_dimensions_error = "Недопустимые размеры BMP";

/**
 * @brief Предупреждение о недопустимой глубине цвета BMP.
 */
const std::string invalid_bpp_warning = "Недопустимая глубина цвета BMP, итоговое изображение может быть некорректным";

/**
 * @brief Ошибка при неподдерживаемом типе сжатия BMP.
 */
const std::string unsupported_compression_error = "Неподдерживаемый тип сжатия BMP";

/**
 * @brief Ошибка при недопустимом размере изображения BMP.
 */
const std::string invalid_image_size_error = "Недопустимый размер изображения BMP, итоговое изображение может быть некорректным";

/**
 * @brief Предупреждение о попытке доступа к цвету за пределами границ изображения.
 */
const std::string access_outside_bounds_warning = "Попытка доступа к цвету за пределами границ изображения";

/**
 * @brief Предупреждение о попытке установки цвета за пределами границ изображения.
 */
const std::string set_outside_bounds_warning = "Попытка установки цвета за пределами границ изображения";

/**
 * @brief Ошибка при указании недопустимой оси зеркального отражения.
 */
const std::string invalid_mirror_axis_error = "Указана недопустимая ось зеркального отражения";

/**
 * @brief Ошибка при недопустимых параметрах разделения.
 */
const std::string invalid_split_parameters_error = "Недопустимые параметры разделения";

/**
 * @brief Ошибка при выходе за границы изображения назначения при копировании.
 */
const std::string copy_exceeds_bounds_error = "Копируемая область выходит за границы изображения назначения";

/**
 * @brief Ошибка при создании конечного файла.
 */
const std::string failed_create_output_file = "Ошибка создания конечного файла: ";

/**
 * @brief Ошибка при некорректной области копирования.
 */
const std::string invalid_copy_region = "Некорректная область копирования!";

// Help message descriptions

/**
 * @brief Описание использования программы.
 */
const std::string help_usage_description = "Использование: название_программы [параметры] имя_файла";

/**
 * @brief Начало описания параметров.
 */
const std::string help_usage_start = "Параметры: ";

/**
 * @brief Описание параметра --mirror.
 */
const std::string mirror_option_description = "  --mirror               Операция зеркального отражения";

/**
 * @brief Описание параметра --axis.
 */
const std::string axis_option_description = "  --axis <значение>      Ось операции";

/**
 * @brief Описание параметра --left_up.
 */
const std::string left_up_option_description = "  --left_up <x.y>        Координаты левого верхнего угла";

/**
 * @brief Описание параметра --right_down.
 */
const std::string right_down_option_description = "  --right_down <x.y>     Координаты правого нижнего угла";

/**
 * @brief Описание параметра --dest_left_up.
 */
const std::string dest_left_up_option_description = "  --dest_left_up <x.y>   Координаты левого верхнего угла назначения";

/**
 * @brief Описание параметра --old_color.
 */
const std::string old_color_option_description = "  --old_color <r.g.b>    Старый цвет для замены";

/**
 * @brief Описание параметра --new_color.
 */
const std::string new_color_option_description = "  --new_color <r.g.b>    Новый цвет для замены";

/**
 * @brief Описание параметра --color.
 */
const std::string color_option_description = "  --color <r.g.b>        Цвет линии";

/**
 * @brief Описание параметра --copy.
 */
const std::string copy_option_description = "  --copy                 Операция копирования";

/**
 * @brief Описание параметра --color_replace.
 */
const std::string color_replace_option_description = "  --color_replace        Операция замены цвета";

/**
 * @brief Описание параметра --split.
 */
const std::string split_option_description = "  --split                Операция разделения";

/**
 * @brief Описание параметра --number_x.
 */
const std::string number_x_option_description = "  --number_x <значение>  Количество элементов вдоль оси x";

/**
 * @brief Описание параметра --number_y.
 */
const std::string number_y_option_description = "  --number_y <значение>  Количество элементов вдоль оси y";

/**
 * @brief Описание параметра --thickness.
 */
const std::string thickness_option_description = "  --thickness <значение> Толщина операции";

/**
 * @brief Описание параметра --output.
 */
const std::string output_option_description = "  -o, --output <файл>    Выходной файл";

/**
 * @brief Описание параметра --input.
 */
const std::string input_option_description = "  -i, --input <файл>     Входной файл";

/**
 * @brief Описание параметра --help.
 */
const std::string help_option_description = "  -h, --help             Показать эту информацию";

// Info message

/**
 * @brief Сообщение о сигнатуре файла.
 */
const std::string signature_message = "Сигнатура: ";

/**
 * @brief Сообщение о размере файла.
 */
const std::string file_size_message = "Размер файла: ";

/**
 * @brief Сообщение о смещении данных в файле.
 */
const std::string data_offset_message = "Смещение данных: ";

/**
 * @brief Сообщение о размере заголовка файла.
 */
const std::string header_size_message = "Размер заголовка: ";

/**
 * @brief Сообщение о размерах изображения.
 */
const std::string image_dimensions_message = "Размеры изображения: ";

/**
 * @brief Сообщение о количестве бит на пиксель.
 */
const std::string bits_per_pixel_message = "Бит на пиксель: ";

/**
 * @brief Сообщение о типе сжатия.
 */
const std::string compression_message = "Сжатие: ";

/**
 * @brief Сообщение о размере изображения.
 */
const std::string image_size_message = "Размер изображения: ";

/**
 * @brief Сообщение о количестве пикселей на метр по оси X.
 */
const std::string pixels_per_meter_x_message = "Пикселей на метр (ось X): ";

/**
 * @brief Сообщение о количестве пикселей на метр по оси Y.
 */
const std::string pixels_per_meter_y_message = "Пикселей на метр (ось Y): ";

/**
 * @brief Сообщение об используемых цветах.
 */
const std::string colors_used_message = "Используемые цвета: ";

/**
 * @brief Сообщение об важных цветах.
 */
const std::string important_colors_message = "Важные цвета: ";

/**
 * @brief Error message for the usage of two incompatible functions.
 */
const std::string double_function_use_err = "Несовместимые функции";

/**
 * @brief Error message for too many arguments provided.
 */
const std::string too_many_args_err = "Слишком много аргументов";

/**
 * @brief Error message for missing input file.
 */

#else
// MAIN

/**
 * @brief Message for invalid BMP file.
 */
const std::string invalid_bmp_message = "Invalid bmp file!";

/**
 * @brief Message when input file is same as output file.
 */
const std::string same_input_output_message = "Input file is the same as output file!";

/**
 * @brief Success message.
 */
const std::string success_message = "Success!";

/**
 * @brief Warning for requested mirror operation.
 */
const std::string mirror_warning = "=Mirror operation requested!=";

/**
 * @brief Warning for requested color replace operation.
 */
const std::string color_replace_warning = "=Color replace operation requested!=";

/**
 * @brief Warning for requested image split operation.
 */
const std::string image_split_warning = "=Image split operation requested=";

/**
 * @brief Warning for requested image copy operation.
 */
const std::string image_copy_warning = "=Image copy operation requested=";

// OPERATIONS

/**
 * @brief Error for invalid color format.
 */
const std::string invalid_color_format_error = "Invalid color format";

/**
 * @brief Error when color is out of range [0-255].
 */
const std::string invalid_color_range_error = "Color out of range [0-255] got: ";

/**
 * @brief Error for invalid coordinate format.
 */
const std::string invalid_coordinate_format_error = "Invalid coordinate format";

/**
 * @brief Error for invalid argument for certain operation.
 */
const std::string invalid_argument_error = "Invalid argument for ";

/**
 * @brief Warning for unexpected option.
 */
const std::string unexpected_option_warning = "Unexpected option: ";

// BMP

/**
 * @brief Error when failed to open input BMP file.
 */
const std::string open_bmp_error = "Failed to open input BMP file: ";

/**
 * @brief Error when BMP file header is invalid.
 */
const std::string invalid_header_error = "BMP file header is invalid: ";

/**
 * @brief Error for invalid BMP file signature.
 */
const std::string invalid_signature_error = "Invalid BMP file signature";

/**
 * @brief Error for invalid BMP dimensions.
 */
const std::string invalid_dimensions_error = "Invalid BMP dimensions";

/**
 * @brief Warning for invalid BMP bits per pixel.
 */
const std::string invalid_bpp_warning = "Invalid BMP bits per pixel, output image may be incorrect";

/**
 * @brief Error for unsupported BMP compression type.
 */
const std::string unsupported_compression_error = "Unsupported BMP compression type";

/**
 * @brief Error for invalid BMP image size.
 */
const std::string invalid_image_size_error = "Invalid BMP image size, output image may be incorrect";

/**
 * @brief Warning for trying to access color outside image bounds.
 */
const std::string access_outside_bounds_warning = "Trying to access color outside image bounds";

/**
 * @brief Warning for trying to set color outside image bounds.
 */
const std::string set_outside_bounds_warning = "Trying to set color outside image bounds";

/**
 * @brief Error for invalid mirror axis specified.
 */
const std::string invalid_mirror_axis_error = "Invalid mirror axis specified";

/**
 * @brief Error for invalid split parameters.
 */
const std::string invalid_split_parameters_error = "Invalid split parameters";

/**
 * @brief Error when copying region exceeds destination image boundaries.
 */
const std::string copy_exceeds_bounds_error = "Copying region exceeds destination image boundaries.";

/**
 * @brief Error when failed to create output BMP file.
 */
const std::string failed_create_output_file = "Failed to create output BMP file: ";

/**
 * @brief Error for invalid copy region or destination parameters.
 */
const std::string invalid_copy_region = "Invalid copy region or destination parameters";

// Help message descriptions

/**
 * @brief Usage description of the program.
 */
const std::string help_usage_description = "Usage: program_name [options] filename";

/**
 * @brief Start of the description of options.
 */
const std::string help_usage_start = "Options: ";

/**
 * @brief Description of --mirror option.
 */
const std::string mirror_option_description = "  --mirror               Mirror operation";

/**
 * @brief Description of --axis option.
 */
const std::string axis_option_description = "  --axis <value>         Axis of operation";

/**
 * @brief Description of --left_up option.
 */
const std::string left_up_option_description = "  --left_up <x.y>        Coordinates of left-up corner";

/**
 * @brief Description of --right_down option.
 */
const std::string right_down_option_description = "  --right_down <x.y>     Coordinates of right-down corner";

/**
 * @brief Description of --dest_left_up option.
 */
const std::string dest_left_up_option_description = "  --dest_left_up <x.y>   Coordinates of destination left-up corner";

/**
 * @brief Description of --old_color option.
 */
const std::string old_color_option_description = "  --old_color <r.g.b>    Old color to replace";

/**
 * @brief Description of --new_color option.
 */
const std::string new_color_option_description = "  --new_color <r.g.b>    New color to replace with";

/**
 * @brief Description of --color option.
 */
const std::string color_option_description = "  --color <r.g.b>        Color of line";

/**
 * @brief Description of --copy option.
 */
const std::string copy_option_description = "  --copy                 Copy operation";

/**
 * @brief Description of --color_replace option.
 */
const std::string color_replace_option_description = "  --color_replace        Color replace operation";

/**
 * @brief Description of --split option.
 */
const std::string split_option_description = "  --split                Split operation";

/**
 * @brief Description of --number_x option.
 */
const std::string number_x_option_description = "  --number_x <value>     Number of elements along x-axis";

/**
 * @brief Description of --number_y option.
 */
const std::string number_y_option_description = "  --number_y <value>     Number of elements along y-axis";

/**
 * @brief Description of --thickness option.
 */
const std::string thickness_option_description = "  --thickness <value>    Thickness of operation";

/**
 * @brief Description of --output option.
 */
const std::string output_option_description = "  -o, --output <file>    Output file";

/**
 * @brief Description of --input option.
 */
const std::string input_option_description = "  -i, --input <file>     Input file";

/**
 * @brief Description of --help option.
 */
const std::string help_option_description = "  -h, --help             Display this information";

// Info message

/**
 * @brief Signature of the file message.
 */
const std::string signature_message = "Signature: ";

/**
 * @brief File size message.
 */
const std::string file_size_message = "File size: ";

/**
 * @brief Data offset message.
 */
const std::string data_offset_message = "Data offset: ";

/**
 * @brief Header size message.
 */
const std::string header_size_message = "Header size: ";

/**
 * @brief Image dimensions message.
 */
const std::string image_dimensions_message = "Image dimensions: ";

/**
 * @brief Bits per pixel message.
 */
const std::string bits_per_pixel_message = "Bits per pixel: ";

/**
 * @brief Compression message.
 */
const std::string compression_message = "Compression: ";

/**
 * @brief Image size message.
 */
const std::string image_size_message = "Image size: ";

/**
 * @brief Pixels per meter message for X axis.
 */
const std::string pixels_per_meter_x_message = "Pixels per meter (X axis): ";

/**
 * @brief Pixels per meter message for Y axis.
 */
const std::string pixels_per_meter_y_message = "Pixels per meter (Y axis): ";

/**
 * @brief Colors used message.
 */
const std::string colors_used_message = "Colors used: ";

/**
 * @brief Important colors message.
 */
const std::string important_colors_message = "Important colors: ";

/**
 * @brief Error message for the usage of two incompatible functions.
 */
const std::string double_function_use_err = "Incompatible functions";

/**
 * @brief Error message for too many arguments provided.
 */
const std::string too_many_args_err_en = "Too many arguments";

#endif
