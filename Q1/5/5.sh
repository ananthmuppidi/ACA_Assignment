#!/bin/bash

# Compile the C program
gcc -O0 -o 5 5.c

total_gflops=0
output_file="gflops_results.txt"

# Create or clear the output file
> "$output_file"

# Run the program 10 times and accumulate GFLOPS results
for ((i=1; i<=10; i++)); do
    echo "Run $i:" >> "$output_file"
    gflops=$(./5 | grep "Peak GFLOPS" | awk '{print $3}')
    echo "GFLOPS: $gflops" >> "$output_file"
    total_gflops=$(echo "$total_gflops + $gflops" | bc)
    echo "------------------------" >> "$output_file"
done

# Calculate the average GFLOPS
average_gflops=$(echo "scale=2; $total_gflops / 10" | bc)

# Write the average GFLOPS to the output file
echo "Average GFLOPS: $average_gflops" >> "$output_file"

# Clean up the compiled program
rm 5
