#include <iostream>
int main() {
    float libras, kilogramos, gramos;
    std::cout << "Ingrese la cantidad de libras:";
    std::cin >> libras;
    kilogramos = 0.453592 * libras;
    gramos = 453.6 * libras;
    std::cout << "La cantidad ingresada en libras a kilogramos es:" << kilogramos << "kg" << std::endl;
    std::cout << "La cantidad ingresada en libras a gramos es:" << gramos << "g" << std::endl;
    return 0;
}
