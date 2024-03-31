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

    // Reverse each column of the matrix
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(mat[i][j], mat[n - i - 1][j]);
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
    dimensiones.push_back(n);
    return matriz;
}
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}
vector<int**> crearMatricesImpares(int n) {
    vector<int**> matrices;
    int d;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la dimension de la matriz " << i + 1 << ": ";
        cin >> d;
        // Validar que la dimensión sea impar
        while (d % 2 == 0) {
            cout << "La dimension debe ser impar. Ingrese nuevamente: ";
            cin >> d;
        }
        int** nueva_matriz = crearMatrizImpar(d);
        matrices.push_back(nueva_matriz);
    }
    return matrices;
}
int contarFilas(int indice) {
    return dimensiones[indice];
}
void recorrerVector(const vector<int>& vec) {
    cout << "Recorriendo el vector:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Giros de matriz " << i + 1 << ": " << vec[i] << endl;
    }
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
