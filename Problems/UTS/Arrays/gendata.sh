#!/bin/bash
g++ -o main main.cpp
g++ -o gen gen.cpp
for ((i=1;i<=5;++i)); do
  echo $i
  ./gen $i 1 > in$i.txt
  ./main < in$i.txt > out$i.txt
done
for ((i=6;i<=6;++i)); do
  echo $i
  ./gen $i 2 > in$i.txt
  ./main < in$i.txt > out$i.txt
done
for ((i=7;i<=15;++i)); do
  echo $i
  ./gen $i 3 > in$i.txt
  ./main < in$i.txt > out$i.txt
done

