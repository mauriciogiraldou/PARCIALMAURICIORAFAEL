#include <iostream>
#include <vector>
//tres menos seguido se totea
using namespace std;
vector<int> dimensiones;
vector<int> contadorDeGiros;
void inicializarContadorDeGiros(int dimension) {
    contadorDeGiros = vector<int>(dimension, 0);
}
void recorrerVector(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Giros de la matriz " << i + 1 << ": " << vec[i] << endl;
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
    dimensiones.push_back(n);

    return matriz;
}
void rotateMatrix(int** mat, int n) {
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each column of the matrix
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
    vector<int> dimensiones;
    for (int i = 0; i < n; i++) {
        int** nueva_matriz = crearMatrizImpar(d);
        matrices.push_back(nueva_matriz);
    }
    return matrices;
}
void compararElemento(vector<int**>& matrices, int fila, int columna, int* relacion) {
    int dim, dim2, contadorgiro = 0;
    for (int i = 0; i < matrices.size() - 1; ++i) {
        int** matriz1 = matrices[i];
        int** matriz2 = matrices[i + 1];
        int elemento1 = matriz1[fila][columna];
        int elemento2 = matriz2[fila][columna];
        int fueradim=contarFilas(i);
        if(elemento1==0){
            cout<<"Error se esta comparando la celda del centro "<<endl;
            break;
        }

        if (relacion[i] == -1) {
            if (elemento1 < elemento2) {
                contadorDeGiros[i] = contadorgiro;
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
                        contadorDeGiros[i + 1]=contadorgiro;
                        while(elemento1>=elemento2 & i==0){
                            dim=contarFilas(i);
                            rotateMatrix(matriz1,dim);
                            elemento1=matriz1[fila][columna];
                            contadorgiro++;
                            contadorDeGiros[i] = contadorgiro;
                            if(contadorgiro>3){
                                cout<<"no se encontraron combinaciones"<<endl;
                                break;
                            }


                        }

                    }

                }
            }

        } else if (relacion[i] == 0) {
            if (elemento1 == elemento2) {
                contadorDeGiros[i] = contadorgiro;
                contadorDeGiros[i + 1] = contadorgiro;
                cout << "El elemento en la fila " << fila << ", columna " << columna << " de la matriz " << i + 1 << " es igual al de la matriz " << i + 2 << "." << endl;
            } else {
                cout << "El elemento en la fila " << fila << ", columna " << columna << " de la matriz " << i + 1 << " no es igual al de la matriz " << i + 2 << "." << endl;
            }
        } else if (relacion[i] == 1) {
            if (elemento1 > elemento2) {
                contadorDeGiros[i] = contadorgiro;
                contadorDeGiros[i + 1] = contadorgiro;
                cout << "El elemento en la fila " << fila << ", columna " << columna << " de la matriz " << i + 1 << " es mayor al de la matriz " << i + 2 << "." << endl;
            } else {
                while(elemento1<=elemento2 & i==0){
                    dim=contarFilas(i);
                    rotateMatrix(matriz1,dim);
                    elemento1=matriz1[fila][columna];
                    contadorgiro++;
                    contadorDeGiros[i]=contadorgiro;
                    if(contadorgiro>3){
                        contadorgiro=0;
                        contadorDeGiros[i]=contadorgiro;
                    }

                }
                cout << "El elemento en la fila " << fila << ", columna " << columna << " de la matriz " << i + 1 << " no es mayor al de la matriz " << i + 2 << "." << endl;
            }
        }
    }
    return;
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
    cout<<"El numero ingresado es: "<<*a<<endl;
    return *a;

}

int validar_filas_columnas(int* a){
    do {
        cout<<"Ingrese un numero entero positivo para coordenada fila/columna: ";
        cin>>*a;

        if(cin.fail() || *a < 0){
            cin.clear();
            cin.ignore(10000, '\n');
        }else{
            break;
        }
    } while(true);
    cout<<"El numero es: "<<*a<<endl;
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
    cout<<"El numero ingresado es: "<<*a<<endl;
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

int main() {
    int n, fila, columna,d;
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
    if(mayor==0){
        mayor=3;
    }
    if(mayor==1){
        mayor=3;
    }
    if(mayor%2==0){
        mayor++;
    }
    n=num-1;
    vector<int**> matrices = crearMatricesImpares(n,mayor);
    int* relacion=new int[num-2];
    for (int i = 2; i < num; ++i) {
        relacion[i - 2] = invocar_k[i];
    }
    inicializarContadorDeGiros(n);
    compararElemento(matrices, fila, columna, relacion);
    recorrerVector(contadorDeGiros);
    // Liberar la memoria de todas las matrices al finalizar el programa
    for (int k = 0; k < n; k++) {
        cout << "Matriz " << k + 1 << ":\n";
        for (int i = 0; i < mayor; i++) { // Corregido aquí
            for (int j = 0; j < mayor; j++) { // Corregido aquí
                cout << matrices[k][i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        int** matriz = matrices[i];
        delete[] matriz[0]; // Solo necesitamos liberar la primera fila ya que se asignaron en bloques contiguos
        delete[] matriz;
    }
    delete[] invocar_k;
    delete[] relacion;
    return 0;
}
