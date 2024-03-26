#!/bin/bash

MIRROR="--mirror --axis y --left_up 10.10 --right_down 100.100"

make

./coursework $MIRROR

make clean
