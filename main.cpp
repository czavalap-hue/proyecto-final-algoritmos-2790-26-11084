#include <iostream>

using namespace std;

int main() {
    int opcion = 0;
    int totalVentas = 0;
    double dineroTotal = 0, totalDescuentos = 0;
    double ventaMayor = 0, ventaMenor = 0;

    do {
        cout << "\n--- TIENDITA DE BARRIO ---" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        } 
        else if (opcion == 1) {
            double precio = -1;
            int cantidad = 0;
            double subtotalVenta = 0;

            cout << "\n--- NUEVA VENTA (0 para terminar) ---" << endl;
            
            while (precio != 0) {
                cout << "Precio del producto: Q";
                cin >> precio;

                while (precio < 0) {
                    cout << "Error: El precio no puede ser negativo. Ingrese de nuevo: Q";
                    cin >> precio;
                }

                if (precio != 0) {
                    cout << "Cantidad (1-100): ";
                    cin >> cantidad;

                    while (cantidad < 1 || cantidad > 100) {
                        cout << "Error: Cantidad invalida. Ingrese de nuevo (1-100): ";
                        cin >> cantidad;
                    }

                    subtotalVenta += (precio * cantidad);
                }
            }

            cout << "Subtotal acumulado de esta venta: Q" << subtotalVenta << endl;
        } 
        else if (opcion == 2) {
            cout << "\n[Resumen parcial en desarrollo para el Hito 2]" << endl;
        }

    } while (opcion != 3);

    cout << "\nCaja cerrada correctamente. Saliendo..." << endl;
    return 0;
}
