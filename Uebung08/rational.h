// Klasse für rationale Zahlen
//////////////////////////////
 
#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <cassert>
#include <iostream>
 
class Rational {
   public:
     Rational() : Rational(0, 1) {}
     Rational(long l) : Rational(l, 1) {}  // Typumwandlungskonstruktor
     Rational(long z, long n) {           // allgemeiner Konstruktor
      set(z, n);
     }   
     
     // Abfragen
     long getZaehler() const { return zaehler; };
     long getNenner()  const { return nenner; }

     // Setter
     void set(long zaehler, long nenner);
 
     // weitere Methoden
     void eingabe();
     void ausgabe() const;
     void kehrwert();
     void kuerzen();


     // Neue Methoden
     operator std::string() const;
     Rational& operator=(const Rational& rational);
     const Rational& operator+=(const Rational& rational);
     const Rational& operator-=(const Rational& rational);
     const Rational& operator*=(const Rational& rational);
     const Rational& operator/=(const Rational& rational);

     friend Rational operator+(const Rational& a, const Rational& b);
     friend Rational operator-(const Rational& a, const Rational& b);
     friend Rational operator*(const Rational& a, const Rational& b);
     friend Rational operator/(const Rational& a, const Rational& b);
     friend bool operator==(const Rational& a, const Rational& b);
     friend bool operator!=(const Rational& a, const Rational& b);
     friend std::istream& operator>>(std::istream& is, Rational& output);
     friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
 

   private:
     long zaehler, nenner;
};

 
#endif