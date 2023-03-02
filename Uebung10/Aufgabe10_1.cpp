#include "MyQueueInt.h"
#include <iostream>
using namespace std;

int main() {
    MyQueueInt queue = { 101, 500, 66, 990, 2 };
    cout << queue << endl;
    cout << "adding 1 and 9" << endl;
    queue.push_back(1).push_back(9);
    cout << queue << endl;
    cout << "removing front element: " << queue.pop_front() << endl;
    cout << queue << endl;
}