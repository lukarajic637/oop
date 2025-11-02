#include <iostream>

int main() {
    auto parni = [](int x) { return x % 2 == 0; };
    auto neparni = [](int x) { return x % 2 != 0; };
    auto udvostruci = [](int x) { return x * 2; };
    auto prepolovi = [](int x) { return x / 2; };

  
    int suma = 0;
    int produkt = 1;
    auto dodaj_u_sumu = [&](int x) { suma += x; };
    auto dodaj_u_produkt = [&](int x) { produkt *= x; };

    int prag = 5;
    auto dodaj_ako_vecipraga = [prag, &suma](int x) { if (x > prag) suma += x; };


    int niz[] = { 2, 3, 6, 9, 10 };
    std::size_t n = sizeof(niz) / sizeof(niz[0]);

   
    for (std::size_t i = 0; i < n; ++i) {
        if (parni(niz[i])) niz[i] = prepolovi(niz[i]);
        else niz[i] = udvostruci(niz[i]);
    }

    std::cout << "Niz nakon obrade: ";
    for (int x : niz) std::cout << x << " ";
    std::cout << "\n";


    for (int x : niz) {
        dodaj_u_sumu(x);
        dodaj_u_produkt(x);
    }
    std::cout << "Suma: " << suma << ", Produkt: " << produkt << "\n";


    suma = 0;
    for (int x : niz) dodaj_ako_vecipraga(x);
    std::cout << "Suma brojeva veCih od " << prag << ": " << suma << "\n";

    return 0;
}
