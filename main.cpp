#include <funcion.h>
using namespace std;
int main() {
    int numero;
    cout << "Ingrese un numero impar: ";
    cin >> numero;
    int numero_impar = queseaimpar(numero);
    cout << "El numero impar ingresado es: " << numero_impar << endl;
    return 0;
}
