

#include <stdio.h>
#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos;
    int opcion;

    printf("========================================\n");
    printf("   Gestion de Inventario de la Tienda   \n");
    printf("========================================\n");

    numProductos = ingresarDatos(nombres, precios, MAX_PRODUCTOS);

    if (numProductos == 0) {
        printf("\nNo se ingresaron productos. Saliendo del programa.\n");
        return 0;
    }

    
    do {
        printf("\n\n--- MENU DE OPERACIONES ---\n");
        printf("1. Calcular precio total del inventario\n");
        printf("2. Mostrar producto mas caro y mas barato\n");
        printf("3. Calcular precio promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Editar producto\n"); 
        printf("6. Salir\n");           
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float total = calcularPrecioTotal(precios, numProductos);
                printf("\n>> El precio total del inventario es: %.2f\n", total);
                break;
            }
            case 2: {
                int indiceCaro = encontrarProductoMasCaro(precios, numProductos);
                int indiceBarato = encontrarProductoMasBarato(precios, numProductos);
                printf("\n>> Producto mas caro: %s (Precio: %.2f)\n", nombres[indiceCaro], precios[indiceCaro]);
                printf(">> Producto mas barato: %s (Precio: %.2f)\n", nombres[indiceBarato], precios[indiceBarato]);
                break;
            }
            case 3: {
                float total = calcularPrecioTotal(precios, numProductos);
                float promedio = calcularPrecioPromedio(total, numProductos);
                printf("\n>> El precio promedio de los productos es: %.2f\n", promedio);
                break;
            }
            case 4: {
                char nombreBuscado[MAX_NOMBRE];
                printf("\nIngrese el nombre del producto a buscar: ");
                scanf(" %[^\n]", nombreBuscado);
                int indice = buscarProductoPorNombre(nombres, nombreBuscado, numProductos);
                if (indice != -1) {
                    printf(">> Producto encontrado: %s, Precio: %.2f\n", nombres[indice], precios[indice]);
                } else {
                    printf(">> El producto '%s' no se encontro en el inventario.\n", nombreBuscado);
                }
                break;
            }
            
            case 5: {
                editarProducto(nombres, precios, numProductos);
                break;
            }
            
            case 6:
                printf("\nSaliendo del programa. ¡Adios!\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, intente de nuevo.\n");
                break;
        }
    } while (opcion != 6); 

    return 0;
}