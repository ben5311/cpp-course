#include <iostream>
using namespace std;
int main() {
    // Programm zur Berechnung der
    // Summe zweier Zahlen
    int summe;
    int a;
    int b;
    // Lies die Zahlen a und b ein
    cout << "a und b eingeben : ";
    cin >> a >> b;
    /* Berechne die Summe beider Zahlen
    */
    summe = a + b;
    // Zeige das Ergebnis auf dem
    // Bildschirm an
    cout << "Summe=" << summe;
    return 0;
}