#include "Teilnehmer.h"
#include <iostream>
using namespace std;

void Teilnehmer::lerntKennen(Teilnehmer& teilnehmer) {
    if (&teilnehmer == this) { return; }
    bekannte.insert(&teilnehmer);   //this lernt teilnehmer kennen
    teilnehmer.bekannte.insert(this);   //teilnehmer lernt this kennen
}

void Teilnehmer::druckeBekannte() {
    for (Teilnehmer* teilnehmer : bekannte) {
        cout << teilnehmer->gibNamen() << " ";
    }
    cout << endl;
}