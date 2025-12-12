#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para el producto
typedef struct {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// Prototipos de funciones
Producto* cargar_inventario(int *n);
void guardar_producto(Producto p);
void imprimir_inventario(Producto *inventario, int n);
void liberar_memoria(Producto *inventario);
void limpiar_buffer();

int main() {
    int n = 0;
    Producto *inventario = NULL;
    int opcion;
    char respuesta;

    // Cargar inventario al inicio
    inventario = cargar_inventario(&n);

    do {
        system("cls"); // Limpiar pantalla (Windows)
        printf("\n=================================\n");
        printf("       SISTEMA DE INVENTARIO     \n");
        printf("=================================\n");
        printf("1. Ver inventario\n");
        printf("2. Agregar producto nuevo\n");
        printf("3. Salir\n");
        printf("=================================\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            limpiar_buffer();
            opcion = 0; // Forzar opcion invalida
        }

        if (opcion == 1) {
            imprimir_inventario(inventario, n);
            system("pause");
        } else if (opcion == 2) {
            Producto nuevo;
            printf("\n--- NUEVO PRODUCTO ---\n");
            
            printf("Ingrese ID del producto: ");
            scanf("%d", &nuevo.id);
            limpiar_buffer();
            
            printf("Ingrese nombre del producto: ");
            // Leer string con espacios de forma segura
            fgets(nuevo.nombre, 50, stdin);
            nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; // Quitar salto de linea
            
            printf("Ingrese cantidad: ");
            scanf("%d", &nuevo.cantidad);
            
            printf("Ingrese precio: ");
            scanf("%f", &nuevo.precio);

            // Guardar en archivo
            guardar_producto(nuevo);

            // Recargar inventario para tener los datos actualizados en memoria
            liberar_memoria(inventario);
            inventario = cargar_inventario(&n);
            printf("\nProducto agregado exitosamente.\n");
            system("pause");
        } else if (opcion != 3) {
            printf("\nOpcion no valida.\n");
            system("pause");
        }

    } while (opcion != 3);

    // Liberar memoria antes de salir
    liberar_memoria(inventario);
    return 0;
}

Producto* cargar_inventario(int *n) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        *n = 0;
        return NULL;
    }

    // Contar lineas para saber cuantos productos hay
    int contador = 0;
    char buffer[100];
    while (fgets(buffer, 100, archivo) != NULL) {
        contador++;
    }
    rewind(archivo); // Volver al inicio del archivo

    *n = contador;
    if (contador == 0) {
        fclose(archivo);
        return NULL;
    }

    // Usar memoria dinamica
    Producto *inv = (Producto *)malloc(contador * sizeof(Producto));
    if (inv == NULL) {
        printf("Error de memoria.\n");
        exit(1);
    }

    for (int i = 0; i < contador; i++) {
        // Leer datos del archivo con formato: id;nombre;cantidad;precio
        // %[^;] lee todo hasta encontrar un ;
        fscanf(archivo, "%d;%[^;];%d;%f\n", &inv[i].id, inv[i].nombre, &inv[i].cantidad, &inv[i].precio);
    }

    fclose(archivo);
    return inv;
}

void guardar_producto(Producto p) {
    FILE *archivo = fopen("inventario.txt", "a"); // 'a' para agregar al final
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    // Usar ; como separador para permitir espacios en el nombre
    fprintf(archivo, "%d;%s;%d;%.2f\n", p.id, p.nombre, p.cantidad, p.precio);
    fclose(archivo);
}

void imprimir_inventario(Producto *inventario, int n) {
    if (n == 0 || inventario == NULL) {
        printf("\nEl inventario esta vacio.\n");
        return;
    }
    printf("\n%-5s | %-20s | %-10s | %-10s\n", "ID", "NOMBRE", "CANTIDAD", "PRECIO");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d | %-20s | %-10d | $%-9.2f\n", 
               inventario[i].id, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
    printf("------------------------------------------------------\n");
}

void liberar_memoria(Producto *inventario) {
    if (inventario != NULL) {
        free(inventario);
    }
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
