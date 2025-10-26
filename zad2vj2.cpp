#include <iostream>
using namespace std;

struct Vector {
    int* elementi;
    int logicka;
    int fizicka;
};

Vector vector_new(int init) { // init = 2
    Vector v;
    v.elementi = new int[init]; // [  ]
    v.logicka = 0;
    v.fizicka = init; // 2
    return v;
}

void vector_delete(Vector& v) {
    delete[] v.elementi;
    v.elementi = nullptr;
    v.logicka = 0;
    v.fizicka = 0;
}

void vector_push_back(Vector& v, int vrijednost) {
    if (v.logicka >= v.fizicka) { // 2>=2
        int novaFizicka = v.fizicka * 2; // novaFizicka = 4
        int* noviNiz = new int[novaFizicka];  // [    ]
        for (int i = 0; i < v.logicka; i++) { // 0,1,2
            noviNiz[i] = v.elementi[i]; // noviniz[2] = v.elementi[2](15)
            // [5, 10 , 15]
        }
        delete[] v.elementi; // v.elementi = []
        v.elementi = noviNiz; // v.elementi = [5 ,10 ,15,  ]
        v.fizicka = novaFizicka; // v.fizicka = 4
    }
    v.elementi[v.logicka] = vrijednost;  // v.elementi[2] = 15
    v.logicka++; // 3
}

void vector_pop_back(Vector& v) {
    if (v.logicka > 0) { // 3>0
        v.logicka--;  // v.logicka = 2
    }
}

int vector_front(Vector& v) {
    return v.elementi[0]; // 5 
}

int vector_back(Vector& v) {
    return v.elementi[v.logicka - 1]; // 15
}

int vector_size(Vector& v) { 
    return v.logicka; 
}

int main() {
    Vector v = vector_new(2);

    vector_push_back(v, 5);
    vector_push_back(v, 10);
    vector_push_back(v, 15);

    cout << "Prvi element: " << vector_front(v) << endl;
    cout << "Zadnji element: " << vector_back(v) << endl;
    cout << "Velicina: " << vector_size(v) << endl;

    vector_pop_back(v);
    cout << "Nakon pop_back, velicina: " << vector_size(v) << endl;

    vector_delete(v);
    return 0;
}