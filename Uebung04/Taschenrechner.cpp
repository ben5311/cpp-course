#include <sstream>
#include <cassert>
#include <cmath>
#include "Taschenrechner.h"
using namespace std;

bool Taschenrechner::zeichenVerfuegbar() const {
    return peekZeichen() != -1;
}

char Taschenrechner::peekZeichen() const {
    if (index < input.size()) return input.at(index);
    else return (char) -1;
}

char Taschenrechner::leseZeichen() {
    assert(zeichenVerfuegbar());
    char next = input.at(index++);
    while (index < input.size()-1 && input.at(index) == ' ') {  //ensures that next char is non space
        index++;
    }
    return next;
}

int Taschenrechner::leseZahl() {
    string s("");
    while (isdigit(peekZeichen())) {
        s.push_back(leseZeichen());
    }
    int result = 0;
    for (size_t i = 0; i < s.size(); i++) {
        int digit = s.at(i) - '0';
        result += digit * pow(10, s.size()-i-1);
    }
    return result;
}

int Taschenrechner::leseAusdruck() {
    int erg;
    char next = peekZeichen();
    if (next == '+') {
        leseZeichen();
        erg = leseSummand();
    } else if (next == '-') {
        leseZeichen();
        erg = -leseSummand();
    } else {
        erg = leseSummand(); 
    }
    while (true) {
        next = peekZeichen();
        if (next == '+') {
            leseZeichen();
            erg += leseSummand();
        } else if (next == '-') {
            leseZeichen();
            erg -= leseSummand();
        } else {
            return erg; 
        }
    }
}

int Taschenrechner::leseSummand() {
    int erg = leseFaktor();
    while (true) {
        char next = peekZeichen();
        if (next == '*') {
            leseZeichen();
            erg *= leseFaktor();
        } else if (next == '/') {
            leseZeichen();
            erg /= leseFaktor();
        } else {
            return erg;
        }
    }
    return erg;
}

int Taschenrechner::leseFaktor() {
    int erg;
    char next = peekZeichen();
    if (next == '(') {
        leseZeichen();
        erg = leseAusdruck();
        next = leseZeichen();
        if (next != ')') { cout << "Schließende Klammer fehlt!" << endl; exit(-1); }
    } else {
        erg = leseZahl();
    }
    return erg;
}

int Taschenrechner::calculate() {
    return leseAusdruck();
}