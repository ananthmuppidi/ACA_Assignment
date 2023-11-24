#!/bin/bash

events=("cache-misses" "task-clock")
event_list=$(IFS=,; echo "${events[*]}")

executable="../bin/2"
output_file="./reports/2.txt"

> "$output_file"

for (( i=5; i<=14; i++ ))
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
