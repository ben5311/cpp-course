#include <iostream>
#include <string>
#include "IntMenge.h"
using namespace std;

void IntMenge::hinzufuegen(int el) {
    if (!istMitglied(el)) {
        menge.push_back(el);
    }
}

void IntMenge::entfernen(int el) {
    for (size_t i = 0; i < size(); i++) {
        if (menge.at(i) == el) {
            menge.erase(menge.begin() + i);
            return;
        }
    }
}

bool IntMenge::istMitglied(int el) const {
    for (size_t i = 0; i < size(); i++) {
        if (menge.at(i) == el) { return true; }
    }
    return false;
}

size_t IntMenge::size() const {
    return menge.size();
}

void IntMenge::anzeigen() const {
    cout << '{';
    for (size_t i = 0; i < size(); i++) {
        cout << menge.at(i) << (i < size()-1 ? "," : "");
    }
    cout << '}' << endl;
}

void IntMenge::loeschen() {
    menge.clear();
}

int IntMenge::getMax() const {
    int max = INT_MIN;
    for (size_t i = 0; i < size(); i++) {
        if (menge.at(i) > max) { max = menge.at(i); }
    }
    return max;
}

int IntMenge::getMin() const {
    int min = INT_MAX;
    for (size_t i = 0; i < size(); i++) {
        if (menge.at(i) < min) { min = menge.at(i); }
    }
    return min;
}