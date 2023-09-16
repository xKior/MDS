#include <iostream>
using namespace std;

unsigned long long calcularFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        unsigned long long factorial = 1;
        for (int i = 2; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }
}

int main() {
    int numero;
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "El factorial no esta definido para numeros negativos." << endl;
    } else {
        unsigned long long resultado = calcularFactorial(numero);
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }

    return 0;
}
