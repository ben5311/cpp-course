#include <iostream>
#include "datum.cpp"
using namespace std;

int main() {
    Datum datum1(17, 8, 2021); 
    Datum datum2(01, 01, 2025); 
    
    cout << datum2 << " - " << datum1 << " = " << (datum2 - datum1) << endl;
}