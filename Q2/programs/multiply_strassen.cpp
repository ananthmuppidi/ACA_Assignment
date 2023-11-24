#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

void print(string display, const vector<vector<int>> &matrix, int sr, int sc, int er, int ec)
{
    cout << endl << display << " ================ " << endl;
    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void add(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &res, int idx)
{
    for (auto i = 0; i < idx; i++)
        for (auto j = 0; j < idx; j++)
            res[i][j] = A[i][j] + B[i][j];
}

vector<vector<int>> multiply_strassen(const vector<vector<int>> &A, const vector<vector<int>> &B, int size)
{
    // base case
    if (size == 1)
    {
        vector<vector<int>> res(1, vector<int>(1, 0));
        res[0][0] = A[0][0] * B[0][0];
        return res;
    }

    // split into half
    int idx = size / 2;

    // memory for intermediate matrices
    vector<vector<int>> r00(idx, vector<int>(idx, 0));
    vector<vector<int>> r01(idx, vector<int>(idx, 0));
    vector<vector<int>> r10(idx, vector<int>(idx, 0));
    vector<vector<int>> r11(idx, vector<int>(idx, 0));
    vector<vector<int>> a00(idx, vector<int>(idx, 0));
    vector<vector<int>> a01(idx, vector<int>(idx, 0));
    vector<vector<int>> a10(idx, vector<int>(idx, 0));
    vector<vector<int>> a11(idx, vector<int>(idx, 0));
    vector<vector<int>> b00(idx, vector<int>(idx, 0));
    vector<vector<int>> b01(idx, vector<int>(idx, 0));
    vector<vector<int>> b10(idx, vector<int>(idx, 0));
    vector<vector<int>> b11(idx, vector<int>(idx, 0));

    // splitting the matrices into the declared memory
    for (auto i = 0; i < idx; i++)
        for (auto j = 0; j < idx; j++)
        {
            a00[i][j] = A[i][j];
            a01[i][j] = A[i][j + idx];
            a10[i][j] = A[idx + i][j];
            a11[i][j] = A[i + idx][j + idx];
            b00[i][j] = B[i][j];
            b01[i][j] = B[i][j + idx];
            b10[i][j] = B[idx + i][j];
            b11[i][j] = B[i + idx][j + idx];
        }

    // adding subparts
    add(multiply_strassen(a00, b00, idx), multiply_strassen(a01, b10, idx), r00, idx);
    add(multiply_strassen(a00, b01, idx), multiply_strassen(a01, b11, idx), r01, idx);
    add(multiply_strassen(a10, b00, idx), multiply_strassen(a11, b10, idx), r10, idx);
    add(multiply_strassen(a10, b01, idx), multiply_strassen(a11, b11, idx), r11, idx);

    // merging subparts into the answer matrix
    vector<vector<int>> res(size, vector<int>(size, 0));
    for (auto i = 0; i < idx; i++)
        for (auto j = 0; j < idx; j++)
        {
            res[i][j] = r00[i][j];
            res[i][j + idx] = r01[i][j];
            res[idx + i][j] = r10[i][j];
            res[i + idx][j + idx] = r11[i][j];
        }

    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <matrix_size>" << endl;
        return 1;
    }

    // Get matrix size from command line argument
    int MAT_SIZE = atoi(argv[1]);
    int size = MAT_SIZE;

    vector<vector<int>> A(size, vector<int>(size, 0));
    vector<vector<int>> B(size, vector<int>(size, 0));

    // Randomly initialize matrices A and B based on MAT_SIZE
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            A[i][j] = rand() % 10; // Adjust range as needed
            B[i][j] = rand() % 10;
        }

    vector<vector<int>> resStrassen = multiply_strassen(A, B, size);
    // print("Result Array using Strassen's Algorithm", resStrassen, 0, 0, size - 1, size - 1);

    return 0;
}
