#!/bin/bash

find . -name "how_far_are_you.txt" | tr -cd '/' | wc -c
