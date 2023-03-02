#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct Element {
  T value;
  Element<T> *next;
  Element(T v, Element<T>* n): value(v), next(n) { }
};

template <typename T>
void insert(Element<T> *&rp, T v, std::function<int(const T&, const T&)> comp = [](const T &a, const T &b) -> int { return a > b ? 1 : -1; } ) {
  if (rp != NULL) {
    if (comp(v, rp->value) > 0)     // Sortieren
      insert(rp->next, v, comp); // Rekursion
    else
      rp = new Element<T>(v, rp);
  }
  else {
    rp = new Element<T>(v, NULL);
  }
}

template <typename T>
void remove(Element<T> *&rp, T v) {
  if (rp != NULL) {
    if (rp->value == v) {
      Element<T> *tmp = rp;
      rp = rp->next;
      delete tmp;
      remove(rp, v);
    }
    else
      remove(rp->next, v); // Rekursion
  }
}

template <typename T>
void print(Element<T> *p) {
  while (p) {
    std::cout << p->value << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

