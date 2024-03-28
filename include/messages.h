#pragma once

#ifdef RU
//MAIN
constexpr char invalid_bmp_message[] = "Неверный файл bmp!";
constexpr char same_input_output_message[] = "Входной файл совпадает с выходным файлом!";
constexpr char success_message[] = "Успех!";
constexpr char mirror_warning[] = "=Запрошена операция зеркального отражения!=";
constexpr char color_replace_warning[] = "=Запрошена операция замены цвета!=";
constexpr char image_split_warning[] = "=Запрошена операция разделения изображения=.";
constexpr char image_copy_warning[] = "=Запрошена операция копирования изображения=.";
//OPERSTIONS
constexpr char invalid_color_formate_error[] = "Неверный формат цвета";
constexpr char invalid_color_range_error[] = "Цвет вне диапазона [0-255]: ";
constexpr char invalid_coordinate_formate_error[] = "Неверный формат координаты";
constexpr char invalid_argument_error[] = "Неверный аргумент для ";
constexpr char unexpected_option_warning[] = "Неожиданный параметр: ";
//BMP
constexpr char open_bmp_error[] = "Ошибка открытия входного файла BMP: ";
constexpr char invalid_header_error[] = "Недопустимый заголовок файла BMP: ";
constexpr char invalid_signature_error[] = "Недопустимая сигнатура файла BMP";
constexpr char invalid_dimensions_error[] = "Недопустимые размеры BMP";
constexpr char invalid_bpp_warning[] = "Недопустимая глубина цвета BMP, изображение может быть некорректным";
constexpr char unsupported_compression_error[] = "Неподдерживаемый тип сжатия BMP";
constexpr char invalid_image_size_error[] = "Недопустимый размер изображения BMP";
constexpr char access_outside_bounds_warning[] = "Попытка доступа к цвету за пределами границ изображения";
constexpr char set_outside_bounds_warning[] = "Попытка установки цвета за пределами границ изображения";
constexpr char invalid_mirror_axis_error[] = "Указана недопустимая ось зеркального отражения";
constexpr char invalid_split_parameters_error[] = "Недопустимые параметры разделения";
constexpr char copy_exceeds_bounds_error[] = "Копируемая область выходит за границы изображения назначения";
constexpr char failed_create_output_file[] = "Ошибка создания конечного файла: ";
constexpr char invalid_copy_region[] = "Некорректная область копирования!";

// Help message descriptions
constexpr char help_usage_description[] = "Использование: название_программы [параметры] имя_файла";
constexpr char help_usage_start[] = "Параметры: ";
constexpr char mirror_option_description[] = "  --mirror               Операция зеркального отражения";
constexpr char axis_option_description[] = "  --axis <значение>      Ось операции";
constexpr char left_up_option_description[] = "  --left_up <x.y>        Координаты левого верхнего угла";
constexpr char right_down_option_description[] = "  --right_down <x.y>     Координаты правого нижнего угла";
constexpr char dest_left_up_option_description[] = "  --dest_left_up <x.y>   Координаты левого верхнего угла назначения";
constexpr char old_color_option_description[] = "  --old_color <r.g.b>    Старый цвет для замены";
constexpr char new_color_option_description[] = "  --new_color <r.g.b>    Новый цвет для замены";
constexpr char color_option_description[] = "  --color <r.g.b>        Цвет линии";
constexpr char copy_option_description[] = "  --copy                 Операция копирования";
constexpr char color_replace_option_description[] = "  --color_replace        Операция замены цвета";
constexpr char split_option_description[] = "  --split                Операция разделения";
constexpr char number_x_option_description[] = "  --number_x <значение>  Количество элементов вдоль оси x";
constexpr char number_y_option_description[] = "  --number_y <значение>  Количество элементов вдоль оси y";
constexpr char thickness_option_description[] = "  --thickness <значение> Толщина операции";
constexpr char output_option_description[] = "  -o, --output <файл>    Выходной файл";
constexpr char input_option_description[] = "  -i, --input <файл>     Входной файл";
constexpr char help_option_description[] = "  -h, --help             Показать эту информацию";

