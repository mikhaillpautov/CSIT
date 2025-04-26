#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);

        merge(arr, left, mid, right, ascending);
    }
}

void sortMatrixRows(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;

    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        bool ascending = (i + 1) % 3 != 0; // Строка не третья по счету
        mergeSort(matrix[i], 0, cols - 1, ascending);
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
    string output = "C:/Users/super/CLionProjects/proga/txt's/txt_outputs/SortArray_Out_2.txt";
    vector<vector<int>> matrix = readMatrixFromFile(filename);

    sortMatrixRows(matrix);

    arr_to_file(output, matrix);
    
    return 0;
}