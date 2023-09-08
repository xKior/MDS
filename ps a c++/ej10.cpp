#include <iostream>
int main() {
    int n, x = 1;
    float promedio, nota3, suma = 0.0;
    std::cout << "Ingrese la cantidad de notas: ";
    std::cin >> n;
    while (x <= n) {
        float num;
        std::cout << "Ingrese la nota " << x << ": ";
        std::cin >> num;
        suma += num;
        x++;
    }
    promedio = suma / n;
    std::cout << "El promedio de sus notas es de: " << promedio << std::endl;
    nota3 = promedio * 0.2;
    std::cout << "La equivalencia de la tercera nota es de: " << nota3 << std::endl;
    return 0;
}
