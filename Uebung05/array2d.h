#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <cassert>
#include <iostream>

template <typename T> 
class Array2d {
  public:
    Array2d(size_t z, size_t s) : zeilen{z}, spalten{s}, ptr{new T[z * s]} {}
    Array2d(size_t z, size_t s, const T &wert) : Array2d(z, s) { // an obigen Konstruktor delegieren
      init(wert);
    }
    template<size_t DIM_Z, size_t DIM_S>
    Array2d(T (&sourceArray)[DIM_Z][DIM_S] ) : Array2d(DIM_Z, DIM_S) {
      size_t i = 0;
      for (size_t z = 0; z < DIM_Z; z++) {
        for (size_t s = 0; s < DIM_S; s++) {
          ptr[i++] = sourceArray[z][s];
        }
      }
    }
    Array2d(const Array2d &a) : Array2d(a.zeilen,
                  a.spalten) { // an obigen Konstruktor delegieren
      size_t anzahl = zeilen * spalten;
      for (size_t i = 0; i < anzahl; ++i) {
        ptr[i] = a.ptr[i];
      }
    }

    ~Array2d() { delete[] ptr; }

    Array2d &operator=(const Array2d &arr) = delete; // (noch) verbieten

    Array2d &assign(Array2d tmp) {
      swap(tmp);
      return *this;
    }

    size_t getZeilen() const { return zeilen; }

    size_t getSpalten() const { return spalten; }

    void init(const T &wert) { // Alle Elemente mit wert initialisieren
      size_t anzahl = zeilen * spalten;
      for (size_t i = 0; i < anzahl; ++i) {
        ptr[i] = wert;
      }
    }

    const T &at(size_t z, size_t s) const {
      assert(z < zeilen && s < spalten);
      return ptr[z * spalten + s];
    }

    T &at(size_t z, size_t s) {
      assert(z < zeilen && s < spalten);
      return ptr[z * spalten + s];
    }

    void swap(Array2d &rhs) {
      size_t temp = zeilen;
      zeilen = rhs.zeilen;
      rhs.zeilen = temp;
      temp = spalten;
      spalten = rhs.spalten;
      rhs.spalten = temp;
      T *tempPtr = ptr;
      ptr = rhs.ptr;
      rhs.ptr = tempPtr;
    }

    template <typename U, typename std::enable_if<std::is_arithmetic<U>::value>::type*>
    friend Array2d<U> *mmult(const Array2d<U> &a, const Array2d<U> &b);

  template <typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    Array2d<T> *mmult_with(const Array2d<T> &b) {
      return mmult(*this, b);
    } 

  private:
    size_t zeilen;
    size_t spalten;
    T *ptr;
};



template <typename U, typename std::enable_if<std::is_arithmetic<U>::value>::type* = nullptr>
Array2d<U> *mmult(const Array2d<U> &a, const Array2d<U> &b) {
  assert(a.spalten == b.zeilen);
  Array2d<U> *result = new Array2d<U>(a.zeilen, b.spalten);

  for (size_t spalte = 0; spalte < b.spalten; spalte++) {   //Spalte der rechten Matrix
    for (size_t zeile = 0; zeile < a.zeilen; zeile++) {   //Zeile der linken Matrix, die mit dieser Spalte multipliziert werden soll
      U element(0);
      for (size_t i = 0; i < b.zeilen; i++) {   //Durchführung der Multiplikation von Zeile x Spalte
        element += b.at(i, spalte) * a.at(zeile, i);
      }
      result->at(zeile, spalte) = element;
    }
  }
  return result;   //result muss außerhalb mit delete gelöscht werden
}



// Globale Funktion zur Ausgabe
template <typename T> void printArray(const Array2d<T> &a) {
  for (size_t z = 0; z < a.getZeilen(); ++z) {
    for (size_t s = 0; s < a.getSpalten(); ++s) {
      std::cout << a.at(z, s) << " ";
    }
    std::cout << std::endl;
  }
}
#endif
