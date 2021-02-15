#!/bin/bash
touch in
touch out
mkdir testcases
mkdir bits
cp /mnt/c/users/allen/documents/github/code/testlib.h testlib.h
cp /mnt/c/users/allen/documents/github/code/stdc++.h bits/stdc++.h
g++ -H bits/stdc++.h
