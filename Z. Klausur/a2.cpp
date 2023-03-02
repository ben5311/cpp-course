// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#include "ident.h"
#include "a2_ticker.h"
#include <cassert>
#include <vector>

using std::vector;

int main() {
    check_ident();

    cout << "A2: Ticker" << endl;

    //!!!
    //!!! A2.(a) Testen von random_range()
    //!!!

    // Ausgabe in der Form: "{ 4.52 4.94 2.09 2.2 3.04 4.09 4.05 3.2 2.85 4.46 }"
    cout << endl << "FALL 1 random_range (2.00..5.00)" << endl << "  { ";
    //!!! A2.(a) Test random_range
    for (int i = 0; i < 10; ++i)
        cout << random_range(2, 5, 100) << " ";
    cout << "}" << endl;

    // Ausgabe in der Form: "{ -0.4 -0.8 -1 1 -1 -0.5 0.6 -0.6 -0.6 0 }"
    cout << endl << "FALL 2 random_range (-1.0..1.0)" << endl << "  { ";
    //!!! A2.(a) Test random_range
    for (int i = 0; i < 10; ++i)
        cout << random_range(-1, 1, 10) << " ";
    cout << "}" << endl;


    //!!!
    //!!! A2.(b),(c) Test von Ticker: Erzeugung des Objektes
    //!!!

    cout << endl << "FALL 3 Ticker" << endl;
    vector<double> values;          // speichere Werte in jedem Tick hier
    //!!! A2.(b),(c) Ticker
    Ticker ticker;
    ticker.attach( [&values] () {
        double value = random_range(2, 5, 100);
        cout << value << " " << flush;
        values.push_back(value);
    });

    //!!! A2.(d) -> wird nicht getestet.

    //!!!
    //!!! A2.(e),(f),(g) Testen von Ticker: running, start, stop
    //!!!

    // zunächst sollte der Ticker nicht laufen und es
    // dürfen keine Werte generiert werden
    assert(!ticker.running() && values.empty());

    // Jetzt werden Werte produziert...
    // Bei 5,5s wird die callback-Funktion insgesamt 6 mal aufgerufen.
    // Das stop() sollte blocking sein und daher läuft der Ticker
    // danach nicht mehr.
    cout << "  starte Ticker, warte 5,5s und sammle solange Werte..." << endl;
    cout << "  { ";
    ticker.start();
    sleep_for(milliseconds(5500));
    assert(ticker.running());
    ticker.stop();
    cout << "}" << endl;

    // Warte noch eine Sekunde um zu sehen ob
    // wirklich keine neuen Aufrufe stattfinden
    sleep_for(milliseconds(1000));
    assert(!ticker.running() && values.size() == 6);

    return EXIT_SUCCESS;
}

