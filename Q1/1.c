#include <stdio.h>
#include <stdlib.h>

double dot_product_scalar(const double *x, const double *y, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }
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
    if (n <= 0) {
        printf("Vector size must be a positive integer.\n");
        return 1;
    }

    double x[n];
    double y[n];

    initialize_array(x, n);
    initialize_array(y, n);

    double result = dot_product_scalar(x, y, n);
    printf("Dot Product: %.2f\n", result);

    return 0;
}
