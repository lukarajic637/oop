#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Matrica {
    int m;          // broj redaka
    int n;          // broj stupaca
    double** elementi; 
};

Matrica novaMatrica(int m, int n) { // 3 2
    Matrica mat;
    mat.m = m;
    mat.n = n;
    mat.elementi = new double* [m]; //[3]== [[],[],[]]
    for (int i = 0; i < m; i++)
        mat.elementi[i] = new double[n];//mat.elementi[2] = new double[2]
    return mat; // [[  ],[  ],[  ]]
}

void brisiMatricu(Matrica& mat) {
    for (int i = 0; i < mat.m; i++)
        delete[] mat.elementi[i];  
    delete[] mat.elementi;
    mat.elementi = nullptr;
    mat.m = 0;
    mat.n = 0;
}

void unosMatrice(Matrica& mat) {
    for (int i = 0; i < mat.m; i++)
        for (int j = 0; j < mat.n; j++) { /
            cout << "mat[" << i << "][" << j << "] = ";
            cin >> mat.elementi[i][j]; // [0][0], [0][1], [1][0], [1][1], [2][0]
        }
}

void generirajMatricu(Matrica& mat, double a, double b) {
    srand(time(nullptr));
    for (int i = 0; i < mat.m; i++)
        for (int j = 0; j < mat.n; j++)
            mat.elementi[i][j] = a + (double)rand() / RAND_MAX * (b - a);
}

void ispisMatrice(const Matrica& mat) {
    for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.n; j++)
            cout << setw(10) << fixed << setprecision(4) << mat.elementi[i][j];
        cout << endl;
    }
}

Matrica zbrojMatrica(const Matrica& A, const Matrica& B) {
    Matrica C = novaMatrica(A.m, A.n);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            C.elementi[i][j] = A.elementi[i][j] + B.elementi[i][j];
    return C;
}

Matrica razlikaMatrica(const Matrica& A, const Matrica& B) {
    Matrica C = novaMatrica(A.m, A.n);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            C.elementi[i][j] = A.elementi[i][j] - B.elementi[i][j];
    return C;
}

Matrica transponiraj(const Matrica& A) {
    Matrica T = novaMatrica(A.n, A.m);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            T.elementi[j][i] = A.elementi[i][j];
    return T;
}

int main() {
    int m, n;
    cout << "Unesi broj redaka i stupaca: ";
    cin >> m >> n;

    Matrica A = novaMatrica(m, n);
    Matrica B = novaMatrica(m, n);

    cout << "Unesi elemente prve matrice:\n";
    unosMatrice(A);

    cout << "Generiram drugu matricu s nasumičnim brojevima...\n";
    generirajMatricu(B, 0, 5);

    cout << "\nMatrica A:\n";
    ispisMatrice(A);

    cout << "\nMatrica B:\n";
    ispisMatrice(B);

    Matrica Z = zbrojMatrica(A, B);
    cout << "\nZbroj A + B:\n";
    ispisMatrice(Z);

    Matrica R = razlikaMatrica(A, B);
    cout << "\nRazlika A - B:\n";
    ispisMatrice(R);

    Matrica T = transponiraj(A);
    cout << "\nTransponirana matrica A:\n";
    ispisMatrice(T);

    brisiMatricu(A);
    brisiMatricu(B);
    brisiMatricu(Z);
    brisiMatricu(R);
    brisiMatricu(T);

    return 0;
}