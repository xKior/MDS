#include <iostream>
#include <vector>
using namespace std;

int contarOvejasPresentes(const vector<bool>& ovejas) {
    int contador = 0;

    for (bool presente : ovejas) {
        if (presente) {
            contador++;
        }
    }

    return contador;
}

int main() {
    vector<bool> ovejas = {true, true, true, false, true, true, true, true, true, false, true, false, true, false, false, true, true, true, true, true, false, false, true, true  };
    int cantidadPresentes = contarOvejasPresentes(ovejas);
    cout << "Número de ovejas presentes: " << cantidadPresentes << endl;

    return 0;
}
