#include <stdio.h>

/* Calificaciones.
El programa, al recibir un grupo de calificaciones de un alumno, optiene el promedio de calificaciones de cada uno de ellos y, ademas, los alumnos con el mejor y el peor promedio.

I, MAT, MAMAT y MEMAT: variables de tipo entero.
CAL, SUM, MAPRO, MEPRO Y PRO: variable de tipo real.*/

 void main (void)
 {
     int I, MAT, MAMAT, MEMAT;
     float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;
     printf("Ingrese la matricula del primer alumno:\t");
     scanf("%d", &MAT);
     while (MAT)
     {
         SUM = 0;
         for(I = 1; I<= 5; I++)
         {
             printf("\tIngrese la calificacion del alumno: ", I);
             scanf("&f", &CAL);
             SUM += CAL;
         }
         PRO = SUM / 5;
         printf("\nMatricula:%d\t Promedio:%5.2f", MAT, PRO);
         if (PRO > MAPRO)
         {
             MAPRO = PRO;
             MAMAT = MAT;
         }
         if (PRO < MEPRO)
         {
             MEPRO = PRO;
             MAMAT = MAT;
         }
         printf("\n\nIngrese la matricula de siguiente alimno: ");
         scanf("%d", &MAT);
     }
     printf("\n\nAlumno con mejor promedio: \t%d\t\%5.2f", MAMAT, MAPRO);
     printf("\n\nALumno con peor promedio: \t%d\t\5.2f", MEMAT, MEPRO);
 }
