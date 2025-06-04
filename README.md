# 📐 Kalkulator Figur Geometrycznych

Konsolowa aplikacja w języku C++ umożliwiająca obliczenia geometryczne (długość, pole powierzchni, objętość) oraz konwersję jednostek.

## 📋 Opis

Aplikacja umożliwia:

- Obliczenia dla figur płaskich i przestrzennych
- Przeliczanie wartości między jednostkami: `mm`, `cm`, `m`, `km`
- Intuicyjny interfejs tekstowy z czytelnym menu
- Automatyczną konwersję jednostek dla różnych typów danych (długość, pole, objętość)

## ⚙️ Funkcje

### Obliczenia

Program umożliwia wybór figury, wprowadzenie odpowiednich parametrów oraz otrzymanie wyniku obliczeń.

### Konwersja jednostek

Funkcja `konwersjaJednostki()` umożliwia przeliczenie wartości między wybranymi jednostkami długości. Obsługiwane typy:
- Długość
- Pole powierzchni
- Objętość

### Estetyka i czytelność

Program wykorzystuje prostą grafikę ASCII (linie, ramki), aby zwiększyć czytelność wyników i opcji w menu.

## 🛠️ Kompilacja i uruchomienie

Wymagany kompilator C++ (np. `g++`).

```bash
g++ Kalkulator_Figur.cpp -o kalkulator
./kalkulator
