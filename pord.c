#include <stdio.h>
#include <string.h> 
#include "inventario.h"


#include <stdio.h>
#include <string.h> 


#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

#include <stdio.h>
#include <string.h> 


#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

int ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int maxProductos) {
    int i;
    int j; 
    int esPrecioValido;
    int nombreRepetido; 

    for (i = 0; i < maxProductos; i++) {

        
        do {
            nombreRepetido = 0; 
            printf("\nIngrese el nombre del producto %d (o escriba 'fin' para terminar): ", i + 1);
            scanf(" %[^\n]", nombres[i]);

            
            if (strcmp(nombres[i], "fin") == 0) {
                return i; 
            }

            
            
            for (j = 0; j < i; j++) {
                
                if (strcmp(nombres[j], nombres[i]) == 0) {
                    printf("Error: El producto '%s' ya ha sido ingresado. Por favor, use otro nombre.\n", nombres[i]);
                    nombreRepetido = 1; 
                    break; 
                }
            }
        } while (nombreRepetido); 


       
        do {
            printf("Ingrese el precio de '%s': ", nombres[i]);
            esPrecioValido = 1; 

            if (scanf("%f", &precios[i]) != 1) {
                printf("Entrada invalida. Por favor, ingrese un valor numerico.\n");
                esPrecioValido = 0;
                while(getchar() != '\n');
            }
            else if (precios[i] <= 0) {
                printf("Error: El precio debe ser un numero positivo (mayor que cero).\n");
                esPrecioValido = 0;
            }

        } while (!esPrecioValido); 
    }
    return i; 
}

float calcularPrecioTotal(float precios[], int numProductos) {
    float total = 0.0;
    int i;
    for (i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

// --- Añade esta función en inventario.c ---

void editarProducto(char nombres[][MAX_NOMBRE], float precios[], int numProductos) {
    char nombreBuscado[MAX_NOMBRE];
    int indice;
    int opcionEdicion;

 
    if (numProductos == 0) {
        printf("\nNo hay productos en el inventario para editar.\n");
        return; // Salir de la función
    }

    printf("\n--- Editar Producto ---\n");
    printf("Ingrese el nombre del producto que desea editar: ");
    scanf(" %[^\n]", nombreBuscado);

    
    indice = buscarProductoPorNombre(nombres, nombreBuscado, numProductos);

    
    if (indice == -1) {
        printf("Error: El producto '%s' no se encontro en el inventario.\n", nombreBuscado);
        return;
    }

   
    printf("Producto encontrado: %s | Precio actual: %.2f\n", nombres[indice], precios[indice]);
    printf("Que desea editar?\n");
    printf("1. Editar nombre\n");
    printf("2. Editar precio\n");
    printf("3. Cancelar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcionEdicion);

    switch (opcionEdicion) {
        case 1: { 
            char nuevoNombre[MAX_NOMBRE];
            int nombreRepetido;
            int j;

            do {
                nombreRepetido = 0;
                printf("Ingrese el nuevo nombre para '%s': ", nombres[indice]);
                scanf(" %[^\n]", nuevoNombre);

                
                for (j = 0; j < numProductos; j++) {
                    if (strcmp(nombres[j], nuevoNombre) == 0 && j != indice) {
                        printf("Error: Ya existe otro producto con el nombre '%s'.\n", nuevoNombre);
                        nombreRepetido = 1;
                        break;
                    }
                }
            } while (nombreRepetido);

            
            strcpy(nombres[indice], nuevoNombre);
            printf(">> El nombre ha sido actualizado correctamente.\n");
            break;
        }
        case 2: { 
            float nuevoPrecio;
            int esPrecioValido;

            do {
                printf("Ingrese el nuevo precio para '%s': ", nombres[indice]);
                esPrecioValido = 1;

                if (scanf("%f", &nuevoPrecio) != 1) {
                    printf("Entrada invalida. Por favor, ingrese un valor numerico.\n");
                    esPrecioValido = 0;
                    while(getchar() != '\n');
                } else if (nuevoPrecio <= 0) {
                    printf("Error: El precio debe ser un numero positivo.\n");
                    esPrecioValido = 0;
                }
            } while (!esPrecioValido);

            
            precios[indice] = nuevoPrecio;
            printf(">> El precio ha sido actualizado correctamente.\n");
            break;
        }
        case 3: 
            printf("Operacion cancelada.\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }
}


int encontrarProductoMasCaro(float precios[], int numProductos) {
    int indiceCaro = 0;
    int i;
    for (i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceCaro]) {
            indiceCaro = i;
        }
    }
    return indiceCaro;
}


int encontrarProductoMasBarato(float precios[], int numProductos) {
    int indiceBarato = 0;
    int i;
    for (i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceBarato]) {
            indiceBarato = i;
        }
    }
    return indiceBarato;
}

float calcularPrecioPromedio(float total, int numProductos) {
    if (numProductos == 0) {
        return 0.0;
    }
    return total / numProductos;
}


int buscarProductoPorNombre(char nombres[][MAX_NOMBRE], char nombreBuscado[], int numProductos) {
    int i;
    for (i = 0; i < numProductos; i++) {
        
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return i; 
        }
    }
    return -1; 
}