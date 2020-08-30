#!/bin/bash
g++ -o main main.cpp
echo "Running"
diff -w <(./main < in) out
