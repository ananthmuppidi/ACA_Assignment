#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void tiledMatrixMultiply(int n, int tile_size, std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& B, std::vector<std::vector<double>>& C) {
    for (int i = 0; i < n; i += tile_size) {
        for (int j = 0; j < n; j += tile_size) {
            for (int k = 0; k < n; k += tile_size) {
                for (int y = i; y < i + tile_size && y < n; y++) {
                    for (int x = j; x < j + tile_size && x < n; x++) {
                        for (int z = k; z < k + tile_size && z < n; z++) {
                            C[y][x] += A[y][z] * B[z][x];
                        }
                    }
                }
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <matrix size> <tile size>\n";
        return 1;
    }

    int n = std::atoi(argv[1]);
    int tile_size = std::atoi(argv[2]);

    std::srand(std::time(nullptr));  // Initialize random seed

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<std::vector<double>> B(n, std::vector<double>(n));
    std::vector<std::vector<double>> C(n, std::vector<double>(n, 0));

    // Initialize matrices A and B with random values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = std::rand() % 100; // Random values between 0 and 99
            B[i][j] = std::rand() % 100;
        }
    }

    tiledMatrixMultiply(n, tile_size, A, B, C);

    // Print matrix C
    // std::cout << "Matrix C (Result): \n";

    return 0;
}
