#include <iostream>

using namespace std;

int main() {
    int opcion = 0;
    int totalVentas = 0;
    double dineroTotal = 0;
    double totalDescuentos = 0;
    double v_mayor = -1; 
    double v_menor = -1; 

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

            if (subtotalVenta > 0) {
                double porc_desc = 0;

                if (subtotalVenta < 100) {
                    porc_desc = 0.0;
                } else if (subtotalVenta >= 100 && subtotalVenta < 500) {
                    porc_desc = 0.05;
                } else {
                    porc_desc = 0.10;
                }

                double desc = subtotalVenta * porc_desc;
                double sub_con_desc = subtotalVenta - desc;
                double iva = sub_con_desc * 0.12;
                double total = sub_con_desc + iva;

                cout << "\nTotal a pagar: Q" << total << endl;
                
                double pago = 0;
                cout << "Monto recibido: Q";
                cin >> pago;

                while (pago < total) {
                    cout << "Error: Dinero insuficiente. Ingrese un monto valido: Q";
                    cin >> pago;
                }

                double cambio = pago - total;

                cout << "\n--- RECIBO ---" << endl;
                cout << "Subtotal: Q" << subtotalVenta << endl;
                cout << "Descuento: Q" << desc << endl;
                cout << "IVA (12%): Q" << iva << endl;
                cout << "TOTAL: Q" << total << endl;
                cout << "Pago: Q" << pago << endl;
                cout << "Cambio: Q" << cambio << endl;

                totalVentas++;
                dineroTotal += total;
                totalDescuentos += desc;

                if (v_mayor == -1 || total > v_mayor) {
                    v_mayor = total;
                }
                if (v_menor == -1 || total < v_menor) {
                    v_menor = total;
                }
            } else {
                cout << "No se agregaron productos a la venta." << endl;
            }
        } 
        else if (opcion == 2) {
            cout << "\n--- RESUMEN PARCIAL ---" << endl;
            if (totalVentas == 0) {
                cout << "No se han realizado ventas todavia." << endl;
            } else {
                double promedio = dineroTotal / totalVentas;
                cout << "Cantidad de ventas: " << totalVentas << endl;
                cout << "Total dinero: Q" << dineroTotal << endl;
                cout << "Total descuentos: Q" << totalDescuentos << endl;
                cout << "Venta mayor: Q" << v_mayor << endl;
                cout << "Venta menor: Q" << v_menor << endl;
                cout << "Promedio: Q" << promedio << endl;
            }
        }

    } while (opcion != 3);

    cout << "\nCaja cerrada correctamente. Saliendo..." << endl;
    return 0;
}