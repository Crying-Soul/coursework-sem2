#!/bin/bash

FILE="24.bmp"
OUT_DIR="stress_test_out"
mkdir -p "$OUT_DIR"

MIRROR_OPTIONS=(" --mirror --axis x --left_up 10.10 --right_down 500.500" " --mirror --axis y --left_up 500.500 --right_down 10.10" " --mirror --axis z --left_up 1000.1000 --right_down 500.500" "" " --mirror" )
COLOR_REPLACE_OPTIONS=(" --color_replace --old_color 255.255.255 --new_color 255.12.200 -fake_flag" " --color_replace --old_color 255.255.255 --new_color 255.12.200" " --color_replace --old_color 255.255.255 --new_color 255.12.200" "" )
SPLIT_OPTIONS=(" --split --number_x 20 --number_y 20 --thickness 2 --color 255.100.0" " --split --number_x 0 --number_y 20 --thickness 2 --color 255.100.0" "" )
COPY_OPTIONS=(" --copy --left_up 10.10 --right_down 200.200 --dest_left_up 300.300" " --copy --left_up 500.500 --right_down 200.200 --dest_left_up 300.300" "" )

make

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${GREEN}==========START=========${NC}"
for mirror_option in "${MIRROR_OPTIONS[@]}"; do
    for color_replace_option in "${COLOR_REPLACE_OPTIONS[@]}"; do
        for split_option in "${SPLIT_OPTIONS[@]}"; do
            for copy_option in "${COPY_OPTIONS[@]}"; do
                OPTIONS="$mirror_option$color_replace_option$split_option$copy_option"
                TEST_NAME="Testing with options: $OPTIONS"
                echo -e "${YELLOW}$TEST_NAME${NC}"
                ./coursework -colorful $OPTIONS -i "$FILE" -o "$OUT_DIR/output_${mirror_option// /}_${color_replace_option// /}_${split_option// /}_${copy_option// /}_${FILE}" &
                wait $!
                echo -e "${GREEN}Test $TEST_NAME completed${NC}"
            done
        done
    done
done
echo -e "${GREEN}==========END===========${NC}"

make clean
