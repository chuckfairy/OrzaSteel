#!/bin/bash

# Requires entr

find ../src/ -name '*.cpp' | entr sh -c 'make -j8 && ./src/qt/*.qt'
