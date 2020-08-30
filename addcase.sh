#!/bin/bash
cases=$(($(ls testcases -1 | wc -l)/2 + 1))
echo $cases
cp in testcases/$cases.in
cp out testcases/$cases.out
