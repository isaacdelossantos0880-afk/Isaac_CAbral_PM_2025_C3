#include <stdio.h>

/* Eleccion.
El programa almacena los votos emitidos en una elccion en la que hubo cinco condidatos e imprime el total de votos que obtuvo cada uno de ellos. */

void main(void)
{
    int ELE[5] = {0};    /* Declaracion del arreglo entero ELE de cinco elementos todos sus elementos se inizializan en 0. */

    int I, VOT;
    printf(" Ingresa el primer voto (0 - para terminar): ");
    scanf("%d", &VOT);
    while (VOT)
    {
        if ((VOT > 0)&& (VOT < 6))         /* Se verifica que el boto sea correcto. */
            ELE[VOT -1]++;       /* Los votos se almacenan en el arreglo.Recuerda que la primera posicion del arreglo es 0, por esa razon a la variable VOT se le descunta 1. Los votos del primer candidato se almacenan en la pocision 0. */

        else
            printf("\nEl voto ingresado es incorrecto. \n");
        printf("Ingresa el siguiente voto (0 - para terminar): ");
        scanf("%d", &VOT);
    }
    printf("\n\nResultados de la eleccion\n");
    for (I = 0; I <= 4; I++)
        printf("\nCandidato %d: %d", I+1, ELE[I]);
}
