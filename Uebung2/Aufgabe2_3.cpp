#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const string FILENAME = "Hallo.sec";
const string DIVIDOR = "    ";

int main() {

    ifstream ifs(FILENAME, ios_base::binary);
    cout.fill('0');
    
    if(ifs) {  
        int linenum = 1;
        unsigned char next = ifs.get();
        vector<char> chars;

        while (!ifs.eof()) {
            cout << linenum << DIVIDOR;
            for (int i = 0; i < 16 && !ifs.eof(); i++) {
                cout << std::setw(2) << std::uppercase << std::hex << (int) next << ' ';    //print char's hex representation
                chars.push_back(next);
                next = ifs.get();
            }
            cout << DIVIDOR;
            for (char c : chars) { cout << (isprint(c) ? c : '.'); }
            cout << endl;
            chars.clear();
            linenum++;
        } 

        return 0;
    } else {
        cout << "Fehler beim Einlesen der Datei " << FILENAME << endl;
        return -1;
    }
    
}