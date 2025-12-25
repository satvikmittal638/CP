#!/bin/bash

# 1. Compile all files
echo "Compiling..."
g++ -O3 gen.cpp -o gen
g++ -O3 my.cpp -o my
g++ -O3 sol.cpp -o sol
g++ -O3 check.cpp -o check

# 2. Run Stress Test Loop
echo "Starting Stress Test..."
for ((i = 1; i <= 10000; i++)); do
    # Generate test case
    ./gen > input.txt

    # Run your solution
    ./my < input.txt > my_out.txt
    exit_code_my=$?
    
    # Run reference solution
    ./sol < input.txt > sol_out.txt
    exit_code_sol=$?

    # Check for runtime errors
    if [ $exit_code_my -ne 0 ]; then
        echo "CRITICAL: my.cpp crashed on test $i"
        cat input.txt
        break
    fi
    if [ $exit_code_sol -ne 0 ]; then
        echo "CRITICAL: sol.cpp crashed on test $i"
        cat input.txt
        break
    fi

    # Run checker
    ./check input.txt my_out.txt sol_out.txt > result.txt
    
    # If checker printed anything other than "PASS", it failed
    if ! grep -q "PASS" result.txt; then
        echo "Failed on test $i"
        cat input.txt
        echo "--- Checker Output ---"
        cat result.txt
        break
    fi

    # Progress indicator every 100 tests
    if (( i % 100 == 0 )); then
        echo "Passed $i tests"
    fi
done