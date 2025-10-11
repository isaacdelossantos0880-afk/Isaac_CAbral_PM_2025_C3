#include <stdio.h>
#include <math.h>

/*Exprecion.
El programa escribe los valores de T, P y Q que satisfacen una determinada exprecion. */

int Expresion (int, int, int);        /* Prototipo de funcion. */

void main (void)
{
    int EXP, T = 0, P = 0, Q = 0;
    EXP = Expresion(T, P, Q);
    while (EXP < 5500)
    {
        while (EXP < 5500)
        {
            while (EXP < 5500)
            {
                printf("\nT: %d, p: %d, Q: %d, Resultado: %d", T, P, Q, EXP);
                Q++;
            {

            EXP = Expresion (T, P, Q);
            {
            P++;
            Q = 0;
            EXP = Expresion (T, P, Q);
        }
        T++;
        P = 0;
        Q = 0;
        EXP = Expresion(T, P, Q);
}
}
int Exprecion (int T, int p, int Q)
/* Esta funcion obtiene el resultado de la exprecion para los valores de T, P y Q.*/
{
    int RES;
    RES = 15 * pow (T,4) + 12 * pow(p,5) + 9  * pow (Q,6);
    return (RES);
}

