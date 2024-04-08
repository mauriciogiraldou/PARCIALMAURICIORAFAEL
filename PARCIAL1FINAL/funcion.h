#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include <vector>
using namespace std;
extern vector<int> dimensiones;
extern vector<int> contadorDeGiros;
extern bool comparar_elemento_exitoso;
int validar_numero(int* a);
int validar_filas_columnas(int* a);
int validar_comparacion(int* a);
int* regla_k(int *n);
void inicializarContadorDeGiros(int dimension);
void recorrerVectorG(const vector<int>& vec);
void recorrerVectorD(const vector<int>& vec);
int** crearMatrizImpar(int n);
void rotateMatrix(int** mat, int n);
int contarFilas(int indice);
vector<int**> crearMatricesImpares(int n,int d);
void compararElemento(vector<int**>& matrices, int fila, int columna, int* relacion);
#endif // FUNCION_H
