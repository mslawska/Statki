#pragma once

#include "Plansza.h"
#include "Pole.h"
#include "Komputer.h"
#include "Gracz.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
class Statek {
protected:
    int rozmiar;
    int trafionePola;

public:
    Statek(int rozmiar) : rozmiar(rozmiar), trafionePola(0) {}
};

virtual void traf();
virtual ~Statek();