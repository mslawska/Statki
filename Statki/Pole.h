#pragma once
#include "Statek.h"
#include "Plansza.h"
#include "Komputer.h"
#include "Gracz.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;
class Pole {
private:
    bool trafiony; // Czy pole zosta³o trafione
    bool statek; // Czy pole zawiera statek

public:
    void ustawStatek() : trafiony(false), statek(false);
    void strzel();
    void ustawTrafiony();
    bool czyTrafiony() const {
        return trafiony;
    }

    bool czyMaStatek() const {
        return statek;
    }

    
};