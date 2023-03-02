// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#ifndef A3_SENSORS_H
#define A3_SENSORS_H

#include "a1_named_sensor_manager.h"
#include "a2_ticker.h"

#include <iostream>
#include <string>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::set;


//----- die Klasse Sensor implementiert die Listener-Idee
class Sensor;

//----- die Datenklasse SensorEvent kann so bleiben -----

struct SensorEvent {
    Sensor * sensor;
    double   value;
};

//----- im SensorListener muss on_event angepasst werden
struct SensorListener {
    //!!! A3.(a) rein-virtual
    virtual void on_event(const SensorEvent &event) = 0;
};


//!!! A3.(b) von NamedSensor und Ticker erben
class Sensor: public NamedSensor, public Ticker {
    // Liste aller registrierten Listener
    set<SensorListener *> listener_;

public:
    //!!! A3.(b) Konstruktor, Name an Named weitergeben
    Sensor(string name) : NamedSensor(name), Ticker() {}
    //----- Methode zum Benachrichtigen aller Listener,
    //----- ist bereits fertig implementiert!
    void fire_event(const SensorEvent &event) const {
        for (auto & listener : listener_)
            listener->on_event(event);
    }

    //!!! A3.(c) subscribe, automatischer Start
    virtual void subscribe(SensorListener& listener) override {
        if (listener_.size() == 0) {
            listener_.insert(&listener);
            start();
        } else {
            listener_.insert(&listener);
        }
        
    }

    //!!! A3.(d) unsubscribe, automatischer Stop
    virtual void unsubscribe(SensorListener& listener) override {
        listener_.erase(&listener);
        if (listener_.size() == 0) {
            stop();
        }
    }

    //!!! A3.(e) active und Änderungen in NamedSensor
    virtual bool active() const override { 
        return running();
    }

};

//----- die Klasse TemperatureSensor simuliert einen
//----- Temperatur-Sensor, der regelmäßig die Temperatur
//----- ausliest und an alle Listener sendet (erbt
//----- das Verhalten von Sensor)

//!!! A3.(f) von Sensor erben
class TemperatureSensor: public Sensor {

public:
    //!!! A3.(f,g) Konstruktor, Setzen der Ticker-Methode
    TemperatureSensor(string name, long long interval_ms): Sensor(name) { 
        auto func = [this]() {
            double temperature_value = random_range(18, 23, 100);
            SensorEvent event;
            event.sensor = this;
            event.value = temperature_value;
            this->fire_event(event);
        };
        attach(func, interval_ms);
    }
};

//----- Die Klasse Component realisiert einen
//----- Konsumenten für die Sensordaten

//!!! A3.(h) SensorListener "implementieren"
struct Component: public SensorListener {
    Component(const string& name) : name{name}, events{0} {}

    const string name;
    unsigned int events;
    
    virtual void on_event(const SensorEvent &event) override {
        ++events;
        cout << "('" << name 
             << "', Event Nr. " << events << ", " 
             << event.sensor->getName() << ": " << event.value << " °C) " 
             << endl;
    }
};

#endif
