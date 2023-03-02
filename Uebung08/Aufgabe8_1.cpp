#include "rational.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Rational a(3, 4);
    Rational b(6, 8);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a==b = " << (a == b ? "true" : "false") << endl;
    cout << "a!=b = " << (a != b ? "true" : "false") << endl << endl;

    cout << "Input rational in format a/b" << endl;
    Rational c;
    cin >> c;
    cout << "c = " << c << endl;
    cout << "a==c = " << (a == c ? "true" : "false") << endl << endl;

}