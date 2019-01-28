#!/bin/sh

find samples/valid -type f -name "*.sample" -exec bash run_test.sh {} \;
