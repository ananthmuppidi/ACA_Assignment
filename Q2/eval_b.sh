#!/bin/bash

events=("l2_cache_misses_from_dc_misses" "l2_cache_accesses_from_dc_misses" "L1-dcache-load-misses" "L1-dcache-loads" "L1-icache-load-misses" "L1-icache-loads" "instructions" "cycles")
event_list=$(IFS=,; echo "${events[*]}")

executable="./binaries/multiply_regular"
output_file="./reports/report_regular.txt"
# executable="./binaries/multiply_strassen"
# output_file="./reports/report_strassen.txt"

> "$output_file"

for (( i=4; i<=9; i++ ))
do
    value=$((2**i))
    echo "Running for value: $value" >> "$output_file"
    command="perf stat -e $event_list $executable $value"
    output=$($command 2>&1)
    for event in "${events[@]}"
    do
        extracted_value=$(echo "$output" | awk -v ev="$event" '$0 ~ ev {gsub(/,/,""); print $1}')
        echo "$event: $extracted_value" >> "$output_file"
    done
    echo "--------------------------------" >> "$output_file"
done
