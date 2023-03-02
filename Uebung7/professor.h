#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include <string>

class Professor : public Person {

    public:
        Professor(std::string firstname, std::string lastname, std::string subject) : Person(firstname, lastname), subject(subject) {}
        const std::string& getSubject() const { return subject; }
        virtual std::string toString() const override { return "Professor {" + Person::toString() + ", " + "subject: " + subject + "}"; }

    private:
        std::string subject;

};

#endif