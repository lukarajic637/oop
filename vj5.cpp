#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std;


enum class Zog {
    Bastoni,   
    Kupe,     
    Dinari,    
    Spade      
};

string zogToString(Zog z) {
    switch (z) {
    case Zog::Bastoni: return "Bastoni";
    case Zog::Kupe:   return "Kupe";
    case Zog::Dinari:  return "Dinari";
    case Zog::Spade:   return "Spade";
    }
    return "";
}


class Karta {
    int broj;      
    Zog zog;

public:
    Karta(int broj = 1, Zog zog = Zog::Bastoni)
        : broj(broj), zog(zog) {
    }

    int getBroj() const { return broj; }
    Zog getZog() const { return zog; }

    string toString() const {
        
        return to_string(broj) + " " + zogToString(zog);
    }
};

class Mac {
    vector<Karta> karte;

public:
    Mac() {
   
        for (int b = 1; b <= 10; ++b) {
            karte.emplace_back(b, Zog::Bastoni);
            karte.emplace_back(b, Zog::Kupe);
            karte.emplace_back(b, Zog::Dinari);
            karte.emplace_back(b, Zog::Spade);
        }
    }

    void promijesaj() {
        random_device rd;
        mt19937 g(rd());
        shuffle(karte.begin(), karte.end(), g);
    }


    template<typename PlayerContainer>
    void podijeli(PlayerContainer& igraci) {
        const int karataPoIgracu = 10;
        for (int k = 0; k < karataPoIgracu; ++k) {
            for (auto& igrac : igraci) {
                if (karte.empty()) return;
                igrac.dodajKartu(karte.back());
                karte.pop_back();
            }
        }
    }
};


class Igrac {
    string ime;
    vector<Karta> ruka;
    int bodoviAkuzе = 0;

public:
    Igrac(const string& ime) : ime(ime) {}

    const string& getIme() const { return ime; }
    const vector<Karta>& getRuka() const { return ruka; }

    void dodajKartu(const Karta& k) {
        ruka.push_back(k);
    }

    int izracunajAkuzu() {
        int bodovi = 0;


        bool ima1[4] = { false, false, false, false };
        bool ima2[4] = { false, false, false, false };
        bool ima3[4] = { false, false, false, false };

        for (const auto& k : ruka) {
            int s = static_cast<int>(k.getZog());
            int b = k.getBroj();
            if (b == 1) ima1[s] = true;
            else if (b == 2) ima2[s] = true;
            else if (b == 3) ima3[s] = true;
        }

        for (int s = 0; s < 4; ++s) {
            if (ima1[s] && ima2[s] && ima3[s]) {
                bodovi += 3;  
            }
        }

  
        int countRank[11] = { 0 }; 
        for (const auto& k : ruka) {
            int b = k.getBroj();
            if (b >= 1 && b <= 10) {
                countRank[b]++;
            }
        }

   
        for (int b : {1, 2, 3}) {
            if (countRank[b] >= 3) {
                if (countRank[b] == 3)
                    bodovi += 3;
                else if (countRank[b] == 4)
                    bodovi += 4;
            }
        }

        bodoviAkuzе = bodovi;
        return bodovi;
    }

    int getBodoviAkuze() const {
        return bodoviAkuzе;
    }

    void ispisiRuku() const {
        cout << "Ruka igraca " << ime << ":\n";
        for (const auto& k : ruka) {
            cout << "  " << k.toString() << "\n";
        }
    }
};


int main() {
    int brojIgraca;
    cout << "Unesite broj igraca (2 ili 4): ";
    cin >> brojIgraca;

    if (brojIgraca != 2 && brojIgraca != 4) {
        cout << "Dozvoljen broj igraca je 2 ili 4.\n";
        return 1;
    }

    vector<Igrac> igraci;
    igraci.reserve(brojIgraca);

    for (int i = 0; i < brojIgraca; ++i) {
        string ime;
        cout << "Unesite ime igraca " << (i + 1) << ": ";
        cin >> ime;
        igraci.emplace_back(ime);
    }

    Mac mac;
    mac.promijesaj();
    mac.podijeli(igraci);

    cout << "\n--- Podijeljene ruke ---\n";
    for (const auto& igrac : igraci) {
        igrac.ispisiRuku();
        cout << "\n";
    }

    cout << "--- Bodovi iz akuze ---\n";
    for (auto& igrac : igraci) {
        int bodovi = igrac.izracunajAkuzu();
        cout << "Igrac " << igrac.getIme()
            << " ima " << bodovi << " bodova iz akuze.\n";
    }

    return 0;
}
