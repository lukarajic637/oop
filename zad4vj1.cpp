#include <iostream>

int& at(int niz[], int i) {
    return niz[i];
}

int main() {
    int niz[] = {10, 20, 30, 40, 50};
    int i = 2;

    at(niz, i) += 1;

    for (int j = 0; j < 5; ++j) {
        std::cout << niz[j] << " ";
    }

    return 0;
}
