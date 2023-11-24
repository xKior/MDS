#include <iostream>
#include <vector>
#include <string>

using namespace std;

// creamos una estructura para los productos

struct Producto {
    string nombre;
    int cantidad;
};

// esta funcion es para realizar la busqueda en la opcion 2

int buscarProducto(const vector<Producto>& inventario, const string& nombre) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].nombre == nombre) {
            return i;
        }
    }
    return -1; // Producto no encontrado
}

// esta funcion vacia es el menu que se va a ver en la consola

void mostrarMenu() {
    cout << "\n=== Menu ===\n";
    cout << "1. Ingresar productos\n";
    cout << "2. Modificar inventario\n";
    cout << "3. Abono por Hectarea\n";
    cout << "4. Informe\n";
    cout << "5. Cerrar sesion\n";
}

int main() {

    // este es el rol de admin, creamos un usuario y contraseña ya establecidos

    string usuario;
    string contrasena = "admin1234";

    // creamos una funcion llamada inventario que va a tener las variables de la estructura

    vector<Producto> inventario;

    // aca hacemos el inicio de sesion

    do {
        cout << "Ingrese el usuario: ";
        cin >> usuario;

        cout << "Ingrese la contrasena: ";
        string inputContrasena;
        cin >> inputContrasena;

        if (usuario == "admin" && inputContrasena == contrasena) {
            break; 
            
            // si es igual la contraseña entra y se rompe el bucle sino vuelve a hacerlo

        }
        else {
            cout << "Usuario o contrasena incorrectos. Intente de nuevo.\n";
        }
    } while (true);

    int opcion;
    
    // mostramos el menu para que seleccione alguna opcion

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // usamos casos para el menu

        switch (opcion) {
        case 1: 
        {
            char deseaIngresarMas;
            do {
                Producto nuevoProducto;
                cout << "Ingrese el nombre del producto: ";
                cin >> nuevoProducto.nombre;

                cout << "Ingrese la cantidad del producto: ";
                cin >> nuevoProducto.cantidad;

                inventario.push_back(nuevoProducto);

                cout << "¿Desea ingresar mas productos? (s/n): ";
                cin >> deseaIngresarMas;
            } while (deseaIngresarMas == 's' || deseaIngresarMas == 'S');
        }
        break;

        // aca es para modificar el inventario

        case 2: 
        {
            if (inventario.empty()) {
                cout << "No hay productos en el inventario. Por favor, vaya al menu 1 e ingrese un producto.\n";
                break;
            }

            cout << "Opciones:\n";
            cout << "1. Agregar cantidad\n";
            cout << "2. Eliminar cantidad\n";
            cout << "3. Eliminar producto\n";
            cout << "Seleccione una opción: ";

            int opcionModificar;
            cin >> opcionModificar;

            // caso 1 es para añadir una cantidad de un producto
            // caso 2 es para eliminar una cantidad de un producto

            switch (opcionModificar) {
            case 1: 
            case 2: 
            {
                string nombreProducto;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombreProducto;

                int indice = buscarProducto(inventario, nombreProducto);

                if (indice != -1) {
                    if (opcionModificar == 1) {
                        cout << "Ingrese la cantidad para agregar: ";
                        int cantidad;
                        cin >> cantidad;
                        inventario[indice].cantidad += cantidad;
                        cout << "Se agregaron " << cantidad << " unidades del producto.\n";
                    }

                    // opcionModificar == 2

                    else { 
                        cout << "Ingrese la cantidad a eliminar: ";
                        int cantidad;
                        cin >> cantidad;

                        if (inventario[indice].cantidad >= cantidad) {
                            inventario[indice].cantidad -= cantidad;
                            cout << "Se eliminaron " << cantidad << " unidades del producto.\n";
                        }
                        else {
                            cout << "No hay suficientes unidades para eliminar.\n";
                        }
                    }
                }
                else {
                    cout << "Producto no encontrado.\n";
                }
            }
            break;
            
            // eliminar producto

            case 3: 
            {
                string nombreProducto;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombreProducto;

                int indice = buscarProducto(inventario, nombreProducto);

                if (indice != -1) {
                    inventario.erase(inventario.begin() + indice);
                    cout << "Se elimino el producto.\n";
                }
                else {
                    cout << "Producto no encontrado.\n";
                }
            }
            break;

            default:
                cout << "Opcion no valida.\n";
                break;
            }
        }
        break;

        // abono por hectarea

        case 3: 
        {
            int hectareas;
            cout << "Ingrese la cantidad de hectareas que va a abonar: ";
            cin >> hectareas;

            const int abonoPorHectarea = 3;
            int cantidadTotalAbono = hectareas * abonoPorHectarea;

            cout << "Segun la cantidad de hectareas, es necesario " << cantidadTotalAbono << " bultos de abono.\n";

            // verificamos si hay suficiente abono en el inventario

            int indiceAbono = buscarProducto(inventario, "abono");
            if (indiceAbono != -1 && inventario[indiceAbono].cantidad >= cantidadTotalAbono) {
                cout << "Tiene suficiente abono en el inventario.\n";
            }
            else {
                if (indiceAbono == -1) {
                    cout << "No tiene abono en el inventario.\n";
                }
                else {
                    cout << "Le faltan " << (cantidadTotalAbono - inventario[indiceAbono].cantidad) << " bultos de abono.\n";
                }
            }
        }
        break;

        // Informe

        case 4: 
            if (inventario.empty()) {
                cout << "No hay productos en el inventario.\n";
            }
            else {
                cout << "Inventario actual:\n";
                for (const Producto& producto : inventario) {
                    cout << "Nombre: " << producto.nombre << ", Cantidad: " << producto.cantidad << "\n";
                }
            }
            break;

        // cerrar sesion

        case 5: 
            cout << "Sesion cerrada.\n";
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}
