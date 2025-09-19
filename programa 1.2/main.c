#include <stdio.h>
#include <stdlib.h>
/* Ivierte datos
El programa, al recibir como datoun conjunto de datos de entrada,invierte el orden de los mismos cuando los imprime.

A, B, C y D: variables tipo entero. */

void main (void)
{
int A, B, C, D;
printf("ingrse cuatro datos de tipo entero: ");
scanf ("%d %d %d",&A, &B, &C,&D) ;
printf("\n %d %d %d %d " , D, C,B, A) ;
}

