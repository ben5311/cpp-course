#include <iostream>
#include "datum.cpp"
#include "ungueltiges_datum_exception.h"
using namespace std;

int main() {
    Datum datum(17, 8, 2021); 
    
    try {
        datum.set(30, 2, 2010);
    } catch (const UngueltigesDatumException& e) {
        cout << e.what() << endl;
    }
}