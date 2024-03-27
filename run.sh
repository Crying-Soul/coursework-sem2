#!/bin/bash

MIRROR="--mirror --axis x --left_up 10.10 --right_down 500.500 24_2.bmp"

make
echo "==========START========="
./coursework $MIRROR
echo "==========END==========="
make clean
