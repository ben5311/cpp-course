#include <iostream>
#include "meinstring.cpp"
using namespace std;

int main() {
   MeinString einString("Hallo");
   cout << einString << endl;
 
   // Zuweisen
   MeinString zweiterString;
   zweiterString.reserve(20);
   zweiterString = einString;
   cout << "zugewiesener String: ";
   cout << zweiterString << endl;
 
   cout << "zweiterString.length() : "   << zweiterString.length()   << endl;
   cout << "zweiterString.capacity() : " << zweiterString.capacity() << endl;
   cout << "nach shrink_to_fit(): " << endl;
   zweiterString.shrink_to_fit();
   cout << "zweiterString.length() : " << zweiterString.length() << endl;
   cout << "zweiterString.capacity() : " << zweiterString.capacity() << endl << endl;

   cout << "zweiterString[1] : " << zweiterString[1] << endl << endl;

   cout << "zweiterString + \" Welt\" : " << (zweiterString + " Welt") << endl;
   cout << "zweiterString += \" Welt\";" << endl;
   zweiterString += " Welt";
   cout << "zweiterString: " << zweiterString << endl;
}