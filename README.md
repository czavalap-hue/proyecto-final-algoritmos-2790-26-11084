# proyecto-final-algoritmos-2790-26-11084

# TIENDITA DE BARRIO

## 1. Descripción del proyecto

Tiendita de Barrio es un programa desarrollado en C++ que permite administrar las ventas de una pequeña tienda.

El programa permite registrar productos, calcular subtotales, aplicar descuentos según el monto de la compra, validar los pagos recibidos y calcular el cambio que debe entregarse al cliente.

También permite consultar un resumen parcial de las ventas y generar un reporte final al cerrar la caja.

## 2. Lenguaje utilizado

- **Lenguaje:** C++
- **Bibliotecas utilizadas:**
  - `iostream`: entrada y salida de datos.
  - `iomanip`: formato de números decimales.
  - `sstream`: validación de entradas.
  - `string`: manejo de cadenas de texto.

## 3. Funcionalidades del programa

- Registrar ventas de productos.
- Ingresar precios y cantidades.
- Validar que los precios no sean negativos.
- Validar cantidades entre 1 y 100.
- Aplicar descuentos automáticamente:
  - Menos de Q100.00: sin descuento.
  - Desde Q100.00 hasta Q499.99: 5 % de descuento.
  - Desde Q500.00 en adelante: 10 % de descuento.
- Solicitar el pago del cliente.
- Rechazar pagos menores al total de la compra.
- Calcular el cambio.
- Consultar el resumen parcial de ventas.
- Mostrar el reporte final de caja.

## 4. Cómo compilar y ejecutar

Para ejecutar el programa se necesita un compilador de C++, como MinGW (g++) o el compilador de Visual Studio.

### Utilizando la terminal con g++

1. Abrir la carpeta del proyecto en Visual Studio Code.
2. Abrir la terminal.
3. Ejecutar el siguiente comando para compilar:

```bash
g++ main.cpp -o tiendita
```

4. Ejecutar el programa en Windows:

```powershell
.\tiendita.exe
```

También se puede abrir el proyecto en Visual Studio, compilarlo y ejecutarlo desde el entorno de desarrollo.

## 5. Pruebas realizadas

Se realizaron las siguientes pruebas para comprobar el funcionamiento del programa.

### Prueba 1: Venta de Q99.99 y Q100.00

**Objetivo:** Comprobar que los descuentos se apliquen correctamente según el subtotal.

- Venta de Q99.99: no aplica descuento.
- Venta de Q100.00: aplica un descuento del 5 %, equivalente a Q5.00.
- Total a pagar por Q100.00: Q95.00.

**Resultado esperado:** El programa aplica correctamente los descuentos establecidos.

![Prueba 1](<Capturas de codigo/Primera captura de codigo .png>) ![Prueba 1](<Capturas de codigo/Segunda captura de codigo .png>)


### Prueba 2: Venta de Q500.00

**Objetivo:** Comprobar el descuento del 10 %.

- Subtotal: Q500.00.
- Descuento aplicado: Q50.00.
- Total a pagar: Q450.00.

**Resultado esperado:** El programa aplica correctamente el descuento del 10 %.

![Prueba dos](<Capturas de codigo/Tercera captura de codigo .png>) 

### Prueba 3: Validación de datos incorrectos

**Objetivo:** Comprobar que el programa no permita ingresar datos inválidos.

Se realizaron las siguientes pruebas:

- Cantidad 0: rechazada.
- Cantidad 101: rechazada.
- Precio negativo: rechazado.
- Opción de menú 9: rechazada.

**Resultado esperado:** El programa muestra mensajes de error y solicita nuevamente los datos.

![Prueba tres](<Capturas de codigo/Cuarta captura de codigo .png>) ![Prueba 3](<Capturas de codigo/Quinta captura de codigo .png>)


### Prueba 4: Resumen del día sin ventas

**Objetivo:** Comprobar el funcionamiento del resumen cuando todavía no se han registrado ventas.

**Resultado esperado:**
- Ventas realizadas: 0.
- Total bruto: Q0.00.
- Descuentos acumulados: Q0.00.
- Dinero recaudado: Q0.00.
- Mensaje indicando que todavía no se han registrado ventas.

![Prueba 4](<Capturas de codigo/Sexta captura de codigo .png>)

### Prueba 5: Pago menor al total

**Objetivo:** Comprobar que el programa valide el dinero recibido del cliente.

Se ingresa inicialmente una cantidad menor al total de la compra.

**Resultado esperado:**
- El programa muestra un mensaje de pago insuficiente.
- Solicita nuevamente el monto recibido.
- Cuando el pago es suficiente, calcula el cambio correctamente.

![Prueba 5](<Capturas de codigo/Septima captura de codigo .png>)

## 6. Uso de IA

**Herramienta utilizada:** ChatGPT.

Se utilizó como herramienta de apoyo durante el desarrollo y revisión del programa.

**Preguntas realizadas:**

- ¿Cómo validar que los precios y cantidades ingresados sean correctos?
- ¿Cómo aplicar descuentos según el subtotal de una venta?
- ¿Cómo validar que el pago recibido sea suficiente?
- ¿Cómo calcular el cambio y mostrar un resumen de ventas?

**Sugerencias aceptadas:**

- Mejorar la validación de los datos ingresados.
- Aplicar automáticamente los descuentos del 5 % y 10 %.
- Incorporar la validación del pago recibido.
- Mostrar el cambio y mejorar la presentación de la factura.

**Sugerencias rechazadas:**

Se descartó mantener los porcentajes y límites de descuento de la versión inicial, porque no coincidían con los requisitos establecidos para el proyecto. Se ajustaron los rangos para aplicar el 5 % desde Q100.00 y el 10 % desde Q500.00.

La IA se utilizó como apoyo para comprender y corregir el código. Se revisaron las sugerencias y se realizaron pruebas para comprobar su funcionamiento.

## 7. Conclusión

El proyecto permitió aplicar los conocimientos de programación en C++, utilizando variables, estructuras condicionales, ciclos, funciones y validaciones de datos.

Además, se desarrolló un sistema básico para administrar las ventas de una tienda, calcular descuentos, validar pagos y generar reportes de caja.