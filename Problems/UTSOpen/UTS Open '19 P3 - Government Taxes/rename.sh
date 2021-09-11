#!/bin/bash
for ((i=16;i<=25;++i)); do
  cp data/subtask2case$i.in data/subtask2case$((i-5)).in
  cp data/subtask2case$i.out data/subtask2case$((i-5)).out
done
