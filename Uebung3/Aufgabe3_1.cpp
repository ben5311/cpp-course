#include <iostream>
#include <iomanip>
#include <cmath>
#include <assert.h>
using namespace std;

double ehoch1(double x) {
    double result = 1;
    double factorial = 1;
    for (int i = 1; i <= 100; i++) {
        factorial *= i;
        result += pow(-x, i) / factorial;
    }
    return result;
}

double ehoch2(double x) {
    double result = 1;
    double factorial = 1;
    for (int i = 1; i <= 100; i++) {
        factorial *= i;
        if (x < 0) result += pow(-x, i) / factorial;
        else result += pow(x, i) / factorial;
    }
    return (x < 0) ? 1/result : result;
}

int main() {
    cout.fill(' ');

    for (int i = -40; i <= 40; i += 10) {
        if (i >= 0) cout << '+';
        cout << std::setw(2) << i << " e^i=" << exp(i) << " ehoch(i)=" << ehoch2(i) << endl;
    }
    return 0;
}