// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#ifndef A1_NAMED_SENSOR_MANAGER_H
#define A1_NAMED_SENSOR_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

class SensorListener;

class NamedSensor {
    //!!! A1.(a) Attribut name_

    //!!! A1.(a) getName()
    
    //!!! A1.(b) ctor mit name_
    public:
        NamedSensor(string name): name_(name) {}
        virtual ~NamedSensor() {}

        virtual void subscribe(SensorListener & sl) {
            (void)(sl); // Dummy zur Vermeidung von Warnings
        };

        virtual void unsubscribe(SensorListener & sl) {
            (void)(sl); // Dummy zur Vermeidung von Warnings
        };
        
        virtual bool active() const {
            return false;
        };
        virtual const string& getName() const { return name_; }

    private:
        string name_;
};


class SensorManager {

    public:
        typedef NamedSensor* elem_t;
        vector<elem_t> sensors_;
        SensorManager() {}
        SensorManager(initializer_list<elem_t> elements) {
            for (elem_t element : elements) {
                sensors_.push_back(element);
            }
        }
        virtual ~SensorManager() {
            for (elem_t sensor : sensors_) {
                delete sensor;
            }
            sensors_.clear();
        }
        elem_t operator[](string name) {
            for (elem_t sensor : sensors_) {
                if (sensor->getName() == name) {
                    return sensor;
                }
            }
            return nullptr;
        }
    private:

    //!!! A1.(c) Datentyp elem_t (Zeiger auf NamedSensor)
       
    //!!! A1.(d) Vektor sensors_

    //!!! A1.(e) Konstruktoren, die Aufruf in main realisieren

    //!!! A1.(f) Destruktor, Freigabe der Elemente

    //!!! A1.(g) Ausgabeoperator, Form: "{ 'obj1', 'obj2' }"
    //!!! Hinweis: Operator muss nicht unbedingt an dieser Stelle implementiert werden
    
    //!!! A1.(h) Index-Operator

};

std::ostream& operator<<(std::ostream& os, const SensorManager& manager) {
    os << "{ ";
    for (SensorManager::elem_t sensor : manager.sensors_) {
        os << "'" << sensor->getName() << "' ";
    }
    os << "}";
    return os;
}

#endif

