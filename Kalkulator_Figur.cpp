#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

void kreski() {
    cout << "==============================================\n";
}

void konwersjaJednostki(double wartosc, const string& typ, const string& aktualnaJednostka) {
    
    cout << "+------------------------------------------+\n";
    cout << "|   Czy chcesz przekonwertowaæ jednostkê?  |\n";
    cout << "+------------------------------------------+\n";
    cout << "| T - Tak                                   |\n";
    cout << "| N - Nie                                   |\n";
    cout << "+------------------------------------------+\n";
    cout << "Twój wybór: ";
    
    char decyzja;
    cin >> decyzja;

    if (decyzja != 'T' && decyzja != 't') return;

    system("cls");
    cout << "+---------------------------------+\n";
    cout << "|      Dostêpne jednostki:        |\n";
    cout << "|---------------------------------|\n";
    cout << "|  1. mm                          |\n";
    cout << "|  2. cm                          |\n";
    cout << "|  3. m                           |\n";
    cout << "|  4. km                          |\n";
    cout << "+---------------------------------+\n";
    cout << "Na jak¹ jednostkê chcesz przekonwertowaæ? ";

    string nowaJednostka;
    cin >> nowaJednostka;

    if ((nowaJednostka != "mm" && nowaJednostka != "cm" && nowaJednostka != "m" && nowaJednostka != "km") ||
        (aktualnaJednostka != "mm" && aktualnaJednostka != "cm" && aktualnaJednostka != "m" && aktualnaJednostka != "km")) {
        system("cls");
        cout << "+---------------------------+\n";
        cout << "|  Niepoprawna jednostka!   |\n";
        cout << "+---------------------------+\n";
        return;
    }

    int potega = 1;
    if (typ == "powierzchnia") potega = 2;
    else if (typ == "objêtoœæ") potega = 3;

    double wartoscWmm = wartosc;
    if (aktualnaJednostka == "cm") wartoscWmm *= pow(10, potega);
    else if (aktualnaJednostka == "m") wartoscWmm *= pow(1000, potega);
    else if (aktualnaJednostka == "km") wartoscWmm *= pow(1000000, potega);

    double mnoznik = 1.0;
    if (nowaJednostka == "cm") mnoznik = 1.0 / pow(10, potega);
    else if (nowaJednostka == "m") mnoznik = 1.0 / pow(1000, potega);
    else if (nowaJednostka == "km") mnoznik = 1.0 / pow(1000000, potega);

    double wynik = wartoscWmm * mnoznik;

    system("cls"); 
    cout << "+--------------------------------------+\n";
    cout << "|   Wynik po konwersji: ";
    cout << fixed << wynik << " " << nowaJednostka;
    if (typ == "powierzchnia") cout << "^2";
    else if (typ == "objêtoœæ") cout << "^3";
    cout << "   |\n";
    cout << "+--------------------------------------+\n";
}
bool wczytajLiczbe(int &liczba) {
    cin >> liczba;
    if (cin.fail() || liczba <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
    return true;
}

bool DalszyWybor() {
    char decyzja;
    cout << "Czy chcesz powtórzyæ obliczenia? (T lub N): ";
    cin >> decyzja;
    return decyzja == 'T' || decyzja == 't';
}
string wybierzJednostke() {
    int wybor;
    cout << "==========================" << endl;
    cout << "|   Wybierz jednostkê:   |" << endl;
    cout << "|------------------------|" << endl;
    cout << "| 1. mm                  |" << endl;
    cout << "| 2. cm                  |" << endl;
    cout << "| 3. m                   |" << endl;
    cout << "| 4. km                  |" << endl;
    cout << "==========================" << endl;
    cout << "Twój wybór: ";
    cin >> wybor;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Nieprawid³owy wybór. Ustawiono domyœlnie cm.\n";
        return "cm";
    }
    switch (wybor) {
        case 1: return "mm";
        case 2: return "cm";
        case 3: return "m";
        case 4: return "km";
        default:
            cout << "Nieprawid³owy wybór. Ustawiono domyœlnie cm.\n";
            return "cm";
    }
}
void autoKonwersjaJednostki(double &wynik, string &jednostka, const string &typ) {
    int potega = 1;
    if (typ == "powierzchnia") potega = 2;
    else if (typ == "objêtoœæ") potega = 3;

    const double przelicznik = 10.0;
    double prog = 1.0;
    for (int i = 0; i < potega; ++i)
        prog *= przelicznik;

    while (wynik >= prog) {
        if (jednostka == "mm") {
            wynik /= prog;
            jednostka = "cm";
        }
        else if (jednostka == "cm") {
            wynik /= prog;
            jednostka = "m";
        }
        else if (jednostka == "m") {
            wynik /= prog;
            jednostka = "km";
        }
        else {
            break;
        }
    }
}
void Kwadrat() {
    int rozmiar = 6;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
void Trojkat() {
    int wysokosc = 6;
    for (int i = 1; i <= wysokosc; i++) {
        for (int j = 1; j <= wysokosc - i; j++) cout << " ";
        for (int k = 1; k <= 2 * i - 1; k++) cout << "*";
        cout << endl;
    }
}
void Rownoleglobok() {
    int wysokosc = 5;
    int szerokosc = 10;
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < wysokosc - i - 1; j++) cout << " ";
        for (int j = 0; j < szerokosc; j++) cout << "*";
        cout << endl;
    }
}
void Prostokat() {
    int wysokosc = 4;
    int szerokosc = 10;
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < szerokosc; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
void Trapez() {
    int gora = 4;
    int dol = 10;
    int wysokosc = (dol - gora) / 2 + 1;
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < wysokosc - i - 1; j++) cout << " ";
        for (int j = 0; j < gora + 2 * i; j++) cout << "*";
        cout << endl;
    }
}
void Ostroslup() {
    int wysokosc = 5;
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < wysokosc - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }
}
void Prostopadloscian() {
    int szerokosc = 10;
    int wysokosc = 4;
    int glebokosc = 5;

    for (int i = 0; i < glebokosc; i++) cout << " ";
    for (int i = 0; i < szerokosc; i++) cout << "*";
    cout << endl;

    for (int i = 1; i < wysokosc; i++) {
        for (int j = 0; j < glebokosc - i; j++) cout << " ";
        cout << "*";
        for (int j = 0; j < szerokosc - 2; j++) cout << " ";
        cout << "*" << endl;
    }

    for (int i = 0; i < szerokosc; i++) cout << "*";
    cout << endl;
}
void Romb() {
    int wysokosc = 5;
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < wysokosc - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    for (int i = wysokosc - 2; i >= 0; i--) {
        for (int j = 0; j < wysokosc - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
}
void FiguryPlaskie(const string& nazwaFigury, void (*poleFunkcja)(), void (*obwodFunkcja)(), void (*nazwaFiguryG)()) {
    int wybor;
    system("cls");
    kreski();
    cout << nazwaFigury << "\n";
    kreski();
    cout << endl;
    nazwaFiguryG();
    cout << endl;
    cout <<  "Na powy¿szym rysunku, wyglad geometryczny figury" << endl;

    cout << "=====================\n";
    cout << "|     MENU FIGURY    |\n";
    cout << "=====================\n";
    cout << "| 1. Pole            |\n";
    cout << "| 2. Obwód           |\n";
    cout << "=====================\n";
    cout << "Wybierz opcjê: ";
    cin >> wybor;

    if (wybor == 1) poleFunkcja();
    else if (wybor == 2) obwodFunkcja();
    else cout << "Nieprawid³owy wybór!\n";
}
void FiguryPrzestrzenne(const string& nazwaBryly, void (*poleFunkcja)(), void (*objetoscFunkcja)(), void (*nazwaFiguryG)()) {
    int wybor;
    system("cls");
    kreski();
    cout << nazwaBryly << "\n";
    kreski();
    cout << endl;
    nazwaFiguryG();
    cout << endl;
    cout << "===========================\n";
    cout << "|     MENU BRY£Y          |\n";
    cout << "===========================\n";
    cout << "| 1. Pole ca³kowite       |\n";
    cout << "| 2. Objêtoœæ             |\n";
    cout << "===========================\n";
    cout << "Wybierz opcjê: ";
    cin >> wybor;
    if (wybor == 1) poleFunkcja();
    else if (wybor == 2) objetoscFunkcja();
    else cout << "Nieprawid³owy wybór!\n";
}
void PoleKwadratu() {
    do {
        system("cls"); kreski();
        cout << "POLE KWADRATU\n";
        string jednostka = wybierzJednostke();
        int a;
        cout << "Podaj d³ugoœæ boku (" << jednostka << "): ";
        if (!wczytajLiczbe(a)) { cout << "Niepoprawna wartoœæ!\n"; return; }
        double wynik = a * a;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole kwadratu: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObwodKwadratu() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD KWADRATU\n";
        string jednostka = wybierzJednostke();
        int a;
        cout << "Podaj d³ugoœæ boku (" << jednostka << "): ";
        if (!wczytajLiczbe(a)) { cout << "Niepoprawna wartoœæ!\n"; return; }
        double wynik = 4 * a;
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód kwadratu: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleProstokata() {
    do {
        system("cls"); kreski();
        cout << "POLE PROSTOK¥TA\n";
        string jednostka = wybierzJednostke();
        int a, b;
        cout << "Podaj d³ugoœci boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = a * b;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole prostok¹ta: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObwodProstokata() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD PROSTOK¥TA\n";
        string jednostka = wybierzJednostke();
        int a, b;
        cout << "Podaj d³ugoœci boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = 2 * (a + b);
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód prostok¹ta: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleTrojkata() {
    do {
        system("cls"); kreski();
        cout << "POLE TRÓJK¥TA\n";
        string jednostka = wybierzJednostke();
        int a, h;
        cout << "Podaj podstawê i wysokoœæ (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = 0.5 * a * h;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole trójk¹ta: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObwodTrojkata() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD TRÓJK¥TA\n";
        string jednostka = wybierzJednostke();
        int a, b, c;
        cout << "Podaj d³ugoœci trzech boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b) || !wczytajLiczbe(c)) { cout << "Niepoprawne wartoœci!\n"; return; }
        if (a + b <= c || a + c <= b || b + c <= a) { cout << "Podane boki nie tworz¹ trójk¹ta!\n"; return; }
        double wynik = a + b + c;
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód trójk¹ta: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleRownolegloboku() {
    do {
        system("cls"); kreski();
        cout << "POLE RÓWNOLEG£OBOKU\n";
        string jednostka = wybierzJednostke();
        int a, h;
        cout << "Podaj podstawê i wysokoœæ (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = a * h;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole równoleg³oboku: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObwodRownolegloboku() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD RÓWNOLEG£OBOKU\n";
        string jednostka = wybierzJednostke();
        int a, b;
        cout << "Podaj d³ugoœci dwóch s¹siednich boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = 2 * (a + b);
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód równoleg³oboku: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleRombu() {
    do {
        system("cls"); kreski();
        cout << "POLE ROMBU\n";
        string jednostka = wybierzJednostke();
        int a, h;
        cout << "Podaj bok i wysokoœæ (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = a * h;

        
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");

        kreski();
        cout << "Pole rombu: " << wynik << " " << jednostka << "^2\n";
        kreski();

        
        konwersjaJednostki(wynik, "powierzchnia", jednostka);

        kreski();
    } while (DalszyWybor());
}
void ObwodRombu() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD ROMBU\n";
        string jednostka = wybierzJednostke();
        int a;
        cout << "Podaj d³ugoœæ boku (" << jednostka << "): ";
        if (!wczytajLiczbe(a)) { cout << "Niepoprawna wartoœæ!\n"; return; }
        double wynik = 4 * a;
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód rombu: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleTrapezu() {
    do {
        system("cls"); kreski();
        cout << "POLE TRAPEZU\n";
        string jednostka = wybierzJednostke();
        int a, b, h;
        cout << "Podaj d³ugoœci podstaw (a, b) i wysokoœæ (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = ((a + b) * h) / 2.0;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole trapezu: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObwodTrapezu() {
    do {
        system("cls"); kreski();
        cout << "OBWÓD TRAPEZU\n";
        string jednostka = wybierzJednostke();
        int a, b, c, d;
        cout << "Podaj d³ugoœci czterech boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b) || !wczytajLiczbe(c) || !wczytajLiczbe(d)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = a + b + c + d;
        autoKonwersjaJednostki(wynik, jednostka, "d³ugoœæ");
        kreski();
        cout << "Obwód trapezu: " << wynik << " " << jednostka << "\n";
        kreski();
        konwersjaJednostki(wynik, "d³ugoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleOstroslupa() {
    do {
        system("cls"); kreski();
        cout << "POLE OSTROS£UPA\n";
        string jednostka = wybierzJednostke();
        int Pp, Pb;
        cout << "Podaj pole podstawy i pole boczne (" << jednostka << "): ";
        if (!wczytajLiczbe(Pp) || !wczytajLiczbe(Pb)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = Pp + Pb;
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole ca³kowite ostros³upa: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObjetoscOstroslupa() {
    do {
        system("cls"); kreski();
        cout << "OBJÊTOŒÆ OSTROS£UPA\n";
        string jednostka = wybierzJednostke();
        int P, h;
        cout << "Podaj pole podstawy i wysokoœæ (" << jednostka << "): ";
        if (!wczytajLiczbe(P) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = (P * h) / 3.0;
        autoKonwersjaJednostki(wynik, jednostka, "objêtoœæ");
        kreski();
        cout << "Objêtoœæ ostros³upa: " << wynik << " " << jednostka << "^3\n";
        kreski();
        konwersjaJednostki(wynik, "objêtoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void PoleProstopadloscianu() {
    do {
        system("cls"); kreski();
        cout << "POLE PROSTOPAD£OŒCIANU\n";
        string jednostka = wybierzJednostke();
        int a, b, h;
        cout << "Podaj d³ugoœci trzech boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = 2 * (a * b + b * h + a * h);
        autoKonwersjaJednostki(wynik, jednostka, "powierzchnia");
        kreski();
        cout << "Pole powierzchni: " << wynik << " " << jednostka << "^2\n";
        kreski();
        konwersjaJednostki(wynik, "powierzchnia", jednostka);
        kreski();
    } while (DalszyWybor());
}
void ObjetoscProstopadloscianu() {
    do {
        system("cls"); kreski();
        cout << "OBJÊTOŒÆ PROSTOPAD£OŒCIANU\n";
        string jednostka = wybierzJednostke();
        int a, b, h;
        cout << "Podaj d³ugoœci trzech boków (" << jednostka << "): ";
        if (!wczytajLiczbe(a) || !wczytajLiczbe(b) || !wczytajLiczbe(h)) { cout << "Niepoprawne wartoœci!\n"; return; }
        double wynik = a * b * h;
        autoKonwersjaJednostki(wynik, jednostka, "objêtoœæ");
        kreski();
        cout << "Objêtoœæ: " << wynik << " " << jednostka << "^3\n";
        kreski();
        konwersjaJednostki(wynik, "objêtoœæ", jednostka);
        kreski();
    } while (DalszyWybor());
}
void menu() {
    while (true) {
        system("cls"); kreski();
        cout << "KALKULATOR GEOMETRYCZNY\n";
        kreski();
        cout << "1. Kwadrat\n";
        cout << "2. Prostok¹t\n";
        cout << "3. Trójk¹t\n";
        cout << "4. Równoleg³obok\n";
        cout << "5. Romb\n";
        cout << "6. Ostros³up\n";
        cout << "7. Prostopad³oœcian\n";
        cout << "8. Trapez\n";
        cout << "0. Wyjœcie\n";
        kreski();

        char wybor;
        cout << "Wybierz figurê (0-8): ";
        cin >> wybor;

        switch (wybor) {
            case '1': FiguryPlaskie("KWADRAT", PoleKwadratu, ObwodKwadratu, Kwadrat); break;
            case '2': FiguryPlaskie("PROSTOK¥T", PoleProstokata, ObwodProstokata,Prostokat); break;
            case '3': FiguryPlaskie("TRÓJK¥T", PoleTrojkata, ObwodTrojkata,Trojkat); break;
            case '4': FiguryPlaskie("RÓWNOLEG£OBOK", PoleRownolegloboku, ObwodRownolegloboku,Rownoleglobok); break;
            case '5': FiguryPlaskie("ROMB", PoleRombu, ObwodRombu,Romb); break;
            case '6': FiguryPrzestrzenne("OSTROS£UP", PoleOstroslupa, ObjetoscOstroslupa,Ostroslup); break;
            case '7': FiguryPrzestrzenne("PROSTOPAD£OŒCIAN", PoleProstopadloscianu, ObjetoscProstopadloscianu,Prostopadloscian); break;
            case '8': FiguryPlaskie("TRAPEZ", PoleTrapezu, ObwodTrapezu,Trapez); break;
            case '0': cout << "Do widzenia!\n"; return;
            default: cout << "Nieprawid³owy wybór! Naciœnij Enter..."; cin.ignore(); cin.get(); break;
        }
        cout << "\nNaciœnij Enter, aby wróciæ do menu...";
        cin.ignore(); cin.get();
    }
}
int main() {
    setlocale(LC_ALL, "");
    menu();
    return 0;
}
