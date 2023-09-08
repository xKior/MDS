#include <iostream>
int main() {
    float x;
    std::cout << "Ingrese hasta qué número quiere hacer el listado:";
    std::cin >> x;
    for (int n = 1; n <= x; ++n) {
        std::cout << n << std::endl;
    }
    return 0;
}
