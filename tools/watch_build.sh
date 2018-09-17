#!/bin/bash

# Requires entr

find ../src/ | grep -E '(cpp|h|txt)' | entr sh -c 'make -j8 && ./src/qt/*.qt'
