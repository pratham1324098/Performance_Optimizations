#include <iostream>
#include <vector>
#include <omp.h> // Include OpenMP header

using namespace std;

vector<vector<int>> matrix_multiplication(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    vector<vector<int>> result(5, vector<int>(5, 0));
    #pragma omp parallel for // Parallelize the outer loop
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 5; ++k) {
            for (int j = 0; j < 5; ++j) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    vector<vector<int>> result_matrix = matrix_multiplication(matrix1, matrix2);

    // Print the result matrix
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << result_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
