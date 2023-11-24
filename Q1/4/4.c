#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_SIZE (1 << 30)  // 1 GB

int main() {

    int64_t *array = (int64_t *)malloc(sizeof(int64_t) * ARRAY_SIZE);

    if (array == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 9,223,372,036,854,775,807;
    }

    clock_t start_time = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 1;
    }
    clock_t end_time = clock();


    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    double memory_write_bandwidth = (sizeof(int64_t) * ARRAY_SIZE) / (elapsed_time * 1e9);

    printf("Memory Write Bandwidth: %.2f GB/s\n", memory_write_bandwidth);

    start_time = clock();
    int64_t sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    double memory_read_bandwidth = (sizeof(int64_t) * ARRAY_SIZE) / (elapsed_time * 1e9);

    printf("Memory Read Bandwidth: %.2f GB/s\n", memory_read_bandwidth);

    free(array);

    return 0;
}

