#!/bin/bash
g++ -o main main.cpp
g++ -o gen gen.cpp
for ((i=25;i<=25;++i)); do
  ./gen $i > data/subtask2case$i.in
  (./main < data/subtask2case$i.in) > data/subtask2case$i.out
done
