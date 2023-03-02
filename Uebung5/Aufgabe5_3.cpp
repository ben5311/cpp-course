#include "List.cpp"
#include <iostream>
#include <functional>
using namespace std;

int main(void) {

  Element<int> * head = NULL;
  //normal sorting; funktioniert!
  insert(head, 2);
  insert(head, 5);
  insert(head, 1);
  print(head);
  remove(head, 2);
  print(head);
  cout << endl;

  Element<int> * head2 = NULL;
  std::function<int(const int&, const int&)> comp = [](const int &a, const int &b) -> int { 
    if (a > b) return -1;
    if (a == b) return 0;
    else return 1;
   };   //reverse sorting;
  insert(head2, 2, comp);
  insert(head2, 5, comp);
  insert(head2, 1, comp);
  print(head2);
  remove(head2, 2);
  print(head2);
}