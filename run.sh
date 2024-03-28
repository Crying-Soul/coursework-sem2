#!/bin/bash

FILE="-i 24.bmp"
MIRROR=" --mirror --axis x --left_up 10.10 --right_down 500.500"
COLOR_REPLACE=" --color_replace --old_color 255.255.255 --new_color 255.12.200 -fake_flag"
SPLIT="-info --split --number_x 20 --number_y 20 --thickness 2 --color 255.100.0"
COPY=" -h --copy --left_up 10.10 --right_down 200.200 --dest_left_up 300.300"

make
echo "==========START========="
./coursework -colorful $COPY $FILE
echo "==========END==========="
make clean
