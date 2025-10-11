#include <stdio.h>

/* Busqueda secuencial de arreglos desordenados. */

const int max=100;

void Lectura(int, int);               /* Prototipos de funciones. */
int Busca (int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[max];
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>max || TAM<1);      /*Se verifica que el tamaño del arreglo sea correcto. */
    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Busca(VEC, TAM, ELE);     /* Se llama a la funcion que busca el arreglo. */

    if(RES)
    /* Si RES tiene un valor verdadero-diferentede 0-, se escribe la posicioon en la que se encontro el elemento. */
    printf("\nEl elemento se encuentra en la posicion %d", RES);
else
    printf("\nEl elemento  no se encuentra en el arreglo");
}
void Lectura(int A[], int T)
/* La funcion Lectura se utiliza para leer un arreglo unidimencional de T elementos de tipo entero. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
    }
}
int Busca(int A[], int T, int K)
/*Esta funcion localiza en el arreglo un elemento determinado. Si el elmento es encontrado,regresa la posicion correspondiente. En caso contrario, regresa a 0. */
{
    int I = 0, BAN = 0, RES;
    while (I < T && !BAN)
        if (A[I] == K)
             BAN++;
    else
        I++;
    if (BAN)
        RES = I + 1;
    /* Se asigan I+1 dado que las posicionas en el arreglo comienzan desde cero. */
    else
        RES = BAN;
    return (RES);
}
