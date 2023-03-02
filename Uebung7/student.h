#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <string>

class Student : public Person {

    public:
        Student(std::string firstname, std::string lastname, std::string matrikelnr) : Person(firstname, lastname), matrikelnr(matrikelnr) {}
        const std::string& getMatrikelNr() const { return matrikelnr; }
        virtual std::string toString() const override { return "Student {" + Person::toString() + ", " + "matrikelnr: " + matrikelnr + "}"; }

    private: 
        std::string matrikelnr;

};

#endif