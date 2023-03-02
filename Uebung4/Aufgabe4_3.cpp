#include <iostream>
#include "MeineKlasse.h"
using namespace std;

int main() {
    MeineKlasse objekt;
    cout << "objekt.readonlyAttribut=" << objekt.readonlyAttribut << endl;    // ok
    //objekt.readonlyAttribut = 999; // Fehler! nicht erlaubte Aktion
    objekt.aendern(999);              // OK, Setter funktioniert!
    // erlaubter direkter lesender Zugriff:
    cout << "objekt.readonlyAttribut=" << objekt.readonlyAttribut << endl;    // ok
}