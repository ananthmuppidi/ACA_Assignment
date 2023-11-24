#!/bin/bash

MATRIX_SIZE=512

TILE_SIZES=(2 4 8 16 32 64)

OUTPUT_FILE="./reports/report_tile.txt"

> "$OUTPUT_FILE"

for TILE_SIZE in "${TILE_SIZES[@]}"
do
    echo "Running cachegrind for tile size $TILE_SIZE"
    echo "Tile Size: $TILE_SIZE" >> "$OUTPUT_FILE"
    valgrind --tool=cachegrind --I1=32768,8,64 --D1=32768,8,64 --L2=1048576,8,64 ./binaries/multiply_tile $MATRIX_SIZE $TILE_SIZE >> "$OUTPUT_FILE" 2>&1
    echo "----------------------------------------" >> "$OUTPUT_FILE"
done

echo "All runs completed. Results saved to $OUTPUT_FILE"
