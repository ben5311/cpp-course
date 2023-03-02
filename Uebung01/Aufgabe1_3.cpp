#include <iostream>
#include <cmath>
	using namespace std;
    int main() {
        int p, q, result1, result2, d;
        cout << "Geben Sie die Koeffizienten p und q fuer die Gleichung x^2+px+q=0 ein: ";
        cin >> p >> q;
        d=sqrt(p*p - 4*q);
        result1=((-1)*p+d)/2;
        result2=((-1)*p-d)/2;
        cout << "Loesung: " << result1 << "  " << result2;
        return 0;
    }