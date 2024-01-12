#!/bin/bash

##########################################################
# Santito Tester Script for push_swap and checker        #
#                                                        #
# Usage: ./tester.sh <num_elements> <num_tests>          #
#                                                        #
# This script tests the push_swap program using random   #
# sets of numbers and checks the output with the checker. #
#                                                        #
# Arguments:                                             #
#   <num_elements> - Number of elements in each test      #
#   <num_tests>    - Number of tests to run               #
##########################################################

# Path to your push_swap and checker executables
PUSH_SWAP=./push_swap
CHECKER=./checker

# Check if the number of elements and tests is provided as arguments
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <num_elements> <num_tests>"
    exit 1
fi

NUM_ELEMENTS=$1
NUM_TESTS=$2

# Check if push_swap binary exists, and compile if missing
if [ ! -e "$PUSH_SWAP" ]; then
    echo "Compiling push_swap..."
    make > /dev/null
    make clean > /dev/null
fi

# Check if checker binary exists, and compile if missing
if [ ! -e "$CHECKER" ]; then
    echo "Compiling checker..."
    make bonus > /dev/null
    make clean > /dev/null
fi

# Function to generate random, non-repeating numbers
generate_random_numbers() {
    local numbers=($(seq 1 $NUM_ELEMENTS | shuf))
    echo "${numbers[@]}"
}

total_movements=0

# Run tests
for ((i=1; i<=$NUM_TESTS; i++)); do
    echo "Test $i:"

    # Generate random numbers
    input_numbers=$(generate_random_numbers)

    # Display input numbers
    echo "Input numbers: $input_numbers"

    # Run push_swap and capture the output
    output=$($PUSH_SWAP $input_numbers)

    # Count the number of movements (lines)
    num_movements=$(echo "$output" | wc -l)

    # Display the number of movements for each test
    echo "Number of Movements: $num_movements"

    total_movements=$((total_movements + num_movements))

    # Check if the output is sorted using the checker
    checker_output=$(echo "$output" | $CHECKER $input_numbers)

    # Display the checker output
    echo "Checker Output: $checker_output"

    echo "----------------------------------------"
done

# Calculate and display the average number of movements
average_movements=$((total_movements / NUM_TESTS))
echo "Average Number of Movements: $average_movements"
