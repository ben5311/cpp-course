#include <iostream>
#include <string>
#include "Taschenrechner.h"
using namespace std;

int main() {
    while(true) {
        // Abbruch mit break
        cout << "Bitte einen mathematischen Ausdruck eingeben , z.B. 4*(12+3)"
               << endl << "(Abbruch durch Eingabe einer Leerzeile) : " ;
        string anfrage;
        getline(cin, anfrage);
        if(anfrage.length() > 0) {
            Taschenrechner tr(anfrage);
            cout << "Das Ergebnis des Ausdrucks '"
                   << tr.getAnfrage() << "' ist " << tr.getErgebnis() << endl;
        }
        else break;
    }
}