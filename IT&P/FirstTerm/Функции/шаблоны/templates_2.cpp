#include <iostream>
using namespace std;

// Создание массивов
template<typename T>
T** createArray(int rows, int cols) {
   
    T** arr = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new T[cols];
    }
    return arr;
}

// Шаблон для освобождения памяти
template<typename T>
void destroyArray(T** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

//Ввод массива
template<typename T>
T** inputArray(int rows, int cols) {
    // Создаём новый массив
    T** arr = createArray<T>(rows, cols);
    cout << "Enter elements"
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
    
    return arr;
}

// Вывод массива
template<typename T>
T** printArray(T** arr, int rows, int cols) {
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return arr;
}

//Замена столбцов
template<typename T>
T** swapColumns(T** arr, int rows, int cols) {
    
    for (int col = 0; col < cols / 2; ++col) {
        for (int row = 0; row < rows; ++row) {
            T temp = arr[row][col];       
            arr[row][col] = arr[row][cols - 1 - col];   // Поменять местами первый и последний столбцы
            arr[row][cols - 1 - col] = temp;
        }
    }
    
    return arr;
}

int main() {
    int n, m;

   
    cout << "rows (n): ";
    cin >> n;
    cout << "cols (m): ";
    cin >> m;
    
    char** intArr = inputArray<char>(n, m);// Поменять на int или double для других примеров
    
    printArray(intArr, n, m);
    
    swapColumns(intArr, n, m);

    cout << endl;
    
    printArray(intArr, n, m);
    
    destroyArray(intArr, n);

    return 0;
}