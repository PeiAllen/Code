!/bin/bash

g++ -std=c++20 -o main main.cpp
g++ -std=c++20 -o brute brute.cpp
g++ -std=c++20 -o gen gen.cpp

for((i=1;;i++)); do
	echo $i
	./gen $i > in
	./main < in > out
	./brute < in > exp
	diff out exp || break
done
