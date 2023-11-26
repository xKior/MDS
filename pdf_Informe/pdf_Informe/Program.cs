using System;
using System.Collections.Generic;
using System.IO;
using iTextSharp.text;
using iTextSharp.text.pdf;

class Program
{
    // Clase para los productos
    class Producto
    {
        public string nombre;
        public int cantidad;
    }

    // Función para realizar la búsqueda en el inventario
    static int BuscarProducto(List<Producto> inventario, string nombre)
    {
        for (int i = 0; i < inventario.Count; ++i)
        {
            if (inventario[i].nombre == nombre)
            {
                return i;
            }
        }
        return -1; // Producto no encontrado
    }

    // Función que muestra el menú en la consola
    static void MostrarMenu()
    {
        Console.WriteLine("\n=== Menu ===");
        Console.WriteLine("1. Ingresar productos");
        Console.WriteLine("2. Modificar inventario");
        Console.WriteLine("3. Abono por Hectarea");
        Console.WriteLine("4. Informe");
        Console.WriteLine("5. Cerrar sesion");
    }

    // Nueva función para generar el informe en un documento PDF
    static void GenerarInformePDF(List<Producto> inventario)
    {
        // Crear un nuevo documento PDF
        Document doc = new Document();

        // Obtener la ruta de descargas
        string descargasPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);

        // Crear un directorio para almacenar los informes PDF si no existe
        string nombreDirectorio = Path.Combine(descargasPath, "Downloads", "Informes");

        if (!Directory.Exists(nombreDirectorio))
        {
            Directory.CreateDirectory(nombreDirectorio);
        }

        // Crear el nombre del archivo PDF con la fecha y hora actual
        string nombreArchivo = $"{nombreDirectorio}\\Informe_{DateTime.Now:yyyy_MM_dd_HH_mm_ss}.pdf";

        // Crear el archivo PDF
        PdfWriter.GetInstance(doc, new FileStream(nombreArchivo, FileMode.Create));

        // Abrir el documento PDF
        doc.Open();

        // Agregar contenido al documento PDF
        doc.Add(new Paragraph("=== Inventario Actual ==="));

        foreach (var producto in inventario)
        {
            doc.Add(new Paragraph($"Nombre: {producto.nombre}, Cantidad: {producto.cantidad}"));
        }

        // Cerrar el documento PDF
        doc.Close();

