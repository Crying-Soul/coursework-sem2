# BMP Image Processor

This is a command-line tool for processing BMP image files according to the specified functionalities. It allows for operations such as reflection, copying of regions, color replacement, and splitting images into multiple parts.

## Prerequisites

- C++ compiler
- Make

## Installation

1. Clone the repository:
`
   git clone https://github.com/Crying-Soul/coursework-sem2.git ./cw
`
2. Navigate to the project directory:
`
   cd cw
`
3. Build the project using Make:
`
   ./run.sh
`
## Usage
```css
./coursework [--mirror --axis <x/y> --left_up <x.y> --right_down <x.y>] \
                [--copy --left_up <x.y> --right_down <x.y> --dest_left_up <x.y>] \
                [--color_replace --old_color <rrr.ggg.bbb> --new_color <rrr.ggg.bbb>] \
                [--split --number_x <N> --number_y <M> --thickness <T> --color <rrr.ggg.bbb>] \
                -i <input_file.bmp> -o <output_file.bmp>
```
- `--mirror`: Reflects a specified region of the image.
- `--axis`: Specifies the axis (x or y) for reflection.
- `--left_up`: Coordinates of the top-left corner of the region.
- `--right_down`: Coordinates of the bottom-right corner of the region.
- `--copy`: Copies a specified region of the image to another location.
- `--dest_left_up`: Coordinates of the top-left corner of the destination region.
- `--color_replace`: Replaces all pixels of a specified color with another color.
- `--old_color`: Color to replace (in the format rrr.ggg.bbb).
- `--new_color`: Color to replace with (in the format rrr.ggg.bbb).
- `--split`: Divides the image into N*M parts with specified line thickness and color.
- `--number_x`: Number of parts along the Y-axis.
- `--number_y`: Number of parts along the X-axis.
- `--thickness`: Thickness of the dividing lines.
- `--color`: Color of the dividing lines (in the format rrr.ggg.bbb).

## Example
```css
./coursework --mirror --axis x --left_up 100.100 --right_down 200.200 \
                --copy --left_up 50.50 --right_down 150.150 --dest_left_up 300.300 \
                --color_replace --old_color 255.0.0 --new_color 0.255.0 \
                --split --number_x 3 --number_y 3 --thickness 2 --color 0.0.255 \
                -i input.bmp -o output.bmp
```
