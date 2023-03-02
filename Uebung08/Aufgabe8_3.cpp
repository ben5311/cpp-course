#include <iostream>
#include "rational.cpp"
using namespace std;

int main() {

    Rational a(3, 4);
    cout << "a = " << a << endl << endl;

    cout << "a*2 = " << (a * 2) << endl;
    cout << "2*a = " << (2 * a) << endl;
    cout << "a *= 2;" << endl;
    a *= 2;
    cout << "a = " << a << endl << endl;

    cout << "a/4 = " << (a / 4) << endl;
    cout << "4/a = " << (4 / a) << endl;
    cout << "a /= 4;" << endl;
    a /= 4;
    cout << "a = " << a << endl;

}