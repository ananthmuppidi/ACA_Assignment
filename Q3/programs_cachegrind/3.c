#include <stdio.h>
#include <stdlib.h>

#define N 4000

int main() {
    float *A = (float *)malloc(N * sizeof(float));
    float *X = (float *)malloc(N * sizeof(float));
    float **B = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; ++i) {
        B[i] = (float *)malloc(N * sizeof(float));
    }

    for (int i = 0; i < N - 1; i++) {
        S1 : A[i] = 0.0;
        for (int j = 1; j < N - 1; j++) {
            S2 : A[i] += 0.33 * (B[i][j] * X[j]);
        }
    }

    return 0;
}
