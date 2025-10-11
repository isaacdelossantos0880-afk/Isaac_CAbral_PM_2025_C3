#include <stdio.h>
/* Incremento del precio.
El prgrama, al recibir como dato el precio de un producto importado, incrementa 11% el mismo si este es inferios a $1,00.
pre y NPR: variable de tipo real. */

void main(void)
{
    float PRE, NPR;
    printf("ingrece el precio del producto: ");
    scanf("%f", &PRE);
    if (PRE > 1500)
        NPR = PRE * 1.11;
    printf("\nNuevo precio: %7.2f",NPR);
}

