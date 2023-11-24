#!/bin/bash

ITERATIONS=10

WRITE_OUTPUT_FILE="write_bandwidth.txt"
READ_OUTPUT_FILE="read_bandwidth.txt"
OUTPUTS_FILE="outputs.txt"

gcc -O0 4.c -o bandwidth_test

> $WRITE_OUTPUT_FILE
> $READ_OUTPUT_FILE

for ((i=1; i<=$ITERATIONS; i++)); do
    output=$(./bandwidth_test)
    echo "$output" | grep "Memory Write Bandwidth" | awk '{print $4}' >> $WRITE_OUTPUT_FILE
    echo "$output" | grep "Memory Read Bandwidth" | awk '{print $4}' >> $READ_OUTPUT_FILE
done

avg_write_bandwidth=$(awk '{ total += $1 } END { printf "%.2f", total/NR }' $WRITE_OUTPUT_FILE)

avg_read_bandwidth=$(awk '{ total += $1 } END { printf "%.2f", total/NR }' $READ_OUTPUT_FILE)

echo "Average Memory Write Bandwidth: ${avg_write_bandwidth} GB/s" > $OUTPUTS_FILE
echo "Average Memory Read Bandwidth: ${avg_read_bandwidth} GB/s" >> $OUTPUTS_FILE

rm bandwidth_test

echo "Results written to $OUTPUTS_FILE"
