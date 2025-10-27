#include <iostream>
#include <cstddef>
using namespace std;
void sortt(int niz[], std::size_t n, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < n - i - 1; ++j) {
			if (cmp(niz[j+1], niz[j])) {
				std::swap(niz[j], niz[j + 1]);
			}
		}
	}
}
inline bool ascending(int a, int b) {
	return a < b;
}
inline bool descending(int a, int b) {
	return a > b;
}

int main() {
	int niz[] = { 5,2,6,1,3 };
	std::size_t n = 5;

	cout << "Ulazno: ";
	sortt(niz, n, ascending);
	for (auto x : niz)cout << x << " ";
	cout << endl;

	cout << "Silazno: ";
	sortt(niz, n, descending);
	for (auto x : niz)cout << x << " ";
	cout << endl;
	return 0;
}