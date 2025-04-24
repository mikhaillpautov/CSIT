#include <iostream>
using namespace std;

template<typename T>
T** inputMatrix(int rows, int cols) {
    T** matrix = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

template<typename T>
void printMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
int findMaxSumRowIndex(T** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) return -1;

    T maxSum = 0;
    int maxSumIndex = 0;

    for (int i = 0; i < rows; ++i) {
        T sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxSumIndex = i;
        }
    }

    return maxSumIndex;
}

template<typename T>
T** swapRows(T** matrix, int row1, int row2, int cols) {
    for (int j = 0; j < cols; ++j) {
        T temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
    return matrix;
}

template<typename T>
T** processMatrix(T** matrix, int rows, int cols) {
    int maxSumRowIndex = findMaxSumRowIndex(matrix, rows, cols);

    matrix = swapRows(matrix, 0, maxSumRowIndex, cols);

    return matrix;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    
    int** matrix = inputMatrix<int>(n, m);
    
    printMatrix(matrix, n, m);
    
    matrix = processMatrix(matrix, n, m);

    printMatrix(matrix, n, m);
    
    return 0;
}