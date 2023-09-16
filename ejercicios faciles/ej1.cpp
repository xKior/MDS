#include <iostream>
using namespace std;

int main() {
    double centimetros, pulgadas;
    cout << "Ingrese la cantidad en centimetros: ";
    cin >> centimetros;

    pulgadas = centimetros / 2.54;

    cout << centimetros << " centimetros son " << pulgadas << " pulgadas." << endl;

    return 0;
}
