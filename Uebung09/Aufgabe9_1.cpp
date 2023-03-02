#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <cctype>
using namespace std;

bool isLetter(unsigned char c);
string *readName(ifstream& is);

int main(int argc, char* argv[]) {

    if (argc != 2) { 
        cout << "Error: Pass file path as arguments" << endl; 
        return -1;
    }

    //read file and count the names
    char* filename = argv[1];
    map<string, size_t> nameCounts;
    ifstream is(filename);
    if (!is) {
        cout << "Could not open file " << filename << endl;
        return -1;
    } 
    string* nextName;
        while ((nextName = readName(is)) != nullptr) {
            if (nameCounts.find(*nextName) == nameCounts.end()) {   //nameCounts does not contain this name yet
                nameCounts[*nextName] = 0;
            }
            nameCounts.at(*nextName)++;
            delete nextName;
        }
    is.close();

    //print name counts
    cout << "File \"" << filename << "\" contains these names:" << endl;
    for (map<string, size_t>::const_iterator it = nameCounts.cbegin(); it != nameCounts.cend(); it++) {
        pair<string, size_t> pair = *it;
        cout << pair.first << ": " << pair.second << endl;
    }

}

/**
 * @brief Reads next name from ifstream
 * 
 * @param is input filestream 
 * @return string* to the name or nullptr if there is no next name
 */
string *readName(ifstream& is) {
    while (is.peek() != EOF) {
        unsigned char nextChar = is.get();
        if (isLetter(nextChar)) {
            string* name = new string;
            name->push_back(nextChar);
            while (isLetter(is.peek()) || isdigit(is.peek())) {
                name->push_back((unsigned char) is.get());
            }
            return name;
        }
    }
    return nullptr;
}

bool isLetter(unsigned char c) {
    return isalpha(c) || c == '_';
}