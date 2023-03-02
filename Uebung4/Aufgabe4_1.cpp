#include "rational.h"
#include <iostream>
using namespace std;

int main() {
    Rational a(1, 2);
    cout << a.to_string() << endl;
    a.add(30);
    cout << a.to_string();
}