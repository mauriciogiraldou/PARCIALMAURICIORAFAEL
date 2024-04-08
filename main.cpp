#include <funcion.h>
using namespace std;
int main() {
    int n, fila, columna;
    int num = 0;
    validar_numero(&num);
    int* invocar_k = regla_k(&num);
    cout<<"La regla k es: "<<endl;
    for(int i = 0; i<num; i++){
        cout<<invocar_k[i]<<", ";
    }
    cout<<endl;
    fila=invocar_k[0];
    columna=invocar_k[1];
    int mayor;
    if (fila >= columna) {
        mayor = fila;
    } else {
        mayor = columna;
    }
    if(mayor==1){
        mayor=3;
    }
    if(mayor%2==0){
        mayor++;
    }
    if (fila == (mayor/2)+ 1 && columna == (mayor/2)+ 1) {
        mayor=mayor+ 2;
    }
    n=num-1;
    vector<int**> matrices = crearMatricesImpares(n,mayor);
    int* relacion=new int[num-2];
    for (int i = 2; i < num; ++i) {
        relacion[i - 2] = invocar_k[i];
    }
    inicializarContadorDeGiros(n);
    compararElemento(matrices, fila, columna, relacion);
    if (comparar_elemento_exitoso) {
        recorrerVectorG(contadorDeGiros);
        recorrerVectorD(dimensiones);
    }
    for (int i = 0; i < n; ++i) {
        int** matriz = matrices[i];
        delete[] matriz[0];
        delete[] matriz;
    }
    delete[] invocar_k;
    delete[] relacion;
    return 0;
}
