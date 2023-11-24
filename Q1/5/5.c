#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OPERATIONS (1e9)  

int main() {
    

    volatile float a = 1.0;
    volatile float b = 2.0;

    clock_t start_time = clock();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        volatile float c = a + b; 
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    double gflops = NUM_OPERATIONS / (elapsed_time * 1e9);

    printf("Peak GFLOPS: %.2f GFlops/sec\n", gflops);
    return 0;
}
