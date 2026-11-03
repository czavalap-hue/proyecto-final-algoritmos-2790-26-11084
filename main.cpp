
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// Funcion para leer numeros decimales
double leerDouble(string mensaje, double minimo) {
    string entrada;
    double valor;
    char sobrante;

    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        stringstream ss(entrada);

        if (ss >> valor && !(ss >> sobrante) && valor >= minimo) {
            return valor;
        }

        cout << "Error: Ingrese un numero valido y no negativo." << endl;
    }
}

// Funcion para leer numeros enteros
int leerEntero(string mensaje, int minimo, int maximo) {
    string entrada;
    int valor;
    char sobrante;

    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        stringstream ss(entrada);

        if (ss >> valor && !(ss >> sobrante)
            && valor >= minimo && valor <= maximo) {
            return valor;
        }

        cout << "Error: Ingrese un numero entero entre "
             << minimo << " y " << maximo << "." << endl;
    }
}

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

        cout << "\n================================" << endl;
        cout << "       TIENDITA DE BARRIO" << endl;
        cout << "================================" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "================================" << endl;

        opcion = leerEntero("Seleccione una opcion: ", 1, 3);

        if (opcion == 1) {

            double precio = -1;
            int cantidad = 0;

            double subtotalVenta = 0;
            double descuento = 0;
            double totalPagar = 0;
            double pago = 0;
            double cambio = 0;

            cout << "\n--- NUEVA VENTA ---" << endl;
            cout << "Ingrese 0 en el precio para terminar." << endl;

            while (precio != 0) {

                precio = leerDouble("Precio del producto: Q", 0);

                if (precio != 0) {

                    cantidad = leerEntero("Cantidad (1-100): ", 1, 100);

                    subtotalVenta += precio * cantidad;
                }
            }

            if (subtotalVenta > 0) {

                // Aplicar descuentos segun el subtotal

                if (subtotalVenta >= 500) {
                    descuento = subtotalVenta * 0.10;
                }
                else if (subtotalVenta >= 100) {
                    descuento = subtotalVenta * 0.05;
                }
                else {
                    descuento = 0;
                }

                // Calcular total a pagar
                totalPagar = subtotalVenta - descuento;

                // Solicitar pago y validar
                do {

                    pago = leerDouble("Ingrese el dinero recibido: Q", 0);

                    if (pago < totalPagar) {

                        cout << fixed << setprecision(2);

                        cout << "Pago insuficiente. Faltan Q"
                             << totalPagar - pago << endl;
                    }

                } while (pago < totalPagar);

                // Calcular cambio
                cambio = pago - totalPagar;

                // Actualizar acumuladores
                totalVentas++;
                totalBruto += subtotalVenta;
                dineroTotal += totalPagar;
                totalDescuentos += descuento;

                // Identificar venta mayor y menor
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

                // Mostrar factura
                cout << fixed << setprecision(2);

                cout << "\n========== FACTURA ==========" << endl;
                cout << "Subtotal: Q" << subtotalVenta << endl;
                cout << "Descuento aplicado: Q" << descuento << endl;
                cout << "Total a pagar: Q" << totalPagar << endl;
                cout << "Pago recibido: Q" << pago << endl;
                cout << "Cambio: Q" << cambio << endl;
                cout << "=============================" << endl;

                cout << "Venta registrada correctamente." << endl;
            }
            else {

                cout << "\nNo se registro ninguna venta." << endl;
            }
        }

        else if (opcion == 2) {

            cout << fixed << setprecision(2);

            cout << "\n====== RESUMEN PARCIAL ======" << endl;
            cout << "Ventas realizadas: " << totalVentas << endl;
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

            cout << "=============================" << endl;
        }

    } while (opcion != 3);

    // Reporte final
    cout << fixed << setprecision(2);

    cout << "\n================================" << endl;
    cout << "        REPORTE FINAL DE CAJA" << endl;
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
    cout << "         CAJA CERRADA" << endl;
    cout << "================================" << endl;

    return 0;
}

