#include <iostream>
using namespace std;

int main() {

    unsigned int uintv = 0;
    int intv = 1;
    uint64_t ulongv = 0L;
    int64_t longv = 1L;
    unsigned long long ulonglongv = 0;
    long long longlongv = 1;

    cout << "Maximaler uint-Wert: " << (uintv - 1) << endl;
    cout << "Minimaler int-Wert: " << (intv << 31) << endl;
    cout << "Maximaler int-Wert: " << (intv << 31) - 1 << endl << endl;
    
    cout << "Maximaler ulong-Wert: " << (ulongv - 1) << endl;
    cout << "Minimaler long-Wert: " << (longv << 63) << endl;
    cout << "Maximaler long-Wert: " << (longv << 63) - 1 << endl << endl;

    cout << "Maximaler ulonglong-Wert: " << (ulonglongv - 1) << endl;
    cout << "Minimaler longlong-Wert: " << (longlongv << 63) << endl;
    cout << "Maximaler longlong-Wert: " << (longlongv << 63) - 1 << endl << endl;

    return 0;
}