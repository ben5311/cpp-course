#include "student.h"
#include "professor.h"
#include "person.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<Person *> personen;
    personen.push_back(new Student("Risse", "Felicitas" , "635374"));
    personen.push_back(new Professor("Philippsen", "Nele", "Datenbanken"));
    personen.push_back(new Student("Spillner", "Julian", "123429"));
    cout << "getFirstname():" << endl;
    for(Person* person : personen) {
        cout << person->getFirstname() << endl;
    }
    cout << endl << "toString():" << endl;
    for(Person* person : personen) {
        cout << person->toString() << endl;
    }
    for(Person* person : personen) {
        delete person;
    }
    
}