#include <string>
#include <iostream>

class Taschenrechner {

    public:
        Taschenrechner(std::string input) : input(input) {}
        std::string getAnfrage() const { return input; }
        int getErgebnis() { return calculate(); }
    private:
        const std::string input;
        size_t index = 0;
        bool zeichenVerfuegbar() const;
        char peekZeichen() const;
        char leseZeichen();
        int leseZahl();
        int leseFaktor();
        int leseSummand();
        int leseAusdruck();
        int calculate();

};