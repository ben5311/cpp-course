#include "array2d.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    int sourceA[2][3] = {1, 2, 3, 
                         4, 5, 6};
    int sourceB[3][2] = {1, 1, 
                         0, 1, 
                         1, 2};
    Array2d<int> a(sourceA);
    Array2d<int> b(sourceB);

    printArray(a);
    cout << "x" << endl;
    printArray(b);
    cout << "=" << endl;
    Array2d<int> *multiplied = a.mmult_with(b);  //funktioniert

    printArray(*multiplied);
    cout << endl << endl;
    delete multiplied;

    Array2d<float> c(2, 3, 1.5);
    Array2d<float> d(3, 2, 2.0);
    printArray(c);
    cout << "x" << endl;
    printArray(d);
    cout << "=" << endl;
    printArray(*mmult(c, d));    //funktioniert
}