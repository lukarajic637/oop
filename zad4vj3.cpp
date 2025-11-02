#include <iostream>
#include <string>

struct Student {
    std::string ime;
    std::string JMBAG;
    int godina;
    int ECTS;
    double prosjek;
};

void filter_students(
    Student studenti[], std::size_t n,
    void (*akcija)(Student&),
    bool (*filter)(Student&)
) {
    for (std::size_t i = 0; i < n; ++i) {
        if (filter(studenti[i])) {
            akcija(studenti[i]);
        }
    }
}

void ispisi(Student& s) {
    std::cout << s.ime << " (" << s.JMBAG << "), Godina: "
        << s.godina << ", ECTS: " << s.ECTS
        << ", Prosjek: " << s.prosjek << "\n";
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

int main() {
    Student studenti[] = {
        {"Luka", "001", 1, 20, 4.0},
        {"Ana", "002", 1, 0, 3.2},
        {"Ivan", "003", 2, 45, 3.8},
        {"Sara", "004", 3, 55, 4.5}
    };
    std::size_t n = sizeof(studenti) / sizeof(studenti[0]);

    std::cout << "Studenti 1. godine s barem jednim ispitom:\n";
    filter_students(studenti, n, ispisi,
        [](Student& s) { return s.godina == 1 && s.ECTS > 0; });

    std::cout << "\nStudenti s prosjekom > 3.5:\n";
    filter_students(studenti, n, ispisi,
        [](Student& s) { return s.prosjek > 3.5; });


    std::cout << "\nPovecanje godine studentima s >= 45 ECTS...\n";
    filter_students(studenti, n, povecaj_godinu,
        [](Student& s) { return s.ECTS >= 45; });

    std::cout << "\nNakon povecanja godine:\n";
    for (Student& s : studenti) ispisi(s);

    return 0;
}
