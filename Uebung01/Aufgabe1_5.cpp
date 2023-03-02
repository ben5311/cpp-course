#include <iostream>
#include <string>
using namespace std;

string intToBinaryString(int number) {
    string result("");
    int comparator;
    for (int i = 31; i >= 0; i--) {
        comparator = 1 << i;
        if ((comparator & number) == comparator) { 
            result += "1";
        } else {
            result += "0";
        }
    }
    return result;
}

int main() {
    cout << "Zahl eingeben: " << endl;
    int number;
    cin >> number;
    cout << intToBinaryString(number) << endl;
    return 0;
}

