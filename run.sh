#!/bin/bash

FILE=" 24_2.bmp"
MIRROR=" --mirror --axis x --left_up 10.10 --right_down 500.500"
COLOR_REPLACE=" --color_replace --old_color 255.255.255 --new_color 0.0.0"
SPLIT=" --split --number_x 10 --number_y 10 --thickness 10 --color 255.0.0"

make
echo "==========START========="
./coursework $SPLIT -colorful $FILE
echo "==========END==========="
make clean
