#pragma once
#include "Statek.h"
#include "Plansza.h"
#include "Pole.h"
#include "Komputer.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
// Klasa reprezentuj¹ca statek typu "Czteromasztowiec"
class Czteromasztowiec : public Statek {
public:
    Czteromasztowiec() : Statek(4) {}

    char getSymbol() const override {
        return 'C';
    }
};

// Klasa reprezentuj¹ca statek typu "Trójmasztowiec"
class Trojmasztowiec : public Statek {
public:
    Trojmasztowiec() : Statek(3) {}

    char getSymbol() const override {
        return 'T';
    }
};

// Klasa reprezentuj¹ca statek typu "Dwumasztowiec"
class Dwumasztowiec : public Statek {
public:
    Dwumasztowiec() : Statek(2) {}

    char getSymbol() const override {
        return 'D';
    }
};

// Klasa reprezentuj¹ca statek typu "Jednomasztowiec"
class Jednomasztowiec : public Statek {
public:
    Jednomasztowiec() : Statek(1) {}

    char getSymbol() const override {
        return 'J';
    }
};

class Gracz {
private:
    Plansza plansza;
    vector<Statek*> flota;

public:
    Gracz();
    ~Gracz();


    bool ustawStatek(int x, int y, Statek* statek, bool pionowo);
    bool czyKoniecGry() const;
     

    void strzel(int x, int y, Gracz& przeciwnik);

    

    void pozycjaStatku(const Statek& statek, int& x, int& y) const {
        for (int i = 0; i < plansza.rozmiar(); ++i) {
            for (int j = 0; j < plansza.rozmiar(); ++j) {
                if (&plansza(i, j) == &statek) {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }

    void wyswietlPlansze(bool pokazStatki) const;

    void zapiszPlanszeDoPliku(const string& nazwaPliku) const;