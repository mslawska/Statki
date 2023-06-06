#include "Gracz.h"
void Gracz::Gracz() {
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
}

void Gracz::~Gracz() {
    for (Statek* statek : flota) {
        delete statek;
    }
}

bool Gracz::ustawStatek()
{
    {
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
}

bool Gracz::czyKoniecGry() {
       for (const Statek* statek : flota) {
        if (!statek->czyZatopiony()) {
            return false;
        }
    }

    return true;
}

void Gracz::strzel() {
    Pole& pole = przeciwnik.plansza(x, y);
    if (pole.czyTrafiony()) {
        cout << "Ju¿ strzela³eœ w to pole!" << endl;
    }
    else {
        pole.strzel();
        if (pole.czyMaStatek()) {
            cout << "Trafiony!" << endl;
            pole.ustawTrafiony();
            for (Statek* statek : przeciwnik.flota) {
                if (statek->czyZatopiony()) {
                    continue;
                }
                int rozmiar = statek->getRozmiar();
                bool zatopiony = true;
                for (int i = 0; i < rozmiar; ++i) {
                    int xStatek, yStatek;
                    przeciwnik.pozycjaStatku(*statek, xStatek, yStatek);
                    if (!przeciwnik.plansza(xStatek, yStatek).czyTrafiony()) {
                        zatopiony = false;
                        break;
                    }
                }
                if (zatopiony) {
                    statek->traf();
                    cout << "Zatopi³eœ statek!" << endl;
                }
            }
        }
        else {
            cout << "Pud³o!" << endl;
        }
    }
}

void Gracz::wyswietlPlansze() {
    plansza.wyswietl(pokazStatki);
}

void Gracz::zapiszPlanszeDoPlik() {
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

