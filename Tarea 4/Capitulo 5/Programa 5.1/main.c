#include <stdio.h>

/* Cuenta- numeros.
El programa, al recibir como datos un arreglo unidimencional de tipo entero y un tipo entero, determina cuantas veces se encuentra el numero en el arreglo. */

void main (void)
{
    int I, NUM, CUE = 0;
    int ARRET [100];                  /* Declaracion del arreglo */
    for (I=0; I<100; I++)
    {
        printf("Ingrese el elemento %d del arreglo: ", I+1);
        scanf("%d", &ARRET[I]);              /* Lectura -asignacion- del arreglo */

    }
    printf("\n\nIngrese el numero que se va a buscar en el arreglo: ");
    scanf("$d", &NUM);
    for (I=0; I<100; I++)
        if (ARRET[I] == NUM)    /* comparacion del numero con los elementos del arrglo */

                CUE++;
    printf("\n\nEl %d se encuentra %d veces en el arraglo", NUM, CUE);

}
