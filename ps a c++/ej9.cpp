#include <iostream>
#include <string>
int main() {
    float notaf, previo1, previo2, nota3, previof;
    std::string asignatura;
    std::cout << "Ingrese la asignatura: ";
    std::cin >> asignatura;
    std::cout << "Ingrese la nota del primer previo: ";
    std::cin >> previo1;
    std::cout << "Ingrese la nota del segundo previo: ";
    std::cin >> previo2;
    std::cout << "Ingrese la nota del tercer previo: ";
    std::cin >> nota3;
    std::cout << "Ingrese la nota del previo final: ";
    std::cin >> previof;
    notaf = (previo1 * 0.25) + (previo2 * 0.25) + (nota3 * 0.20) + (previof * 0.30);
    std::cout << "La nota final de " << asignatura << " es de: " << notaf << std::endl;
    return 0;
}
