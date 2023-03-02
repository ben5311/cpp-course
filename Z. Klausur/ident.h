// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#ifndef IDENT_H
#define IDENT_H

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

//!!! Hier bitte Daten eintragen!
string matse_name   = "Benjamin Heimann";
string matse_matrnr = "3245065";


void check_ident() {
    if ( (matse_name   == "Vorname Nachname") ||
         (matse_matrnr == "123456") ) {
        cout << "*** Sie müssen in der Datei ident.h noch ihre Daten eintragen ***" << endl;
        exit(EXIT_FAILURE);
    }
}

#endif
