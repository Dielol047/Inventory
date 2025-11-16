#ifndef INVENTARIO_H
#define INVENTARIO_H
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

int ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int maxProductos);
float calcularPrecioTotal(float precios[], int numProductos);
int encontrarProductoMasCaro(float precios[], int numProductos);
int encontrarProductoMasBarato(float precios[], int numProductos);
float calcularPrecioPromedio(float total, int numProductos);
int buscarProductoPorNombre(char nombres[][MAX_NOMBRE], char nombreBuscado[], int numProductos);
void editarProducto(char nombres[][MAX_NOMBRE], float precios[], int numProductos);

#endif 