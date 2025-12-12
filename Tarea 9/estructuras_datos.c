#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ESTRUCTURAS DE DATOS ---

// 1. Lista Enlazada
struct NodoLista {
    int dato;
    struct NodoLista* sig;
};

void ejemplo_lista() {
    printf("\n--- EJEMPLO LISTA ENLAZADA ---\n");
    struct NodoLista* cabeza = NULL;
    struct NodoLista* uno = (struct NodoLista*)malloc(sizeof(struct NodoLista));
    struct NodoLista* dos = (struct NodoLista*)malloc(sizeof(struct NodoLista));
    struct NodoLista* tres = (struct NodoLista*)malloc(sizeof(struct NodoLista));

    if (!uno || !dos || !tres) return; // Verificacion simple

    uno->dato = 10;
    dos->dato = 20;
    tres->dato = 30;

    cabeza = uno;
    uno->sig = dos;
    dos->sig = tres;
    tres->sig = NULL;

    struct NodoLista* temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    }
    printf("NULL\n");
    
    // Liberar (simple)
    free(uno); free(dos); free(tres);
}

// 2. Pila (Stack)
#define MAX 5
struct Pila {
    int items[MAX];
    int top;
};

void ejemplo_pila() {
    printf("\n--- EJEMPLO PILA (LIFO) ---\n");
    struct Pila s;
    s.top = -1;

    // Push
    s.items[++s.top] = 10;
    printf("Push(10)\n");
    s.items[++s.top] = 20;
    printf("Push(20)\n");

    // Pop
    printf("Pop() -> %d\n", s.items[s.top--]);
    printf("Pop() -> %d\n", s.items[s.top--]);
}

// 3. Cola (Queue)
struct Cola {
    int items[MAX];
    int front, rear;
};

void ejemplo_cola() {
    printf("\n--- EJEMPLO COLA (FIFO) ---\n");
    struct Cola q;
    q.front = -1;
    q.rear = -1;

    // Enqueue
    if (q.front == -1) q.front = 0;
    q.items[++q.rear] = 100;
    printf("Enqueue(100)\n");
    q.items[++q.rear] = 200;
    printf("Enqueue(200)\n");

    // Dequeue
    printf("Dequeue() -> %d\n", q.items[q.front++]);
    printf("Dequeue() -> %d\n", q.items[q.front++]);
}

// 4. Arbol Binario
struct NodoArbol {
    int dato;
    struct NodoArbol *izq, *der;
};

struct NodoArbol* nuevoNodo(int dato) {
    struct NodoArbol* nodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    if (!nodo) return NULL;
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void inorden(struct NodoArbol* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void ejemplo_arbol() {
    printf("\n--- EJEMPLO ARBOL BINARIO ---\n");
    struct NodoArbol *raiz = nuevoNodo(1);
    raiz->izq = nuevoNodo(2);
    raiz->der = nuevoNodo(3);
    raiz->izq->izq = nuevoNodo(4);

    printf("Estructura:\n    1\n   / \\\n  2   3\n /\n4\n");
    printf("Recorrido Inorden (Izq-Raiz-Der): ");
    inorden(raiz);
    printf("\n");
    // Nota: faltaria liberar memoria recursivamente
}

// 5. Grafo (Matriz de Adyacencia)
void ejemplo_grafo() {
    printf("\n--- EJEMPLO GRAFO (Matriz) ---\n");
    int grafo[3][3] = {
        {0, 1, 0}, // Nodo 0 conecta con 1
        {1, 0, 1}, // Nodo 1 conecta con 0 y 2
        {0, 1, 0}  // Nodo 2 conecta con 1
    };
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (grafo[i][j] == 1) {
                printf("Nodo %d esta conectado con Nodo %d\n", i, j);
            }
        }
    }
}

// 6. Tabla Hash
void ejemplo_hash() {
    printf("\n--- EJEMPLO TABLA HASH ---\n");
    int tabla[10];
    for(int i=0; i<10; i++) tabla[i] = -1; // Inicializar

    // Insertar claves 15, 25, 35 con hash(x) = x % 10
    tabla[15 % 10] = 15; // Indice 5
    printf("Insertar 15 -> Hash(15) = 5\n");
    
    // Colision simple (reemplazo)
    printf("Insertar 25 -> Hash(25) = 5 (Colision! Reemplazando...)\n");
    tabla[25 % 10] = 25; 
    
    printf("Valor en tabla[5] = %d\n", tabla[5]);
}

void resumen_capitulo() {
    printf("\n--- RESUMEN CAPITULO 9: ESTRUCTURAS DE DATOS ---\n");
    printf("En este capitulo se estudian las formas de organizar datos en la computadora.\n\n");
    printf("1. Listas Enlazadas: Coleccion de nodos donde cada uno apunta al siguiente.\n");
    printf("2. Arboles: Estructuras jerarquicas con raiz, ramas y hojas. Utiles para busquedas.\n");
    printf("3. Grafos: Conjunto de nodos (vertices) y enlaces (aristas). Modelan redes.\n");
    printf("4. Pilas y Colas: Estructuras lineales con reglas de acceso LIFO y FIFO respectivamente.\n");
    printf("5. Tablas Hash: Arreglos que usan una funcion matematica para calcular el indice de almacenamiento.\n");
}

void pausar() {
    printf("\n");
    system("pause");
}

int main() {
    int opcion;
    do {
        system("cls");
        printf("\n================================\n");
        printf("    TAREA 9: ESTRUCTURAS DATOS  \n");
        printf("================================\n");
        printf("1. Lista Enlazada\n");
        printf("2. Arbol\n");
        printf("3. Grafo\n");
        printf("4. Tabla Hash\n");
        printf("5. Pila\n");
        printf("6. Cola\n");
        printf("7. Resumen Capitulo 9\n");
        printf("8. Salir\n");
        printf("================================\n");
        printf("Seleccione: ");
        
        if (scanf("%d", &opcion) != 1) {
            int c; while((c=getchar())!='\n' && c!=EOF); // Limpiar buffer
            opcion = 0;
        }

        switch(opcion) {
            case 1: ejemplo_lista(); pausar(); break;
            case 2: ejemplo_arbol(); pausar(); break;
            case 3: ejemplo_grafo(); pausar(); break;
            case 4: ejemplo_hash(); pausar(); break;
            case 5: ejemplo_pila(); pausar(); break;
            case 6: ejemplo_cola(); pausar(); break;
            case 7: resumen_capitulo(); pausar(); break;
            case 8: printf("Adios.\n"); break;
            default: printf("Opcion invalida.\n"); pausar();
        }
    } while (opcion != 8);
    return 0;
}
