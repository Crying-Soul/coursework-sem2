# Курсовая работа

Это инструмент командной строки для обработки файлов изображений BMP в соответствии с указанными функциональными возможностями. Он позволяет выполнять операции, такие как отражение, копирование областей, замена цвета и разделение изображений на несколько частей.

## Содержание
- [Предварительные требования](#предварительные-требования)
- [Установка](#установка)
- [Использование](#использование)
- [Пример](#пример)
- [Авторы](#авторы)

<a name="предварительные-требования"></a> 

## Предварительные требования

- Компилятор C++
- Make

<a name="установка"></a> 

## Установка

1. Клонируйте репозиторий:`git clone https://github.com/Crying-Soul/coursework-sem2.git ./cw`
2. Перейдите в каталог проекта:`cd cw`
3. Соберите проект с помощью make:`make`
<a name="использование"></a> 

## Использование
```css
./coursework [--mirror --axis <x/y> --left_up <x.y> --right_down <x.y>] \
                [--copy --left_up <x.y> --right_down <x.y> --dest_left_up <x.y>] \
                [--color_replace --old_color <rrr.ggg.bbb> --new_color <rrr.ggg.bbb>] \
                [--split --number_x <N> --number_y <M> --thickness <T> --color <rrr.ggg.bbb>] \
                -i <input_file.bmp> -o <output_file.bmp>
```

- `--mirror`: Отражает указанную область изображения.
- `--axis`: Указывает ось (x или y) для отражения.
- `--left_up`: Координаты верхнего левого угла области.
- `--right_down`: Координаты нижнего правого угла области.
- `--copy`: Копирует указанную область изображения в другое место.
- `--dest_left_up`: Координаты верхнего левого угла целевой области.
- `--color_replace`: Заменяет все пиксели указанного цвета другим цветом.
- `--old_color`: Цвет для замены (в формате rrr.ggg.bbb).
- `--new_color`: Цвет для замены (в формате rrr.ggg.bbb).
- `--split`: Делит изображение на N*M частей с указанной толщиной линии и цветом.
- `--number_x`: Количество частей вдоль оси Y.
- `--number_y`: Количество частей вдоль оси X.
- `--thickness`: Толщина разделительных линий.
- `--color`: Цвет разделительных линий (в формате rrr.ggg.bbb).

<a name="example"></a>

## Пример
```css
./coursework --mirror --axis x --left_up 100.100 --right_down 200.200 \
                --copy --left_up 50.50 --right_down 150.150 --dest_left_up 300.300 \
                --color_replace --old_color 255.0.0 --new_color 0.255.0 \
                --split --number_x 3 --number_y 3 --thickness 2 --color 0.0.255 \
                -i input.bmp -o output.bmp
```
<a name="credits"></a> 

## Дополнительно

### Разработчики

- **Grebnev Egor** - Project Lead, Frontend Developer
- **ChatGPT** - Backend Developer

### Инструменты и библиотеки

Наш проект использует следующие инструменты и библиотеки:

- **[Doxygen](https://doxygen.nl)** - Инструмент для генерации документации из комментариев в исходном коде.
- **[DoxygenAwesome](https://github.com/jothepro/doxygen-awesome-css)** - Пользовательская тема CSS для документации Doxygen.
