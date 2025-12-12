#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    int anio;
    float precio;
    char titulo[100];
    char autor[100];
    char descripcion[200];
} Libro;

struct Nodo {
    Libro dato;
    struct Nodo* siguiente;
};

// Prototipos
struct Nodo* cargar_lista();
void guardar_lista(struct Nodo* cabeza);
void agregar_libro(struct Nodo** cabeza);
void buscar_libro(struct Nodo* cabeza);
void imprimir_lista(struct Nodo* cabeza);
void liberar_lista(struct Nodo* cabeza);
void pausar();
void limpiar_buffer();

// Helper para leer strings con espacios
void leer_string(char* buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Quitar salto de linea
}

int main() {
    struct Nodo* lista_libros = NULL;
    int opcion;

    // Cargar lista del disco al inicio
    lista_libros = cargar_lista();

    do {
        system("cls");
        printf("\n==================================\n");
        printf("    SISTEMA DE GESTION DE LIBROS  \n");
        printf("==================================\n");
        printf("1. Ver todos los libros\n");
        printf("2. Agregar libro\n");
        printf("3. Buscar libro (Titulo o Autor)\n");
        printf("4. Guardar y Salir\n");
        printf("==================================\n");
        printf("Seleccione: ");
        
        if (scanf("%d", &opcion) != 1) {
            opcion = 0;
        }
        limpiar_buffer(); // Consumir el enter o limpiar entrada invalida

        switch(opcion) {
            case 1: imprimir_lista(lista_libros); pausar(); break;
            case 2: agregar_libro(&lista_libros); pausar(); break;
            case 3: buscar_libro(lista_libros); pausar(); break;
            case 4: 
                guardar_lista(lista_libros);
                liberar_lista(lista_libros);
                printf("Guardado y saliendo...\n");
                break;
            default: printf("Opcion invalida.\n"); pausar();
        }
    } while (opcion != 4);

    return 0;
}

struct Nodo* cargar_lista() {
    FILE* archivo = fopen("libros.txt", "r");
    if (archivo == NULL) return NULL;

    struct Nodo* cabeza = NULL;
    struct Nodo* ultimo = NULL;
    Libro temp;
    char buffer[20];

    // Formato de archivo: Codigo \n Anio \n Precio \n Titulo \n Autor \n Descripcion \n
    while (fgets(buffer, 20, archivo) != NULL) {
        temp.codigo = atoi(buffer);
        
        fgets(buffer, 20, archivo);
        temp.anio = atoi(buffer);
        
        fgets(buffer, 20, archivo);
        temp.precio = atof(buffer);
        
        fgets(temp.titulo, 100, archivo);
        temp.titulo[strcspn(temp.titulo, "\n")] = 0;
        
        fgets(temp.autor, 100, archivo);
        temp.autor[strcspn(temp.autor, "\n")] = 0;
        
        fgets(temp.descripcion, 200, archivo);
        temp.descripcion[strcspn(temp.descripcion, "\n")] = 0;

        // Crear nodo
        struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
        nuevo->dato = temp;
        nuevo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    fclose(archivo);
    return cabeza;
}

void guardar_lista(struct Nodo* cabeza) {
    FILE* archivo = fopen("libros.txt", "w");
    if (archivo == NULL) {
        printf("Error al guardar.\n");
        return;
    }

    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        fprintf(archivo, "%d\n", actual->dato.codigo);
        fprintf(archivo, "%d\n", actual->dato.anio);
        fprintf(archivo, "%.2f\n", actual->dato.precio);
        fprintf(archivo, "%s\n", actual->dato.titulo);
        fprintf(archivo, "%s\n", actual->dato.autor);
        fprintf(archivo, "%s\n", actual->dato.descripcion);
        actual = actual->siguiente;
    }
    fclose(archivo);
}

void agregar_libro(struct Nodo** cabeza) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    printf("\n--- AGREGAR NUEVO LIBRO ---\n");
    printf("1. Codigo: "); scanf("%d", &nuevo->dato.codigo);
    printf("2. Anio:   "); scanf("%d", &nuevo->dato.anio);
    printf("3. Precio: "); scanf("%f", &nuevo->dato.precio);
    
    limpiar_buffer(); // Limpiar buffer antes de leer strings

    printf("4. Titulo: "); leer_string(nuevo->dato.titulo, 100);
    printf("5. Autor:  "); leer_string(nuevo->dato.autor, 100);
    printf("6. Descripcion: "); leer_string(nuevo->dato.descripcion, 200);

    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("\nLibro agregado exitosamente.\n");
}

void buscar_libro(struct Nodo* cabeza) {
    char busqueda[100];
    printf("\n--- BUSQUEDA DE LIBROS ---\n");
    printf("Ingrese Titulo o Autor a buscar: ");
    leer_string(busqueda, 100);

    struct Nodo* actual = cabeza;
    int encontrado = 0;
    while (actual != NULL) {
        // strstr busca si la subcadena existe (busqueda parcial)
        if (strstr(actual->dato.titulo, busqueda) != NULL || strstr(actual->dato.autor, busqueda) != NULL) {
            printf("\n--- ENCONTRADO ---\n");
            printf("Codigo: %d\nTitulo: %s\nAutor: %s\nPrecio: %.2f\n", 
                   actual->dato.codigo, actual->dato.titulo, actual->dato.autor, actual->dato.precio);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) printf("\nNo se encontraron coincidencias.\n");
}

void imprimir_lista(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("\nLista vacia.\n");
        return;
    }
    
    printf("\n%-8s | %-6s | %-10s | %-30s | %-20s\n", "CODIGO", "ANIO", "PRECIO", "TITULO", "AUTOR");
    printf("----------------------------------------------------------------------------------------\n");

    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%-8d | %-6d | $%-9.2f | %-30s | %-20s\n", 
               actual->dato.codigo, 
               actual->dato.anio, 
               actual->dato.precio, 
               actual->dato.titulo, 
               actual->dato.autor);
        actual = actual->siguiente;
    }
    printf("----------------------------------------------------------------------------------------\n");
}

void liberar_lista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

void pausar() {
    printf("\n");
    system("pause");
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
