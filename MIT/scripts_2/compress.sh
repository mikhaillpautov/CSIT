#!/bin/bash

find "$1" -type f -name "*.cpp" -exec zip cpp_files.zip {} +
