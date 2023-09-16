#include <iostream>

using namespace std;

int main() {
    double pies, metros;


    cout << "Ingrese la cantidad en pies: ";
    cin >> pies;
    cout << "Ingrese la cantidad en metros: ";
    cin >> metros;

    double pulgadas_pies = pies * 12;
    double pulgadas_metros = metros / 0.0254;

    double suma_pulgadas = pulgadas_pies + pulgadas_metros;

    double yardas = suma_pulgadas / (3*12);
    double metros_total = suma_pulgadas * 0.0254;
    double millas = metros_total / 1609;

    cout << "Suma en pulgadas: " << suma_pulgadas << endl;
    cout << "Suma en yardas: " << yardas << endl;
    cout << "Suma en metros: " << metros_total << endl;
    cout << "Suma en millas: " << millas << endl;

    return 0;
}
