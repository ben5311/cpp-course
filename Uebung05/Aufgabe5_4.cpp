#include <iostream>
using namespace std;

void removeChar(char* s) {
    while (*s) {
        *s = *(s+1);
        s++;
    }
}

void leerzeichenEntfernen(char* s) {
    char* ptr = s;
    while (*ptr) {
        if (*ptr == ' ') {
            removeChar(ptr);
        } else {
            ptr++;
        }
    }
}

int main() {
    char s[] = "The  quick brown  fox jumps    over the  lazy dog.";
    cout << s << endl;
    leerzeichenEntfernen(s);
    cout << s << endl;
}