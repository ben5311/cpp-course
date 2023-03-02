// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#include "ident.h"
#include "a1_named_sensor_manager.h"
#include <cassert>

int main() {
    check_ident();

    cout << "A1: NamedSensor und SensorManager" << endl << endl;

    //!!!
    //!!! Teste NamedSensor A1.(a) A1.(b)
    //!!!
    NamedSensor * i1 = new NamedSensor("Sensor1");
    NamedSensor * i2 = new NamedSensor("Sensor2");
    NamedSensor * i3 = new NamedSensor("Sensor3");

    cout << "   " << i1->getName() << endl;
    assert(i1->getName() == "Sensor1");
    cout << "   " << i2->getName() << endl;
    assert(i2->getName() == "Sensor2");
    cout << "   " << i3->getName() << endl;
    assert(i3->getName() == "Sensor3");

    //!!!
    //!!! Teste SensorManager: Konstruktor A1.(c)-A1.(f)
    //!!!
    SensorManager empty;
    SensorManager manager( { i1, i2, i3 } );
    
    //!!!
    //!!! Teste SensorManager: Ausgabeoperator A1.(g)
    //!!!
    cout << endl << "Ausgabeoperator:" << endl 
         << "  " << manager << endl;

    //!!!
    //!!! Teste SensorManager: Index-Operator A1.(h)
    //!!!
    assert( manager["Sensor1"] == i1 );      // existiert!
    assert( manager["Sensor2"] == i2 );      // existiert!
    assert( manager["Sensor3"] == i3 );      // existiert!
    assert( manager["xxxxxxx"] == nullptr ); // xxxxxxx existiert nicht!

    return EXIT_SUCCESS;
}

