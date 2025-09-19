#include <stdio.h>

/* Aplicacionde operadores. */
void main (void)
{
    int i= 5,j= 4, k, m;
    k = ! (!i|| 1 && 0)&& 1;
    printf("\nEl valor de k es: %d", k);

    m = (k =(!(12> 10)), j = (10||0) && k, (!(k||j)));
    printf("\nEl valor de m es; %d", m);
}
