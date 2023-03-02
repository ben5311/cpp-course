// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#include "ident.h"
#include "a3_sensors.h"

using std::this_thread::sleep_for;
using std::chrono::milliseconds;

int main() {
    check_ident();

    cout << "A3: TemperatureSensor Simulation" << endl;

    const string WOHNZIMMER    = "Wohnzimmer";
    const string ARBEITSZIMMER = "Arbeitszimmer";

    //!!!
    //!!! A3.(a)-(h) Finaler Test
    //!!!

    // Teste Sensormanager
    SensorManager manager (
        { new TemperatureSensor(WOHNZIMMER,   1000), 
          new TemperatureSensor(ARBEITSZIMMER, 500) }
    );

    NamedSensor & Wohnzimmer    = *manager[WOHNZIMMER];
    NamedSensor & Arbeitszimmer = *manager[ARBEITSZIMMER];

    // NUR bei Problemen mit dem Sensormanager:
    // TemperatureSensor Wohnzimmer(WOHNZIMMER,   1000);
    // TemperatureSensor Arbeitszimmer(ARBEITSZIMMER, 500);
    
    // Teste Component    
    Component Zentrale{"Zentrale"};

    // zunächst sollten die Sensoren nicht laufen
    assert ( !Wohnzimmer.active() &&
             !Arbeitszimmer.active() &&
              Zentrale.events == 0 );

    // Teste subscribe/unsubscribe
    // Wohnzimmer registrieren, Zentrale erhält Events
    cout << endl;
    cout << "***  Wohnzimmer (Interval 1s) registriert, warte 2,1s und sammle Events..." << endl;
    Wohnzimmer.subscribe( Zentrale );
    sleep_for(milliseconds(2100));
    assert (  Wohnzimmer.active() &&
             !Arbeitszimmer.active() &&
              Zentrale.events == 3 );

    // Arbeitszimmer zusätzlich registrieren, Events von beiden Räumen
    cout << "***  Arbeitszimmer (Interval 0,5s) registriert, warte 2,1s und sammle Events..." << endl;
    Arbeitszimmer.subscribe( Zentrale );
    sleep_for(milliseconds(2100));
    assert (  Wohnzimmer.active() &&
              Arbeitszimmer.active() &&
              Zentrale.events == 3 + 7 );

    // Wohnzimmer wird deregistriert, Events nur noch vom Arbeitszimmer
    cout << "***  Wohnzimmer deregistriert, warte 2,1s und sammle Events..." << endl;
    Wohnzimmer.unsubscribe( Zentrale );
    sleep_for(milliseconds(2100));
    assert ( !Wohnzimmer.active() &&
              Arbeitszimmer.active() &&
              Zentrale.events == 10 + 5 );

    // Arbeitszimmer wird deregistriert, keine Events mehr ...
    cout << "***  Arbeitszimmer deregistriert, warte 1,1s und sammle Events..." << endl;
    Arbeitszimmer.unsubscribe( Zentrale );
    sleep_for(milliseconds(1100));
    assert ( !Wohnzimmer.active() &&
             !Arbeitszimmer.active() &&
              Zentrale.events == 10 + 5 );

    return EXIT_SUCCESS;
}
