#include <iostream>
#include "rational.cpp"
using namespace std;

int main() {

    Rational a(3, 4);
    cout << "a = " << a << endl;
    cout << "a + 30 = " << (a + 30) << endl;
    cout << "a += 30;" << endl;
    a += 30;
    cout << "a = " << a << endl;
    cout << "a -= 30;" << endl;
    a -= 30;
    cout << "a = " << a << endl << endl;

}