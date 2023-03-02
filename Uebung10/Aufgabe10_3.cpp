#include "MyQueue.h"
#include <iostream>
using namespace std;

int main() {
    MyQueue<string> Q { "Hallo", "Welt", "A", "B", "C" };
    for (auto elem : Q) {
        std::cout << elem << std::endl;
    }
} 
