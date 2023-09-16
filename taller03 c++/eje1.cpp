#include <iostream>

using namespace std;

int main() {
    int minutos1, segundos1, minutos2, segundos2;

    cout << "Ingrese el tiempo del primer atleta en minutos y segundos: ";
    cin >> minutos1 >> segundos1;

    cout << "Ingrese el tiempo del segundo atleta en minutos y segundos: ";
    cin >> minutos2 >> segundos2;

    int totalMinutos = minutos1 + minutos2;
    int totalSegundos = segundos1 + segundos2;

    if (totalSegundos >= 60) {
        totalMinutos += totalSegundos / 60;
        totalSegundos %= 60;
    }

    int horas = totalMinutos / 60;
    totalMinutos %= 60;

    cout << "Tiempo total utilizado por ambos atletas: " << horas << " horas, " << totalMinutos << " minutos, " << totalSegundos << " segundos." << endl;

    return 0;
}
