#!/bin/bash

# Compile the files
echo "Compiling..."
g++ -O2 main.cpp -o solution
g++ -O2 generator.cpp -o generator
g++ -O2 validator.cpp -o validator

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful. Starting stress test..."

# Counter for test runs
count=0

while true; do
    ((count++))
    
    # 1. Generate Input
    ./generator > input.txt
    
    # 2. Run Solution
    ./solution < input.txt > output.txt
    
    # 3. Validate
    # We pass input and output filenames to the validator
    ./validator input.txt output.txt
    
    # Check return code of validator (0 = success, 1 = fail)
    if [ $? -ne 0 ]; then
        echo "------------------------------------------------"
        echo -e "\033[0;31mFAILED on test #$count\033[0m"
        echo "Input (first 10 lines):"
        head -n 10 input.txt
        echo "------------------------------------------------"
        echo "Your Output (first 10 lines):"
        head -n 10 output.txt
        echo "------------------------------------------------"
        break
    fi
    
    # Optional: Print progress every 100 tests
    if (( count % 100 == 0 )); then
        echo -e "\033[0;32mPassed $count tests so far...\033[0m"
    fi
done