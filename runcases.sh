#!/bin/bash
g++ -o main main.cpp
cases=$(($(ls testcases -1 | wc -l)/2))
for ((i=1;i<=cases;i++)) do
   echo $i
   diff -w --strip-trailing-cr <(./main < testcases/$i.in) testcases/$i.out || break
done
