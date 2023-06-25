#!/bin/bash

cmake -B build -S . && cmake --build build && mkdir -p bin && mv build/exe bin
echo "----------Executable file within bin directory----------"
