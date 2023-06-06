#include "Statek.h"
void Statek::Statek() {
    

        int getRozmiar() const {
            return rozmiar;
        }
    

    bool czyZatopiony() const {
        return trafionePola == rozmiar;
    }

    virtual char getSymbol() const = 0;

 
}
void Statek::traf() {
    trafionePola++;
}
