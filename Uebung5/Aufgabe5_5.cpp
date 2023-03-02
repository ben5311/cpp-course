#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {

    for (int i = 1; i < argc; i++) {
        fstream fs(argv[i], ios_base::in);
        if (!fs) {
            cout << "Datei " << argv[i] << " nicht gefunden!" << endl;
        } else {
            while (fs.peek() != EOF) {
                cout << (unsigned char) fs.get();
            }
            cout << endl;
        }
        fs.close();
    }

}