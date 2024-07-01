#include <iostream>
#include <cmath>

using namespace std;

double binarySearch(double c, double time) {
    double left = 0, right = 1e10; // Adjust this range accordingly
    double result = 0;

    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        double cost = c * mid * log2(mid);

        if (cost <= time) {
            result = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    return result;
}

int main() {
    double c, time;
    cin >> c >> time;

    double n = binarySearch(c, time);
    cout << fixed << n << endl;

    return 0;
}
