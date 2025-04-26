#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int partition(vector<vector<int>>& matrix, int col, int low, int high) {
    int pivot = matrix[high][col];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (matrix[j][col] < pivot) {
            i++;
            swap(matrix[i][col], matrix[j][col]);
        }
    }
    swap(matrix[i + 1][col], matrix[high][col]);
    return (i + 1);
}

void quickSort(vector<vector<int>>& matrix, int col, int low, int high) {
    if (low < high) {
        int pi = partition(matrix, col, low, high);

        quickSort(matrix, col, low, pi - 1);
        quickSort(matrix, col, pi + 1, high);
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
    string output = "C:/Users/super/CLionProjects/proga/txt's/txt_outputs/SortArray_Out_1.txt";
    vector<vector<int>> matrix = readMatrixFromFile(filename);

    int n = matrix.size();

    for (int col = 0; col < n; ++col) {
        quickSort(matrix, col, 0, n - 1);
    }
    
    arr_to_file(output, matrix);


    return 0;
}