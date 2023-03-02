#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T>
string getType(T t) {
    string type = typeid(t).name();
    return type;
}

int main() {
    // Ausgabe
    int i =  1;
    cout << getType(i) << endl; // int
    unsigned int ui;
    cout << getType(ui) << endl; // unsigned int
    char c;
    cout << getType(c) << endl; // char
    bool b;
    cout << getType(b) << endl; // bool
    // Annahme: float ist nicht in getType() berücksichtigt:
    float f;
    cout << getType(f) << endl; // unbekannter Typ!
}