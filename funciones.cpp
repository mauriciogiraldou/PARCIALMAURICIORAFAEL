#include "funcion.h"
int queseaimpar(int Numeroi) {
    while (Numeroi % 2 == 0) {
        cout << "El numero debe ser impar, por favor ingrese otra vez: " << endl;
        cin >> Numeroi;
    }
    return Numeroi;
}
