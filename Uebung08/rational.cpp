// Klasse für rationale Zahlen
// (Definition der Methoden)
//////////////////////////////
#include"rational.h"
#include<iostream>
#include<cassert>
#include<string>
using namespace std;
 
// Elementfunktionen

void Rational::set(long z, long n) {
     zaehler = z;
     nenner  = n;
     assert(nenner != 0);
     kuerzen();
}
 
void Rational::eingabe() {
     cout << "Zähler :";
     cin >> zaehler;
     cout << "Nenner :";
     cin >> nenner;
     assert(nenner != 0);
     kuerzen();
}
 
void Rational::ausgabe() const {
     cout << zaehler << "/" << nenner << endl;
}
 
void Rational::kehrwert() {
     long temp = zaehler;
     zaehler = nenner;
     nenner  = temp;
     assert(nenner != 0);
}

long ggt(long x, long y) {
    long rest;
    while (y > 0) {
       rest = x % y;
       x = y; 
       y = rest;
    }
    return x;
}
 
void Rational::kuerzen() {
     int sign = 1;
     if (zaehler < 0) { sign=-sign; zaehler = -zaehler;}
     if (nenner  < 0) { sign=-sign; nenner  = -nenner;}
     long teiler = ggt(zaehler, nenner);
     zaehler = sign*zaehler/teiler;
     nenner = nenner/teiler;
}



// Neue Methoden

Rational::operator std::string() const { return std::to_string(zaehler) + "/" + std::to_string(nenner); }

Rational& Rational::operator=(const Rational& rational) {
     set(rational.zaehler, rational.nenner);
     return *this;
}

const Rational& Rational::operator+=(const Rational& rational) {
     long zaehler = this->zaehler*rational.nenner + rational.zaehler*this->nenner;
     long nenner = this->nenner*rational.nenner;
     set(zaehler, nenner);
     return *this;
}

const Rational& Rational::operator-=(const Rational& rational) {
     long zaehler = this->zaehler*rational.nenner - rational.zaehler*this->nenner;
     long nenner = this->nenner*rational.nenner;
     set(zaehler, nenner);
     return *this;
}

const Rational& Rational::operator*=(const Rational& rational) {
     long zaehler = this->zaehler*rational.zaehler;
     long nenner = this->nenner*rational.nenner;
     set(zaehler, nenner);
     return *this;
}

const Rational& Rational::operator/=(const Rational& rational) {
     long zaehler = this->zaehler*rational.nenner;
     long nenner = this->nenner*rational.zaehler;
     set(zaehler, nenner);
     return *this;
}

Rational operator+(const Rational& a, const Rational& b) { return Rational(a) += b; }

Rational operator-(const Rational& a, const Rational& b) { return Rational(a) -= b; }

Rational operator*(const Rational& a, const Rational& b) { return Rational(a) *= b; }

Rational operator/(const Rational& a, const Rational& b) { return Rational(a) /= b; }

bool operator==(const Rational& a, const Rational& b) { 
     return a.zaehler == b.zaehler && a.nenner == b.nenner; 
}

bool operator!=(const Rational& a, const Rational& b) { 
     return !(a == b); 
}

std::istream& operator>>(std::istream& is, Rational& output) {
     long zaehler, nenner;
     is >> zaehler;
     if (is.get() != '/') { throw std::runtime_error("input for Rational must be in format a/b where a and b are natural numbers"); }
     is >> nenner;
     output.set(zaehler, nenner);
     return is;
}
std::ostream& operator<<(std::ostream& os, const Rational& rational) {
     os << (std::string) rational;
     return os;
}