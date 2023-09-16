#include <iostream>
using namespace std;

double elevarNumero(double numero, int potencia) {
    double resultado = 1.0;

    for (int i = 0; i < potencia; i++) {
        resultado *= numero;
    }

    return resultado;
}

int main() {
    double base;
    int exponente;
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;
    double resultado = elevarNumero(base, exponente);
    cout << "Resultado: " << resultado << endl;

    return 0;
}
