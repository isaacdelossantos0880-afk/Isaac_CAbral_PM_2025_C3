#include <stdio.h>

/* cubo -2.
El programa calcula el cubo de los 10 primeros numeros naturales con la ayuda de una funcion. */

int cubo (void);            /* prototipo de funcion. */
int I;                      /* Variable global. */

void main (void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo();       /* Llamada a la funcion cubo. */
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
}
int cubo(void)             /* Declaracion de la funcion. */
/* La funcion calculada el cubo de la variable local I. */
{
    int I = 2;             /*Variable local entera I con el mismo nombre que la variable globar. */
     return (I*I*I);
}
