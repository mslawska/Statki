// Statki.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Statek.h"
#include "Plansza.h"
#include "Komputer.h"
#include "Gracz.h"
#include "Pole.h"
using namespace std;

// Funkcja pomocnicza do odczytu liczby z konsoli
int wczytajLiczbe() {
    int liczba;
    cin >> liczba;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return liczba;
}

// Funkcja pomocnicza do odczytu wartości logicznej (tak/nie) z konsoli
bool wczytajTakNie() {
    string odpowiedz;
    getline(cin, odpowiedz);

    return (odpowiedz == "tak" || odpowiedz == "Tak" || odpowiedz == "TAK");
}

int main() {
    Gracz gracz;
    Komputer komputer;

    cout << "Witaj w grze w statki!" << endl;

    cout << "Gracz: Ustaw swoje statki." << endl;
    for (const Statek* statek : gracz.flota) {
        int rozmiar = statek->getRozmiar();
        cout << "Ustawianie statku o rozmiarze " << rozmiar << endl;
        cout << "Podaj współrzędne początku statku (x, y): ";
        int x = wczytajLiczbe();
        int y = wczytajLiczbe();
        cout << "Czy chcesz ustawić statek pionowo? (tak/nie): ";
        bool pionowo = wczytajTakNie();

        bool ustawiony = gracz.ustawStatek(x, y, statek, pionowo);
        while (!ustawiony) {
            cout << "Nie można ustawić statku w tym miejscu. Spróbuj ponownie." << endl;
            cout << "Podaj współrzędne początku statku (x, y): ";
            x = wczytajLiczbe();
            y = wczytajLiczbe();
            cout << "Czy chcesz ustawić statek pionowo? (tak/nie): ";
            pionowo = wczytajTakNie();
            ustawiony = gracz.ustawStatek(x, y, statek, pionowo);
        }

        cout << "Twoja plansza:" << endl;
        gracz.wyswietlPlansze(true);
    }

    cout << "Komputer ustawił swoje statki." << endl;

    while (true) {
        cout << "Twoja plansza:" << endl;
        gracz.wyswietlPlansze(false);

        cout << "Plansza komputera:" << endl;
        komputer.wyswietlPlansze(false);

        cout << "Podaj współrzędne strzału (x, y): ";
        int x = wczytajLiczbe();
        int y = wczytajLiczbe();

        gracz.strzel(x, y, komputer);

        if (gracz.czyKoniecGry() || komputer.czyKoniecGry()) {
            break;
        }

        komputer.losowyStrzal(gracz);

        if (gracz.czyKoniecGry() || komputer.czyKoniecGry()) {
            break;
        }
    }

    cout << "Koniec gry!" << endl;

    cout << "Twoja plansza:" << endl;
    gracz.wyswietlPlansze(true);

    cout << "Plansza komputera:" << endl;
    komputer.wyswietlPlansze(true);

    cout << "Czy chcesz zapisać planszę do pliku? (tak/nie): ";
    bool zapisac = wczytajTakNie();
    if (zapisac) {
        cout << "Podaj nazwę pliku: ";
        string nazwaPliku;
        getline(cin, nazwaPliku);

        gracz.zapiszPlanszeDoPliku("plansza_gracza.txt");
        komputer.zapiszPlanszeDoPliku("plansza_komputera.txt");

        cout << "Zapisano plansze do plików: plansza_gracza.txt i plansza_komputera.txt" << endl;
    }

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
