#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#include <unordered_set>

// Die Teilnehmer Pointer in "bekannte" sind nur solange gültig, wie sie auf existierende Objekte zeigen.
// Es kann passieren, dass die dahinterstehenden Objekte von außerhalb gelöscht werden und die "bekannte" Liste dann losgelöste Pointer enthält.

class Teilnehmer {

    public:
        Teilnehmer(const char* name) : name(name) {}

        void lerntKennen(Teilnehmer& teilnehmer);
        const char* gibNamen() { return name; }
        void druckeBekannte();

    private:
        const char* name;
        std::unordered_set<Teilnehmer*> bekannte;

};

#endif