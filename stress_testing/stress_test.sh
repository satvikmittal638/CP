#!/bin/bash

# Number of tests to run
NUM_TESTS=1000

# Compile the solutions and generator if not already compiled
g++ brute.cpp -o brute_solution
g++ solution.cpp -o solution
g++ generate_test.cpp -o generate_test

# Run the test loop
for ((i=1; i<=NUM_TESTS; i++))
do
    # Generate a test case
    ./generate_test > input.txt

    # Run the brute force solution with the generated test case
    ./brute_solution < input.txt > brute_output.txt

    # Run the correct solution with the same test case
    ./solution < input.txt > correct_output.txt

    # Compare the brute force output with the correct output
    if ! diff -q brute_output.txt correct_output.txt > /dev/null; then
        echo "Test $i failed!"
        echo "Input:"
        cat input.txt
        echo "Brute force output:"
        cat brute_output.txt
        echo "Correct output:"
        cat correct_output.txt
        exit 1
    fi

    # If the test passed, print the success message
    echo "Test $i passed."
done

echo "All tests passed!"