#include <stdio.h>

/* Promedio de curso.
El progrma, al recibir como dato el promedio de un alumno en un curso univercitario, escribe aprobado si su promedio es mayor o igula a 6, o reprobado en caso contrario.

 PRO: variable de tipo real. */

 void main (void)
 {
     float PRO;
     printf("Ingrese el promedio del alimno: ");
     scanf("%f",&PRO);
     if (PRO>= 6.0)
        printf("\nAprobado");
     else
        printf("\nReprobado");
 }

