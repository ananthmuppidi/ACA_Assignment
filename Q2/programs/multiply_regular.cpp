#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

// Function to print a matrix
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

vector<vector<int>> multiply_regular(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();

    vector<vector<int>> res(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                res[i][j] += A[i][k] * B[k][j];

    return res;
}

// Function to randomly initialize a matrix
vector<vector<int>> initializeMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10; // Adjust range as needed

    return matrix;
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
    int R1 = MAT_SIZE;
    int C1 = MAT_SIZE;
    int R2 = MAT_SIZE;
    int C2 = MAT_SIZE;

    // Randomly initialize matrices A and B based on MAT_SIZE
    vector<vector<int>> A = initializeMatrix(R1, C1);
    vector<vector<int>> B = initializeMatrix(R2, C2);

    vector<vector<int>> resRegular = multiply_regular(A, B);

    // Print the result
    // print("Result Array using Regular Algorithm", resRegular, 0, 0, R1 - 1, C2 - 1);

    return 0;
}
