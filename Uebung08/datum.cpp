#include"datum.h"
#include<ctime>
#include<ostream>
#include<cmath>
#include "ungueltiges_datum_exception.h"

Datum::Datum()  { aktuell(); }

void Datum::set(int t, int m, int j) {
    tag_ = t;
    monat_ = m;
    jahr_ = j;
    if (!istGueltigesDatum(tag_, monat_, jahr_)) { throw UngueltigesDatumException(toString() + " is not a valid date!"); }
}

void Datum::aktuell() {   // Systemdatum eintragen
    time_t now = time(NULL);
    tm *z = localtime(&now);           // Zeiger auf struct tm
    jahr_  = z->tm_year + 1900;
    monat_ = z->tm_mon+1;               // localtime liefert 0..11
    tag_   = z->tm_mday;
}

Datum& Datum::operator++() {     // Datum um 1 Tag erh�hen
   ++tag_;
   // Monatsende erreicht?
   if(!istGueltigesDatum(tag_, monat_, jahr_)) {
     tag_ = 1;
     if (++monat_ > 12) {
        monat_ = 1;
        ++jahr_;
     }
   }
   return *this;
}

Datum Datum::operator++(int) {        // Datum um 1 Tag erh�hen
   Datum temp = *this;
   ++*this;                           // Pr�fix ++ aufrufen
   return temp;
}

std::string Datum::toString() const {
    std::string temp("tt.mm.jjjj");
              // implizite Umwandlung in char
    temp[0] = tag_/10 +'0';
    temp[1] = tag_%10 +'0';
    temp[3] = monat_/10 +'0';
    temp[4] = monat_%10 +'0';
    int pos = 9;                 // letzte Jahresziffer
    int j = jahr_;
    while(j > 0) {
       temp[pos] = j % 10 + '0';  // letzte Ziffer
       j = j/10;                  // letzte Ziffer abtrennen
       --pos;
    }
    return temp;
}

// globale Funktion
bool istGueltigesDatum(int t, int m, int j) {
     // Tage pro Monat(static vermeidet Neuinitialisierung):
     static int tmp[]={31,28,31,30,31,30,31,31,30,31,30,31};

     tmp[1] = istSchaltjahr(j) ? 29 : 28;

     return     m >= 1    && m <= 12
            && j  >= 1583 && j  <= 2399  // oder mehr
            && t  >= 1    && t   <= tmp[m-1];
}


// Neue Funktionen

bool Datum::operator==(const Datum& datum) const {
   return tag_ == datum.tag_ && monat_ == datum.monat_ && jahr_ == datum.jahr_;
}

bool Datum::operator!=(const Datum& datum) const {
   return !(*this == datum);
}

bool Datum::operator<(const Datum& datum) const {
   if (jahr_ < datum.jahr_) { return true; }
   if (jahr_ == datum.jahr_) {
      if (monat_ < datum.monat_) { return true; }
      if (monat_ == datum.monat_) {
         return tag_ < datum.tag_;
      }
   }
   return false;
}


int DatumDifferenz(const Datum& a, const Datum& b) {
   int diff = 0;
   if (b < a) {
      Datum cpy(b);
      while (cpy++ < a) { diff++; }
   } else {
      Datum cpy(a);
      while (cpy++ < b) { diff--; }
   }
   return diff;
}

int operator-(const Datum& a, const Datum& b) {
   return DatumDifferenz(a, b);
}

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
   os << datum.toString();
   return os;
}

