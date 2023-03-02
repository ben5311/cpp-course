#include <iostream>
#include "datum.cpp"
using namespace std;

int main() {
    Datum datum(01, 01, 2020);
    Datum dayAfter(02, 01, 2020);
    
    cout << datum << " == " << dayAfter << ": " << (datum == dayAfter) << endl;
    cout << datum << " != " << dayAfter << ": " << (datum != dayAfter) << endl;
    cout << datum << " < " << dayAfter << ": " << (datum < dayAfter) << endl;
    cout << "++" << datum << " == " << dayAfter << ": " << (++datum == dayAfter) << endl;
}