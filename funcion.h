#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include <vector>
using namespace std;
vector<int> dimensiones;
vector<int> contadorDeGiros;
int queseaimpar(int n);
vector<int**> crearMatricesImpares(int n);
int** crearMatrizImpar(int n);
void rotateMatrix(int** mat, int n);
void liberarMatriz(int** matriz, int n);
void recorrerVector(const vector<int>& vec);
int contarFilas(int indice);
int validar_numero(int* a);
int validar_filas_columnas(int* a);
int validar_comparacion(int* a);
int* regla_k(int *n);
#endif // FUNCION_H
