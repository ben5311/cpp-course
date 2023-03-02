#include <iostream>
using namespace std;

int main() {

    cout << "Zahl eingeben: " << endl;
    long long input;
    cin >> input;
    cin.ignore(1);

    long long min = input;
    long long max = input;

    int i = 0;
    do {
        if (input %2 == 0) { 
            input /= 2; 
        } else { 
            input *= 3; 
            input++;
        }
        if (input < min) {
            cout << input << endl;
            min = input;
            cin.get();
        }
        if (input > max) {
            cout << input << endl;
            max = input;
            cin.get();
        }
        i++;
    } while (input > 1);

    cout << "Fertig." << endl << "Ergebnis: " << input << endl << "Anzahl Iterationen: " << i << endl;
    return 0;
}