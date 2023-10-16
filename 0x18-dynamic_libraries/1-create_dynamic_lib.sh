#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fPIC -c *.c
gcc -shared -o libdynamic.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
