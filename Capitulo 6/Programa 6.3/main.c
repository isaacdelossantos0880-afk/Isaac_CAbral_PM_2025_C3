#include <stdio.h>
#include <stdlib.h>

/* Universidad.
El programa, al recibir informacion sobre el numero de alumnos que han ingresado
a sus ocho diferentes carreras en los dos semestres lectivos de los ultimos cinco años,obtiene informacion util para el departamento de escolar. */

const int F = 8, C = 2, P = 5;
/* Se declaran constantes para la fila, la colimna y la profundidad. */
void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int,int, int);
void Funcion2(int [][C][P], int, int, int);
/* Prototipo de funciones. Cada prototipo de funcion correspondiente a uno de los inicios. */

void main(void)
{
    int UNI[F][C][P];
    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, p);
    Funcion2(UNI, F, C, P);
    Fu     Funcion3(UNI, 6, C, P);
    /* Se coloca el 6 como parametro ya que es la clave de la ingenieria en computacion. */

}
void Lectura(int S[][C][P], int FI, int CO, int PR)
/* La funcion Lectura se utiliza para leer un arreglo tridimencional de tipo entero de FI filas, CO columanas y PR profundidad.
Observa que al ser tridimencional se necesita tres ciclos para recorrer el arreglo. */
{
    int K, I, J;
    for (K=0; K<PR; K++)
        for (I=0; I<FI; I++)
            for (J=0; J<CO; J++)
    {
        printf("Año: %d\tCarreras: %d\tSemestre: %d ", K+1, I+1, J+1);
        scanf("%d", &A[I][J][K]);
    }
}
void Funcion1(int A[][C][P], int FI, int CO, int PR)
/* Esta fincion se utiliza para determinar el año en el que ingreso el mayor numero de alumnos en la univercidad.
Observa que el perimer ciclo externo correspondiente a los años. */
{
    int K, I, J, MAY = 0, AO = -1, SUM;
    for (K=0; K<PR; K++)
        /* Por cada año se suma el ingreso de los dos semestres de las ocho carreras.*/
    {
        SUM = 0;
        for (I=0; I<FI; I++)
            for (J=0; J<CO; J++)
                 SUM += A[I][J][K];
         if (SUM > MAY)
         {
             MAY = SUM;
             AO = K;
         }
    }
    printf("\n\nAño con mayor ingreso de alumnos: %d  Alumnos: %d", AO+1, MAY);
}
void Funcion2(int A[][C][P], int FI, int CO, int PR)
/* Esta fincion se utiliza para determinar la carrera que recibio el mayor numero de alimnos el ultimo año.
Observa que no se utiliza un ciclo para los planos de la profundidad, ya que es un dato (PR). */
{
  int I, J, MAY = 0, CAR = -1, SUM;
  for
}
SUM = 0;
for (J=0; J<CO; J++)
    SUM += A[I][J][PR-1];
if (SUM > MAY)
{
    MAY = SUM;
    CAR = I;
}
}
printf("\n\nCarrera con mayor numero de alumnos: %d Alumnos: %d", CAR+1, MAY);
}

void Funcion3 (int A[][C][P], int FI, int CO, int PR)
/* Esta fincion se utiliza para determinar en año en el que la correrea Ingenieria en computacion recibio el mayor numero de alumnos.
Observa que no se utiliza un ciclo para trabajar con las filas, ya que es un dato (FI). */
{
    int K, J, MAY = 0, AO = -1, SUM;
    for (K=0; K<PR; K++)
    {
        SUM = 0;
        for (J=0; J<CO; J++)
            SUM += A[FI-1][J][K];
        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso de alimnos: %d Alumnos: %d", AO+1, MAY);
}
