#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <cctype>
#include <algorithm>
using namespace std;
typedef map<string, size_t> Map;
typedef map<string, size_t>::const_iterator MapIterator;

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

    //sort the map entries
    vector<MapIterator> mapIterators;
    for (MapIterator it = nameCounts.cbegin(); it != nameCounts.cend(); it++) {
        mapIterators.push_back(it);
    }
    sort(mapIterators.begin(), mapIterators.end(), [](MapIterator& a, MapIterator& b) -> bool { return a->second > b->second; });

    //print name counts
    cout << "File \"" << filename << "\" contains these 20 most frequent names:" << endl;
    int i = 1;
    for (vector<MapIterator>::iterator it = mapIterators.begin(); it != mapIterators.end(); it++) {
        MapIterator mapIterator = *it;
        pair<string, size_t> pair = *mapIterator;
        cout << pair.first << ": " << pair.second << endl;
        if (i++ == 20) { break; }
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