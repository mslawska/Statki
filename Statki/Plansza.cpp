#include "Plansza.h"

void Plansza::Plansza() {
    {
        for (int i = 0; i < ROZMIAR; ++i) {
            vector<Pole> wiersz(ROZMIAR);
            pola.push_back(wiersz);
        }
    }

    int rozmiar() const {
        return ROZMIAR;
    }

    Pole& operator()(int x, int y) {
        return pola[x][y];
    }

    const Pole& operator()(int x, int y) const {
        return pola[x][y];
    }
}

void Plansza::wyswietl() {
    cout << "  ";
    for (int i = 0; i < ROZMIAR; ++i) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < ROZMIAR; ++i) {
        cout << i << " ";
        for (int j = 0; j < ROZMIAR; ++j) {
            if (pola[i][j].czyTrafiony()) {
                if (pola[i][j].czyMaStatek()) {
                    cout << "X ";
                }
                else {
                    cout << "O ";
                }
            }
            else {
                if (pokazStatki && pola[i][j].czyMaStatek()) {
                    cout << "# ";
                }
                else {
                    cout << "~ ";
                }
            }
        }
        cout << endl;
    }
}


