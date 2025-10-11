#include <stdio.h>

/*Suma matrices.
El programa al recibir como datos dos arreglos bidimencionales del mismo tamaño, calcula la suma de ambos y la almacena en un tercer arreglo bidimencional. */

const int max = 50;

/* Prototipo de funciones.*/
void Lectura(int [][max], int, int);
void Suma (int [][max], int [][max], int [][max], int, int);
void Imprime (int [][max], int, int);

void main(void)
{
    int MA[max][max], MB[max][max], MC[max][max];
    /* Declaracion de los tres arreglos. */
    int FIL, Col;
    do
    {
        printf("Ingrese el numero de filas de los arreglos: ");
        scanf("%d", &FIL);
    }
    while (FIL> max || FIL< 1);
    /* Se verifica que el numero de filas sea correcto. */
    do
    {
        printf("Ingrese el numero de columnas de los arreglos: ");
        scanf("%d", &Col);
    }
    while (Col > max || Col < 1);
    /* Se verifica que el numero de colimnas sea correcto. */
    printf("\nLectura del Arreglo MA\n");
    Lectura(MA, FIL, Col);
    printf("\nLectura de arreglo MB\n");
    Lectura(MB, FIL, Col);
    Suma(MA, MB, MC, FIL, Col);
    printf("\nImpresion del arreglo MC\n");
    Imprime(MC, FIL, Col);
    }

    void Lectura(int A[][max], int F, int C)
    /* La funcion Lectura se utiliza para leer un arreglo budimencional entero de F filas y C columnas. */
    {
        int I, J;
        for (I=0; I<F; I++)
            for (J=0; J<C; J++)
        {
            printf("Ingrese el elemento %d %d:", I+1, J+1);
            scanf("%d", &A[I][J]);
        }
    }
    void Suma(int M1[][max],int M2[][max],int M3[][max], int F, int C)
    /*LA funcion Suma se utiliza para sumar los arreglos y almacenar el resultado en un tercer arreglo bidimencional. */
    {
        int I, J;
        for (I=0; I<F; I++)
            for (J=0; J<C; J++)
        M3[I][J]= M1[I][J] + M2[I][J];
    }
    void Imprime(int A[][max], int F, int C)
    /* La funcion imprime se utiliza para escribir un arreglo bidimencional de tipo entero de F filas y C columnas. */
    {
        int I, J;
        for (I=0; I<F; I++)
            for(J=0; J<C; J++)
            printf("\nElemento %d %d: %d ", I, J, A[I][J]);
    }
