#!/bin/bash

find . -type f  -name "*.cpp" -o-type f  -name "*.h"  -exec cat {} + | wc -l
