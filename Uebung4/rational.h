// Klasse für rationale Zahlen
//////////////////////////////
 
#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
 
class Rational {
   public:
     Rational();
     Rational(long z, long n);   // allgemeiner Konstruktor
     Rational(long l);  // Typumwandlungskonstruktor
 
     // Abfragen
     long getZaehler() const;
     long getNenner()  const;
 
     // arithmetische Methoden
     // (werden später durch überladene Operatoren ergänzt)
     void add(const Rational& r);
     // void add(long l);
     void sub(const Rational& r);
     void mult(const Rational& r);
     void div(const Rational& r);
 
     // weitere Methoden
     void set(long zaehler, long nenner);
     void eingabe();
     void ausgabe() const;
     void kehrwert();
     void kuerzen();
     std::string to_string();
 
   private:
     long zaehler, nenner;
};
 
// inline Methoden
inline Rational::Rational()               : zaehler(0), nenner(1) {}
inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {}
inline Rational::Rational(long l) : zaehler(l), nenner(1) {}
 
inline long Rational::getZaehler() const {return zaehler;}
inline long Rational::getNenner()  const {return nenner;}
 
#endif