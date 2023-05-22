#!/bin/bash

# Wait for 98 seconds
sleep 98

# Inject the custom shared library using LD_PRELOAD
export LD_PRELOAD=./101-make_me_win.so

# Run the gm program with the desired numbers
./gm 9 8 10 24 75 9
