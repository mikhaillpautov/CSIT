//Дано множество точек на плоскости. Определить максимальное количество точек,
//лежащих на одной прямой.
#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

int main() {
    int n,max = 1 ;
    cout << "amount of points n: ";
    cin >> n;

    Point* points = new Point[n];
    cout << "enter cords(x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    //проврека полным перебором каждой точки для каждой точки
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = 2;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    if ((points[j].y - points[i].y) * (points[k].x - points[j].x) == (points[k].y - points[j].y) * (points[j].x - points[i].x)) {
                        c++;
                    }
                }
            }
            if (c > max) {
                max = c;
            }
        }
    }

    cout << "max on one line: " << max << endl;

    delete[] points;
    return 0;
}