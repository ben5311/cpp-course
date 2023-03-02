#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "Zahlstring eingeben: " << endl;
    string zahl;
    cin >> zahl;

    long result = 0;
    int quersumme = 0;

    for (size_t i = 0; i < zahl.size(); i++) {
        int digit = zahl.at((zahl.size()-1)-i) - '0';
        long part = digit;
        quersumme += digit;
        for (size_t j = 1; j <= i; j++) {
            part *= 10;
        }
        result += part;
    } 

    
    cout << "converted to long: " << result << endl;
    cout << "Quersumme : " << quersumme << endl;
    return 0;
}