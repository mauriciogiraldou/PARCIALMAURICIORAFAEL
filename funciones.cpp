#include "funcion.h"
int queseaimpar(int Numeroi) {
    while (Numeroi % 2 == 0) {
        cout << "El numero debe ser impar, por favor ingrese otra vez: " << endl;
        cin >> Numeroi;
    }
    return Numeroi;
}
void rotateMatrix(int** mat, int n) {
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(mat[i][j], mat[i][n - j - 1]);
        }
    }
}
int** crearMatrizImpar(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
    }

    int num = 1;
    int centro = n / 2; // Índice del elemento central

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == centro && j == centro) {
                // Elemento central vacío
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = num++;
            }
        }
    }

    return matriz;
}
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}
