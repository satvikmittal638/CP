#!/bin/bash

# Compile all three files
g++ -O2 gen.cpp -o gen
g++ -O2 sol.cpp -o sol
g++ -O2 brute.cpp -o brute

# Infinite loop
for ((i=1; ; ++i)); do
    # 1. Generate a test case into input.txt
    ./gen > input.txt
    
    # 2. Run your solution
    ./sol < input.txt > my_out.txt
    
    # 3. Run the brute force solution
    ./brute < input.txt > brute_out.txt
    
    # 4. Compare the outputs
    # diff -w ignores whitespace differences (newline vs space)
    # > /dev/null silences the output if they match
    diff -w my_out.txt brute_out.txt > /dev/null
    
    # $? checks the exit code of the last command (diff)
    # 0 = match, 1 = difference found
    if [ $? -ne 0 ]; then
        echo "Test Case #$i: FAILED"
        echo "Input:"
        cat input.txt
        echo "Your Output:"
        cat my_out.txt
        echo "Expected Output:"
        cat brute_out.txt
        break
    fi
    
    echo "Test Case #$i: OK"
done