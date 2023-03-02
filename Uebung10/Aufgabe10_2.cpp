#include "MyQueueInt.h"
#include <iostream>
using namespace std;

int main() {
    MyQueueInt Q { 1, 2, 3, 4, 5 };
    for (auto elem : Q) {
        std::cout << elem << std::endl;
    } 
}