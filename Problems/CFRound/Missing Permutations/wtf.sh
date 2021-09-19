#!/bin/bash
g++ gen.cpp -o gen -O2
g++ main.cpp -o main -O2
for ((i=1;i<=25;++i)); do
    echo $i
    ./gen $i > in$i
    ./main < in$i > out$i
done
