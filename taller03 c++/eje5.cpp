#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> distancias = {50, 55, 57, 58, 60};
    int distanciasMax = 174;
    int numPueblos = 3;

    int maxSum = 0;
    vector<int> distanciasSeleccionadas;

    for (int i = 0; i < distancias.size(); i++) {
        for (int j = i + 1; j < distancias.size(); j++) {
            for (int k = j + 1; k < distancias.size(); k++) {
                int sum = distancias[i] + distancias[j] + distancias[k];
                if (sum <= distanciasMax && sum > maxSum) {
                    maxSum = sum;
                    distanciasSeleccionadas = {distancias[i], distancias[j], distancias[k]};
                }
            }
        }
    }

    if (distanciasSeleccionadas.empty()) {
        cout << "No se encontró una combinación válida." << endl;
    } else {
        cout << "Distancias seleccionadas: ";
        for (int i = 0; i < distanciasSeleccionadas.size(); i++) {
            cout << distanciasSeleccionadas[i];
            if (i < distanciasSeleccionadas.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Total de millas: " << maxSum << endl;
    }

    return 0;
}
