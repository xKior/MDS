#include <iostream>

using namespace std;

int main() {
    int numero_hijos, edad_hijo_menor;
    bool madre_viuda;

    cout << "Ingrese el numero de hijos: ";
    cin >> numero_hijos;

    int edades[numero_hijos];

    for (int i = 0; i < numero_hijos; ++i) {
        cout << "Ingrese la edad del hijo " << i + 1 << ": ";
        cin >> edades[i];
    }

    cout << "¿Es la madre viuda? (1 para si, 0 para no): ";
    cin >> madre_viuda;

    double monto_base = 0.0;

    if (numero_hijos <= 2) {
        monto_base = 70.00;
    } else if (numero_hijos >= 3 && numero_hijos <= 5) {
        monto_base = 90.00;
    } else {
        monto_base = 120.00;
    }

    double monto_edad_escolar = 0.0;

    for (int i = 0; i < numero_hijos; ++i) {
        if (edades[i] >= 6 && edades[i] <= 18) {
            monto_edad_escolar += 10.00;
        }
    }

    double monto_madre_viuda = madre_viuda ? 20.00 : 0.0;

    double monto_total = monto_base + monto_edad_escolar + monto_madre_viuda;

    cout << "El monto mensual que recibira la familia es: S/." << monto_total << endl;

    return 0;
}
