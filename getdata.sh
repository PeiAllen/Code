#!/bin/bash
rm testcases/*
recieveddata=$(nc -lv 8080)
jsonfile={${recieveddata#*{}
cases=$(($(echo $jsonfile | jq '.tests[]' | wc -l)/4))
echo $cases
for ((i=1;i<=cases;i++)) do
   badinput=$(echo $jsonfile | jq --argjson index "$(($i-1))" '.tests[$index] .input')
   input=${badinput:1:-1}
   printf "%b" "$input" >> testcases/$i.in
   badoutput=$(echo $jsonfile | jq --argjson index "$(($i-1))" '.tests[$index] .output')
   output=${badoutput:1:-1}
   printf "%b" "$output" >> testcases/$i.out
done
