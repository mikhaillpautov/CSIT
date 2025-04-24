#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    vector<double> a;
    double n,sum, sredarifm, prod, sredgeometr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        a.push_back(x);
    }

    sum = accumulate(a.begin(), a.end(), 0.0);// сложение всел эл. вектора
    sredarifm = sum / a.size();

    prod = accumulate(a.begin(), a.end(), 1.0, multiplies<>());//перемножение всех эл вектора
    sredgeometr = exp(log(prod) / a.size());

    cout << "Srednee Arifm: " << sredarifm << endl;
    cout << "Srednee Geometr: " << sredgeometr << endl;



}
//2.5 3.2 6.7 1.9 4.8
