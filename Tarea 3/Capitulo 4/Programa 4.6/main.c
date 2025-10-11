 #include <stdio.h>

 /* Prueba de parametros por referencia. */

 void main (void)
 {
     int I, K = 4;
     for (I = 1; I <= 3; I++)
 {
 printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
 printf("\nValor de K despues de llamar a la funcion: %d", (&K));
 /*Llamada a la funcion f1. se pasa la direccion de la variable K, por medio del operador de direccion: &. */
 }
 }
 void f1 (int *R)
 /* La funcion f1 recibe un parametro por referencia. cada vez que el parametro se utiliza en la funsion debe ir precedido por el operador de indireccion. */
 {
     *R += *R;
 }
