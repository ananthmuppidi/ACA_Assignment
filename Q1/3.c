#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

double dot_product_even(const double *x, const double *y, int n) {
    double result = 0.0;
    __m256d acc = _mm256_setzero_pd();

    for (int i = 0; i < n; i += 4) {
        __m256d vec_x = _mm256_loadu_pd(&x[i]);
        __m256d vec_y = _mm256_loadu_pd(&y[i]);
        acc = _mm256_add_pd(acc, _mm256_mul_pd(vec_x, vec_y));
    }

    double dot[4];
    _mm256_storeu_pd(dot, acc);

    result = dot[0] + dot[2];

    return result;
}

void initialize_array(double *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <vector size>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0 || n % 4 != 0) {
        printf("Vector size must be a positive integer multiple of 4.\n");
        return 1;
    }

    double x[n];
    double y[n];

    initialize_array(x, n);
    initialize_array(y, n);

    double result = dot_product_even(x, y, n);
    printf("Dot Product: %.2f\n", result);

    return 0;
}
