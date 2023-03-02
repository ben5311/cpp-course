#ifndef MEINE_KLASSE_H
#define MEINE_KLASSE_H

class MeineKlasse {
    public:
        const int& readonlyAttribut;
        MeineKlasse(int number = 0): readonlyAttribut(attribut), attribut(number) {}
        void aendern(int number) { attribut = number; }

    private:
        int attribut;
};

#endif