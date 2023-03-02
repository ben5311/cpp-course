#ifndef INT_MENGE_H
#define INT_MENGE_H
#include <vector>
#include <string>

class IntMenge {

    public:
        IntMenge() {}
        IntMenge(const IntMenge& intMenge);

        void hinzufuegen(int el);
        void entfernen(int el);
        bool istMitglied(int el) const;
        size_t size() const;
        void anzeigen() const;
        void loeschen();
        int getMax() const;
        int getMin() const;

    private:
        std::vector<int> menge;
        
};

inline IntMenge::IntMenge(const IntMenge& intMenge) {
    for (size_t i = 0; i < intMenge.size(); i++) {
        this->menge.push_back(intMenge.menge.at(i));
    }
}

#endif