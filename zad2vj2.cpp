#include <iostream>

struct Vector {
	int* d;
	int lv;
	int fv;
};

Vector* vector_new(int k = 2) {
	Vector* v = new Vector;
	v->d = new int[k];
	v->lv = 0;
	v->fv = k;
	return v;
}

void vector_delete(Vector* v) {
	delete[] v->d;
	delete v;
}