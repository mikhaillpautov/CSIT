#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

vector<int> getDiagonal(const vector<vector<int>>& matrix, int row, int col) {
    vector<int> diagonal;
    int n = matrix.size();
    while (row >= 0 && col < n) {
        diagonal.push_back(matrix[row][col]);
        row--;
        col++;
    }
    return diagonal;
}

void setDiagonal(vector<vector<int>>& matrix, const vector<int>& diagonal, int row, int col) {
    int index = 0;
    while (row >= 0 && col < matrix.size()) {
        matrix[row][col] = diagonal[index++];
        row--;
        col++;
    }
}

void sortDiagonals(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return;

    for (int d = 0; d < 2 * n - 1; d++) {
        int row, col;
        if (d < n) {
            row = n - 1 - d;
            col = 0;
        } else {
            row = 0;
            col = d - (n - 1);
        }

        vector<int> diagonal = getDiagonal(matrix, row, col);
        bubbleSort(diagonal);
        setDiagonal(matrix, diagonal, row, col);
    }
}

int coutLines(const string& filename) {
    ifstream file(filename);
    string line;
    int n = 0;
    while (!file.eof()) {
        getline(file, line);
        n++;
    }
    return n;
}

vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);

    int n = coutLines(filename);

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

void arr_to_file(const string& filename, const vector<vector<int>>& matrix) {
    ofstream file(filename);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

}


int main() {
    string filename = "C:/Users/super/CLionProjects/proga/txt's/SortArray.txt";
    string output = "C:/Users/super/CLionProjects/proga/txt's/txt_outputs/SortArray_Out_3.txt";
    vector<vector<int>> matrix = readMatrixFromFile(filename);

    sortDiagonals(matrix);

    arr_to_file(output, matrix);

    return 0;
}