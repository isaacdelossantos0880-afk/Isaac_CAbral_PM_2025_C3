#include <stdio.h>
#include<math.h>

/* Funcion matematica.
El programa obtiene el resultado de una fincion.

OP y T: variables de tipo entero.
RES: variable de tipo real. */

void main (void)
{
    int OP, T;
    float RES;
    printf("Ingrese la opcion del calculo y el valor entero: ");
    scanf("%f %d" , &OP, &T);
    switch(OP)
    {


      case 1: RES = T /5;
       break;
      case 2: RES = POW(T,T);
     /* La funcion POW esta definida en la biblioteca math.h */
         break;
    case 3:
    case 4: RES = 6 * T/2;
         break;
    default: RES = 1;
         brak;
         {
             printf("\nREsultado:     %7.2f", RES);
         }
