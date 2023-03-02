#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

double eval(function<double(double)> f, double x) {
    return f(x);
}

int main() {
    auto square_root = [](double d) { return sqrt(d); };
    auto square = [](double d) { return d*d; };
    auto half = [](double d) { return d/2; }; 
    cout << "Calculates different function values for number" << endl;
    cout << "Input number: ";
    double input;
    cin >> input;
    cout << "square_root(" << input << ") = " << eval(square_root, input) << endl;
    cout << "square(" << input << ") = " << eval(square, input) << endl;
    cout << "half(" << input << ") = " << eval(half, input) << endl;
}