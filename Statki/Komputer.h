#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "Statek.h"
#include "Gracz.h" 
#include "Plansza.h"
#include "Pole.h"

class Komputer {
private:
    Plansza plansza;
    vector<Statek*> flota;

public:
    Komputer();
    ~Komputer();

    bool ustawStatek(int x, int y, Statek* statek, bool pionowo);
    bool czyKoniecGry() const;

    void losowyStrzal(Gracz& gracz);

    void wyswietlPlansze(bool pokazStatki) const;

    void zapiszPlanszeDoPliku(const string& nazwaPliku) const;
}
