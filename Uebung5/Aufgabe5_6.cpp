#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

bool isBuchstabe(char c) {
    return isalpha(c) || c == '_';
}

int main(int argc, char* args[]) {
    if (argc != 2) {
        cout << "Dateinamen als Argument angeben!" << endl;
        return 0;
    }
    fstream fs(args[1], ios_base::in);
    if (!fs) {
            cout << "Datei " << args[1] << " nicht gefunden!" << endl;
    } else {
        while (fs.peek() != EOF) {
            unsigned char next = fs.get();
            if (isBuchstabe(next)) {    //possible name candidate
                string name;
                name.push_back(next);
                while (fs.peek() != EOF && (isBuchstabe(fs.peek()) || isdigit(fs.peek())) ) {
                    name.push_back(fs.get());
                }
                cout << name << endl;
            }
        }
    }

    fs.close();

}