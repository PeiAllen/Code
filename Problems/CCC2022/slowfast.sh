#!/bin/bash
g++ -o main main.cpp
g++ -o brute brute.cpp
g++ -o gen gen.cpp
for((i=0;;i++)); do
echo $i
./gen $i > in
./main < in > out
./brute < in > exp
diff out exp || break
done
