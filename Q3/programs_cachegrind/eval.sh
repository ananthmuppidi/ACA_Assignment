#!/bin/bash

l1_cache_sizes_kb=(32 64 128)
l2_cache_sizes_kb=(64 128 256)

line_size_bytes=64

for l1_size_kb in "${l1_cache_sizes_kb[@]}"; do

    l1_size_bytes=$((l1_size_kb * 1024))
    l1_lines=$((l1_size_bytes / line_size_bytes))

    for l2_size_kb in "${l2_cache_sizes_kb[@]}"; do

        # Calculate the number of lines for L2 cache
        l2_size_bytes=$((l2_size_kb * 1024))
        l2_lines=$((l2_size_bytes / line_size_bytes))

        # Print the Valgrind command
        echo "valgrind --tool=cachegrind --I1=${l1_size_bytes},${l1_lines},${line_size_bytes} --D1=${l1_size_bytes},${l1_lines},${line_size_bytes} --LL=${l2_size_bytes},${l2_lines},${line_size_bytes} ./3"
        
    done
done
