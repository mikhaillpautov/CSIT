#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) { //заполнение вектора
        int num;
        cin >> num;
        nums.push_back(num);
    }

    if (!nums.empty()) { //поиск и удаление максимального эдемента
        int max = *max_element(nums.begin(), nums.end());
        nums.erase(remove(nums.begin(), nums.end(), max), nums.end());
    }

    for (int a : nums) {//вывод
        cout << a << " ";
    }
    return 0;
}