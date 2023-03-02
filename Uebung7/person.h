#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {

    public:
        virtual ~Person() {}
        virtual const std::string& getFirstname() const { return firstname; }
        virtual const std::string& getLastname() const { return lastname; }
        virtual std::string toString() const { return "name: "+firstname+" "+lastname; }

    protected:
        Person(std::string firstname, std::string lastname) : firstname(firstname), lastname(lastname) {}
        std::string firstname;
        std::string lastname;

};

#endif