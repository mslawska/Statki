#include "Komupter.h"

void Komputer::Komputer() {
    flota.push_back(new Czteromasztowiec());
    flota.push_back(new Trojmasztowiec());
    flota.push_back(new Trojmasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());

    srand(static_cast<unsigned int>(time(nullptr)));

    for (Statek* statek : flota) {
        bool ustawiony = false;
        while (!ustawiony) {
            int x = rand() % plansza.rozmiar();
            int y = rand() % plansza.rozmiar();
            bool pionowo = rand() % 2 == 0;
            ustawiony = ustawStatek(x, y, statek, pionowo);
        }
    }
}
void Komupter::~Komputer() {
    for (Statek* statek : flota) {
        delete statek;
    }
}

bool Komputer::ustawStatek() {
    int rozmiar = statek->getRozmiar();

    if (pionowo && y + rozmiar > plansza.rozmiar()) {
        return false;
    }

    if (!pionowo && x + rozmiar > plansza.rozmiar()) {
        return false;
    }

    for (int i = 0; i < rozmiar; ++i) {
        if (pionowo && plansza(x, y + i).czyMaStatek()) {
            return false;
        }

        if (!pionowo && plansza(x + i, y).czyMaStatek()) {
            return false;
        }
    }

    for (int i = 0; i < rozmiar; ++i) {
        if (pionowo) {
            plansza(x, y + i).ustawStatek();
        }
        else {
            plansza(x + i, y).ustawStatek();
        }
    }

    return true;
}

bool Komputer::czyKoniecGry() {
    for (const Statek* statek : flota) {
        if (!statek->czyZatopiony()) {
            return false;
        }
    }

    return true;
}

void Komputer::losowyStrzal() {
    int x, y;
    do {
        x = rand() % plansza.rozmiar();
        y = rand() % plansza.rozmiar();
    } while (gracz.plansza(x, y).czyTrafiony());

    cout << "Komputer strzela na pole (" << x << ", " << y << ")..." << endl;
    gracz.strzel(x, y, *this);
}

void Komputer::wyswietlPlansze() {
    plansza.wyswietl(pokazStatki);
}

void Komputer::zapiszPlanszeDoPliku() {

     ofstream plik(nazwaPliku);
        if (plik.is_open()) {
            for (int i = 0; i < plansza.rozmiar(); ++i) {
                for (int j = 0; j < plansza.rozmiar(); ++j) {
                    char symbol;
                    if (plansza(i, j).czyTrafiony()) {
                        if (plansza(i, j).czyMaStatek()) {
                            symbol = 'X';
                        }
                        else {
                            symbol = 'O';
                        }
                    }
                    else {
                        symbol = '~';
                    }
                    plik << symbol << ' ';
                }
                plik << endl;
            }
            plik.close();
        }
        else {
            cout << "B³¹d podczas zapisu do pliku." << endl;
        }
}
