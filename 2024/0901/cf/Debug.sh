#!/usr/bin/env bash
g++ $1.cpp -o $1 # your code
g++ $2.cpp -o $2 # brute
g++ $3.cpp -o $3 # generator
for i in {1..100} ; do
    ./$3 > input.txt
    # st=$(date +%s%N)
    ./$1 < input.txt > output1.txt
    # echo "$((($(date +%s%N) - $st)/1000000))ms"
    ./$2 < input.txt > output2.txt
    if cmp --silent -- "output1.txt" "output2.txt" ; then
        continue
    fi
    echo Input:
    cat input.txt
    echo Your Output:
    cat output1.txt
    echo Correct Output:
    cat output2.txt
    exit 1
done
echo OK!

