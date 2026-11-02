
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int opcion = 0;
    int totalVentas = 0;

    double dineroTotal = 0;
    double totalDescuentos = 0;
    double totalBruto = 0;

    double ventaMayor = 0;
    double ventaMenor = 0;
    double promedioVenta = 0;

    do {
        cout << "\n--- TIENDITA DE BARRIO ---" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "Seleccione una opcion: ";

        while (!(cin >> opcion)) {
            cout << "Error: Ingrese una opcion numerica: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        else if (opcion == 1) {
            double precio = -1;
            int cantidad = 0;
            double subtotalVenta = 0;
            double descuento = 0;
            double totalPagar = 0;

            cout << "\n--- NUEVA VENTA (0 para terminar) ---" << endl;

            while (precio != 0) {
                cout << "Precio del producto: Q";

                while (!(cin >> precio) || precio < 0) {
                    cout << "Error: Ingrese un precio valido y no negativo: Q";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (precio != 0) {
                    cout << "Cantidad (1-100): ";

                    while (!(cin >> cantidad) || cantidad < 1 || cantidad > 100) {
                        cout << "Error: Ingrese una cantidad entre 1 y 100: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    subtotalVenta += precio * cantidad;
                }
            }

            if (subtotalVenta > 0) {

                if (subtotalVenta >= 1000) {
                    descuento = subtotalVenta * 0.10;
                }
                else if (subtotalVenta >= 500) {
                    descuento = subtotalVenta * 0.05;
                }

                totalPagar = subtotalVenta - descuento;

                totalVentas++;
                totalBruto += subtotalVenta;
                dineroTotal += totalPagar;
                totalDescuentos += descuento;

                if (totalVentas == 1) {
                    ventaMayor = totalPagar;
                    ventaMenor = totalPagar;
                }
                else {
                    if (totalPagar > ventaMayor) {
                        ventaMayor = totalPagar;
                    }

                    if (totalPagar < ventaMenor) {
                        ventaMenor = totalPagar;
                    }
                }

                cout << fixed << setprecision(2);
                cout << "\n--- FACTURA DE VENTA ---" << endl;
                cout << "Subtotal: Q" << subtotalVenta << endl;
                cout << "Descuento aplicado: Q" << descuento << endl;
                cout << "Total a pagar: Q" << totalPagar << endl;
                cout << "\nVenta registrada correctamente." << endl;
            }
            else {
                cout << "\nNo se registro ninguna venta." << endl;
            }
        }
        else if (opcion == 2) {
            cout << fixed << setprecision(2);

            cout << "\n--- RESUMEN PARCIAL DE CAJA ---" << endl;
            cout << "Total de ventas: " << totalVentas << endl;
            cout << "Total bruto: Q" << totalBruto << endl;
            cout << "Descuentos acumulados: Q" << totalDescuentos << endl;
            cout << "Dinero recaudado: Q" << dineroTotal << endl;

            if (totalVentas > 0) {
                promedioVenta = dineroTotal / totalVentas;

                cout << "Promedio por venta: Q" << promedioVenta << endl;
                cout << "Venta mayor: Q" << ventaMayor << endl;
                cout << "Venta menor: Q" << ventaMenor << endl;
            }
            else {
                cout << "Todavia no se han registrado ventas." << endl;
            }
        }

    } while (opcion != 3);

    cout << fixed << setprecision(2);

    cout << "\n================================" << endl;
    cout << "       REPORTE FINAL DE CAJA" << endl;
    cout << "================================" << endl;

    cout << "Ventas realizadas: " << totalVentas << endl;
    cout << "Total bruto: Q" << totalBruto << endl;
    cout << "Descuentos otorgados: Q" << totalDescuentos << endl;
    cout << "Total neto recaudado: Q" << dineroTotal << endl;

    if (totalVentas > 0) {
        promedioVenta = dineroTotal / totalVentas;

        cout << "Promedio por venta: Q" << promedioVenta << endl;
        cout << "Venta mayor: Q" << ventaMayor << endl;
        cout << "Venta menor: Q" << ventaMenor << endl;
    }
    else {
        cout << "No se realizaron ventas durante el dia." << endl;
    }

    cout << "================================" << endl;
    cout << "Caja cerrada correctamente." << endl;

    return 0;
}