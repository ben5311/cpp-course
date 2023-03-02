#include <iostream>
using namespace std;

int main() {

    auto func_sum = [](double d1, double d2, double d3) -> double { return d1 + d2 + d3; };
    int a = 1;
    int b = 10;
    auto func_is_in_interval_a_b = [a,b](int i) -> bool { return i >= a && i <= b; };
    int z;
    auto func_reverse_z = [&z]() { z = -z; };

    cout << "Calculates sum of numbers." << endl;
    cout << "Input three numbers, separated by spaces: ";
    double d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    cout << d1 << " + " << d2 << " + " << d3 << " = " << func_sum(d1, d2, d3) << endl << endl;

    cout << "Checks if number is inside interval [" << a << "," << b << "]." << endl;
    cout << "Input number: ";
    int i;
    cin >> i;
    cout << i << " is in interval: " << (func_is_in_interval_a_b(i) ? "true" : "false") << endl << endl;

    cout << "Reverses number." << endl;
    cout << "Input number: ";
    cin >> z;
    func_reverse_z();
    cout << "Reversed number: " << z << endl;

}