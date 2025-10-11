#include <stdio.h>

/*combinacion de variables globales y locales, y parametros por valor y por referencia. */

int a, b, c, d;                  /* variables globales. */

void fucion1 (int *, int *);
/*Prototipo de funcion. observa qu elos dos parametros son por referencia. */

int fucion2(int, int *);
/* En este prototipo el primer parametro es por valor y el segundo por referencia. */

void main (void)
{
    int a;     /* Nota de a es yuna variable local. */
    a = 1;     /* Se asigna un valor a la variable local a. */
    b = 2;     /* Se asignan valores a las variables globales b, c y d. */
    c = 3;
    d = 4;
    printf("\n%d %d %d %d", a, b, c,d);
}
int funcion2 (int c, int *d)
{
    int b;
    a++;
    b = 7;
    c += 3;
    (*d)+= 2;
    printf("\n%d %d %d %d", a, b, c, *d);
    return (c);
}
