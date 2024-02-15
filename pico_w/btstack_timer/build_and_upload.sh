#!/bin/bash

set -e

cd build
cmake -DPICO_BOARD=pico_w ..
make

picotool load -f btstack_timer.uf2