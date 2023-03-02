#include <iostream>
#include <sstream>
#include <cmath>
#include <assert.h>
using namespace std;

const char* input = "( 13 + 7 )*5 - (2 * 3 + 7) / (-8)";
istringstream is(input);

char peekZeichen();
char leseZeichen();
int leseZahl();
int leseFaktor();
int leseSummand();
int leseAusdruck();
int calculate();

bool zeichenVerfuegbar() {
    return is.peek() != istream::traits_type::eof();
}

char peekZeichen() {
    return is.peek();
}

char leseZeichen() {
    assert(zeichenVerfuegbar());
    char next = is.get();
    while (is.peek() == ' ') {  //ensures that next char is non space
        is.get();
    }
    return next;
}

int leseZahl() {
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

int leseAusdruck() {
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

int leseSummand() {
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

int leseFaktor() {
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

int calculate() {
    return leseAusdruck();
}


int main() {
    cout << input << " = " ;
    cout << calculate();
    return 0;
}