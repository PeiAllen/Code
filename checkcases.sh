#!/bin/bash
g++ -o main main.cpp
g++ -o brute brute.cpp
g++ -o gen gen.cpp
for ((i=1;;++i)); do
  echo $i
  ./gen $i > in
  diff -w <(./main < in) <(./brute < in) || break
done
