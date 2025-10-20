#include <iostream>

int* funkcija(int n) {
	if (n <= 0) {
		return nullptr;
	}
	int* niz = new int[n];
	niz[0] = 1;
	if (n > 1) {
		niz[1] = 1;
	}
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main() {
	int n =8;
	int* niz = funkcija(n);
	std::cout << "Niz: ";
	for (int i = 0; i < n; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;
	delete[] niz;
	return 0;
}