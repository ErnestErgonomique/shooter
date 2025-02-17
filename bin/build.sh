#!/bin/bash
cmake -B build -G "MSYS Makefiles"
cmake --build build
./build/shooter