#else
//MAIN
constexpr char invalid_bmp_message[] = "Invalid bmp file!";
constexpr char same_input_output_message[] = "Input file is the same as output file!";
constexpr char success_message[] = "Success!";
constexpr char mirror_warning[] = "=Mirror operation requested!=";
constexpr char color_replace_warning[] = "=Color replace operation requested!=";
constexpr char image_split_warning[] = "=Image split operation requested=";
constexpr char image_copy_warning[] = "=Image copy operation requested=";
//OPERATIONS
constexpr char invalid_color_formate_error[] = "Invalid color format";
constexpr char invalid_color_range_error[] = "Color out of range [0-255] got: ";
constexpr char invalid_coordinate_formate_error[] = "Invalid coordinate format";
constexpr char invalid_argument_error[] = "Invalid argument for ";
constexpr char unexpected_option_warning[] = "Unexpected option: ";
//BMP
constexpr char open_bmp_error[] = "Failed to open input BMP file: ";
constexpr char invalid_header_error[] = "BMP file header is invalid: ";
constexpr char invalid_signature_error[] = "Invalid BMP file signature";
constexpr char invalid_dimensions_error[] = "Invalid BMP dimensions";
constexpr char invalid_bpp_warning[] = "Invalid BMP bits per pixel, image may be incorrect";
constexpr char unsupported_compression_error[] = "Unsupported BMP compression type";
constexpr char invalid_image_size_error[] = "Invalid BMP image size";
constexpr char access_outside_bounds_warning[] = "Trying to access color outside image bounds";
constexpr char set_outside_bounds_warning[] = "Trying to set color outside image bounds";
constexpr char invalid_mirror_axis_error[] = "Invalid mirror axis specified";
constexpr char invalid_split_parameters_error[] = "Invalid split parameters";
constexpr char copy_exceeds_bounds_error[] = "Copying region exceeds destination image boundaries.";
constexpr char failed_create_output_file[] = "Failed to create output BMP file: ";
constexpr char invalid_copy_region[] = "Invalid copy region or destination parameters";

// Help message descriptions
constexpr char help_usage_description[] = "Usage: program_name [options] filename";
constexpr char help_usage_start[] = "Options: ";
constexpr char mirror_option_description[] = "  --mirror               Mirror operation";
constexpr char axis_option_description[] = "  --axis <value>         Axis of operation";
constexpr char left_up_option_description[] = "  --left_up <x.y>        Coordinates of left-up corner";
constexpr char right_down_option_description[] = "  --right_down <x.y>     Coordinates of right-down corner";
constexpr char dest_left_up_option_description[] = "  --dest_left_up <x.y>   Coordinates of destination left-up corner";
constexpr char old_color_option_description[] = "  --old_color <r.g.b>    Old color to replace";
constexpr char new_color_option_description[] = "  --new_color <r.g.b>    New color to replace with";
constexpr char color_option_description[] = "  --color <r.g.b>        Color of line";
constexpr char copy_option_description[] = "  --copy                 Copy operation";
constexpr char color_replace_option_description[] = "  --color_replace        Color replace operation";
constexpr char split_option_description[] = "  --split                Split operation";
constexpr char number_x_option_description[] = "  --number_x <value>     Number of elements along x-axis";
constexpr char number_y_option_description[] = "  --number_y <value>     Number of elements along y-axis";
constexpr char thickness_option_description[] = "  --thickness <value>    Thickness of operation";
constexpr char output_option_description[] = "  -o, --output <file>    Output file";
constexpr char input_option_description[] = "  -i, --input <file>     Input file";
constexpr char help_option_description[] = "  -h, --help             Display this information";
#endif
