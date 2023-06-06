
#pragma once
#include "Statek.h"
#include "Pole.h"
#include "Komputer.h"
#include "Gracz.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
class Plansza {
private:
    static const int ROZMIAR = 10;
    vector<vector<Pole>> pola;

public:
    Plansza() {
        void wyswietl(bool pokazStatki);
    }
}