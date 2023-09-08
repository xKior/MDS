#include <iostream>
#include <string>
int main() {
    std::string temp;
    float num_temp;
    float Celsius, Kelvin, Fahrenheit;
    std::cout << "Ingrese la escala de temperatura (Celsius, Kelvin, Fahrenheit): ";
    std::cin >> temp;
    std::cout << "Ingrese el número de la temperatura: ";
    std::cin >> num_temp;
    if (temp == "Celsius" || temp == "celsius") {
        Kelvin = num_temp + 273.15;
        Fahrenheit = (num_temp * 9 / 5) + 32;
        std::cout << "La temperatura de Celsius a Kelvin y Fahrenheit es:" << std::endl;
        std::cout << Kelvin << " K°" << std::endl;
        std::cout << Fahrenheit << " F°" << std::endl;
    } else if (temp == "Kelvin" || temp == "kelvin") {
        Celsius = num_temp - 273.15;
        Fahrenheit = (num_temp - 273.15) * 9 / 5 + 32;
        std::cout << "La temperatura de Kelvin a Celsius y Fahrenheit es:" << std::endl;
        std::cout << Celsius << " C°" << std::endl;
        std::cout << Fahrenheit << " F°" << std::endl;
    } else if (temp == "Fahrenheit" || temp == "fahrenheit") {
        Celsius = (num_temp - 32) * 5 / 9;
        Kelvin = (num_temp - 32) * 5 / 9 + 273.15;
        std::cout << "La temperatura de Fahrenheit a Celsius y Kelvin es:" << std::endl;
        std::cout << Kelvin << " K°" << std::endl;
        std::cout << Celsius << " C°" << std::endl;
    } else {
        std::cout << "Escala de temperatura no válida." << std::endl;
    }
    return 0;
}
