#!/bin/bash

g++ gen.cpp -o gen -std=c++20
g++ brute.cpp -o brute -std=c++20
g++ main.cpp -o main -std=c++20

for((i = 1; ; ++i)); do
    echo "Test #$i"
    ./gen > input.txt
    ./brute < input.txt > brute_out.txt
    ./main < input.txt > main_out.txt
    diff -w brute_out.txt main_out.txt || {
        echo "❌ Found mismatch on test #$i"
        echo "Input:"
        cat input.txt
        echo "Brute Output:"
        cat brute_out.txt
        echo "Main Output:"
        cat main_out.txt
        break
    }
done