        Console.WriteLine($"Informe generado exitosamente: {nombreArchivo}");
    }

    static void Main()
    {
        // Este es el rol de admin, creamos un usuario y contraseña ya establecidos
        string usuario;
        string contrasena = "admin1234";

        // Creamos una lista llamada inventario que va a tener las variables de la clase Producto
        List<Producto> inventario = new List<Producto>();

        // Aquí hacemos el inicio de sesión
        do
        {
            Console.Write("Ingrese el usuario: ");
            usuario = Console.ReadLine();

            Console.Write("Ingrese la contrasena: ");
            string inputContrasena = Console.ReadLine();

            if (usuario == "admin" && inputContrasena == contrasena)
            {
                break;
            }
            else
            {
                Console.WriteLine("Usuario o contrasena incorrectos. Intente de nuevo.");
            }
        } while (true);

        int opcion;

        // Mostramos el menú para que seleccione alguna opción
        do
        {
            MostrarMenu();
            Console.Write("Seleccione una opcion: ");
            opcion = int.Parse(Console.ReadLine());

            // Usamos casos para el menú
            switch (opcion)
            {
                case 1:
                    {
                        char deseaIngresarMas;
                        do
                        {
                            Producto nuevoProducto = new Producto(); // Crear una nueva instancia de Producto
                            Console.Write("Ingrese el nombre del producto: ");
                            nuevoProducto.nombre = Console.ReadLine();

                            Console.Write("Ingrese la cantidad del producto: ");
                            nuevoProducto.cantidad = int.Parse(Console.ReadLine());

                            inventario.Add(nuevoProducto);

                            Console.Write("¿Desea ingresar mas productos? (s/n): ");
                            deseaIngresarMas = char.Parse(Console.ReadLine());
                        } while (char.ToLower(deseaIngresarMas) == 's');
                    }
                    break;

                case 2:
                    {
                        if (inventario.Count == 0)
                        {
                            Console.WriteLine("No hay productos en el inventario. Por favor, vaya al menu 1 e ingrese un producto.");
                            break;
                        }

                        Console.WriteLine("Opciones:");
                        Console.WriteLine("1. Agregar cantidad");
                        Console.WriteLine("2. Eliminar cantidad");
                        Console.WriteLine("3. Eliminar producto");
                        Console.Write("Seleccione una opción: ");

                        int opcionModificar = int.Parse(Console.ReadLine());

                        // Caso 1 es para añadir una cantidad de un producto
                        // Caso 2 es para eliminar una cantidad de un producto
                        switch (opcionModificar)
                        {
                            case 1:
                            case 2:
                                {
                                    Console.Write("Ingrese el nombre del producto: ");
                                    string nombreProducto = Console.ReadLine();

                                    int indice = BuscarProducto(inventario, nombreProducto);

                                    if (indice != -1)
                                    {
                                        if (opcionModificar == 1)
                                        {
                                            Console.Write("Ingrese la cantidad para agregar: ");
                                            int cantidad = int.Parse(Console.ReadLine());
                                            inventario[indice].cantidad += cantidad;
                                            Console.WriteLine($"Se agregaron {cantidad} unidades del producto.");
                                        }
                                        // OpcionModificar == 2
                                        else
                                        {
                                            Console.Write("Ingrese la cantidad a eliminar: ");
                                            int cantidad = int.Parse(Console.ReadLine());

                                            if (inventario[indice].cantidad >= cantidad)
                                            {
                                                inventario[indice].cantidad -= cantidad;
                                                Console.WriteLine($"Se eliminaron {cantidad} unidades del producto.");
                                            }
                                            else
                                            {
                                                Console.WriteLine("No hay suficientes unidades para eliminar.");
                                            }
                                        }
                                    }
                                    else
                                    {
                                        Console.WriteLine("Producto no encontrado.");
                                    }
                                }
                                break;

                            // Eliminar producto
                            case 3:
                                {
                                    Console.Write("Ingrese el nombre del producto: ");
                                    string nombreProducto = Console.ReadLine();

                                    int indice = BuscarProducto(inventario, nombreProducto);

                                    if (indice != -1)
                                    {
                                        inventario.RemoveAt(indice);
                                        Console.WriteLine("Se eliminó el producto.");
                                    }
                                    else
                                    {
                                        Console.WriteLine("Producto no encontrado.");
                                    }
                                }
                                break;

                            default:
                                Console.WriteLine("Opción no válida.");
                                break;
                        }
                    }
                    break;

                case 3:
                    {
                        Console.Write("Ingrese la cantidad de hectáreas que va a abonar: ");
                        int hectareas = int.Parse(Console.ReadLine());

                        const int abonoPorHectarea = 3;
                        int cantidadTotalAbono = hectareas * abonoPorHectarea;

                        Console.WriteLine($"Según la cantidad de hectáreas, es necesario {cantidadTotalAbono} bultos de abono.");

                        // Verificamos si hay suficiente abono en el inventario
                        int indiceAbono = BuscarProducto(inventario, "abono");

                        if (indiceAbono != -1 && inventario[indiceAbono].cantidad >= cantidadTotalAbono)
                        {
                            Console.WriteLine("Tiene suficiente abono en el inventario.");
                        }
                        else
                        {
                            if (indiceAbono == -1)
                            {
                                Console.WriteLine("No tiene abono en el inventario.");
                            }
                            else
                            {
                                Console.WriteLine($"Le faltan {cantidadTotalAbono - inventario[indiceAbono].cantidad} bultos de abono.");
                            }
                        }
                    }
                    break;

                case 4:
                    // Generar informe en PDF
                    GenerarInformePDF(inventario);
                    break;

                case 5:
                    Console.WriteLine("Sesión cerrada.");
                    break;

                default:
                    Console.WriteLine("Opción no válida. Intente de nuevo.");
                    break;
            }
        } while (opcion != 5);

        Console.ReadLine(); // Esperar a que el usuario presione Enter antes de cerrar la consola
    }
}
