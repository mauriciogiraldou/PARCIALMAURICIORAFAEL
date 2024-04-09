#include "funcion.h"
vector<int> dimensiones;
vector<int> contadorDeGiros;
bool comparar_elemento_exitoso = false;
void inicializarContadorDeGiros(int dimension) {
    contadorDeGiros = vector<int>(dimension, 0);
}
void recorrerVectorG(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Giros de la matriz " << i + 1 << ": " << vec[i] << endl;
    }
}
void recorrerVectorD(const vector<int>& vec) {
    cout << "X = (";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ",";
        }
    }
    cout << ")" << endl;
}
int validar_filas_columnas(int* a){
    do {
        cout<<"Ingrese un numero entero positivo para coordenada fila/columna: ";
        cin>>*a;

        if(cin.fail() || *a <= 0){
            cin.clear();
            cin.ignore(10000, '\n');
        }else{
            break;
        }
    } while(true);
    return *a;

}

int validar_comparacion(int* a){
    do {
        cout<<"Ingrese un numero que sea -1, 0 o 1: ";
        cin>>*a;

        if(cin.fail() || *a < -1 || *a > 1){
            cin.clear();
            cin.ignore(10000, '\n');
        }else{
            break;
        }
    } while(true);
    return *a;

}
int* regla_k(int *n){
    int* arreglok = new int[*n];
    for(int i= 0; i<2; i++){
        validar_filas_columnas(&(arreglok[i]));
    }
    for(int i = 2; i<*n; i++){
        validar_comparacion(&(arreglok[i]));
    }
    return arreglok;
}
int validar_numero(int* a){
    do {
        cout<<"Ingrese el numero de elementos de la regla k(debe ser mayor o igual a 3): ";
        cin>>*a;

        if(cin.fail() || *a < 3){
            cin.clear();
            cin.ignore(10000, '\n');
        }else{
            break;
        }
    } while(true);
    return *a;

}
int** crearMatrizImpar(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
    }
    int num = 1;
    int centro = n / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == centro && j == centro) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = num++;
            }
        }
    }
    dimensiones.push_back(n);
    return matriz;
}
void rotateMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
}
int contarFilas(int indice) {
    return dimensiones[indice];
}
vector<int**> crearMatricesImpares(int n,int d) {
    vector<int**> matrices;
    for (int i = 0; i < n; i++) {
        int** nueva_matriz = crearMatrizImpar(d);
        matrices.push_back(nueva_matriz);
    }
    return matrices;
}
void compararElemento(vector<int**>& matrices, int fila, int columna, int* relacion) {
    fila--;
    columna--;
    for (int i = 0; i < matrices.size() - 1; ++i) {
        int** matriz1 = matrices[i];
        int** matriz2 = matrices[i + 1];
        int elemento1 = matriz1[fila][columna];
        int elemento2 = matriz2[fila][columna];
        int dim2, contadorgiro = 0;
        if (relacion[i] == -1) {
            if (elemento1 < elemento2 && i==0) {
                contadorDeGiros[i] = contadorgiro;
                contadorDeGiros[i + 1] = contadorgiro;
            }
            if(elemento1<elemento2 && i!=0){
                contadorDeGiros[i + 1] = contadorgiro;

            }else{
                while(elemento1>=elemento2){
                    dim2=contarFilas(i + 1 );
                    rotateMatrix(matriz2,dim2);
                    elemento2=matriz2[fila][columna];
                    contadorgiro++;
                    contadorDeGiros[i + 1]=contadorgiro;
                    if(contadorgiro>3){
                        contadorgiro=0;
                        dim2=dim2 + 2;
                        for (int j = i + 1; j < matrices.size(); ++j){
                            int** nuevadimensionmatriz=crearMatrizImpar(dim2);
                            matrices[j]=nuevadimensionmatriz;
                            dimensiones[j]=dimensiones.back();
                            dimensiones.pop_back();
                        }
                        matriz2=matrices[i + 1];
                        fila++;
                        columna++;
                        elemento2=matriz2[fila][columna];
                        if (elemento1 < elemento2) {
                            contadorDeGiros[i + 1] = contadorgiro;
                        }else{
                            while(elemento1>=elemento2){
                                rotateMatrix(matriz2,dim2);
                                elemento2=matriz2[fila][columna];
                                contadorgiro++;
                                contadorDeGiros[i + 1]=contadorgiro;
                            }
                        }
                    }
                }
            }
        } else if (relacion[i] == 0) {
            if (elemento1 == elemento2 && i==0) {
                contadorDeGiros[i] = contadorgiro;
                contadorDeGiros[i + 1] = contadorgiro;
            }
            if(elemento1==elemento2 && i!=0){
                contadorDeGiros[i + 1] = contadorgiro;
            }else{
                while(elemento1!= elemento2){
                    dim2=contarFilas(i + 1 );
                    rotateMatrix(matriz2,dim2);
                    elemento2=matriz2[fila][columna];
                    contadorgiro++;
                    contadorDeGiros[i + 1]=contadorgiro;
                }
            }
        } else if (relacion[i] == 1) {
            if(fila==0 && columna==0 && i == 0){
                cout<<"Imposible encontrar un numero mayor a 1."<<endl;
                return;
            }

            if (elemento1 > elemento2 && i==0) {
                contadorDeGiros[i] = contadorgiro;
                contadorDeGiros[i + 1] = contadorgiro;
            }
            if(elemento1>elemento2 && i != 0){
                contadorDeGiros[i + 1] = contadorgiro;
            }else {
                while(elemento1<=elemento2){
                    dim2=contarFilas(i + 1 );
                    rotateMatrix(matriz2,dim2);
                    elemento2=matriz2[fila][columna];
                    contadorgiro++;
                    contadorDeGiros[i + 1]=contadorgiro;
                    if(contadorgiro>3 ){
                        cout<<"No existen combinaciones para la regla k ingresada. "<<endl;
                        return;
                    }
                }
            }
        }
    }
    comparar_elemento_exitoso = true;
}

