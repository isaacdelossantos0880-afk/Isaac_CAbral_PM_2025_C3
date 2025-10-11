#include <stdio.h>

/* Lluvias.
El programa permite calcular el promedio mensual de la lluvias caidas en tres regiones importantes del pais. determina tambien cual es la region con mayor promedio de lluvia anual. */

void Mayor (float, float, float);        /*Prototipo de funcion. */

void main (void)
{
    int I;
    float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
    for (I =1; I <= 12; I++)
    {
        printf("\n\nIngresa las lluvias del mes %d", I);
        printf("\nRegiones Golfo, Pasifico y Caribe: ");
        scanf("%f %f %f", &GOL, &PAC, &CAR);
        AGOL += GOL;
        APAC += PAC;
        ACAR += CAR;
    }
    printf("\n\nPromedio de lluvias region Golfo: %6.2f" , (AGOL / 12));
    printf("\nPromedio de lluvias region pasifico: %6.2f" , (APAC / 12));
    printf("\nPromedio de lluvias region caribe: %6.2f" , (ACAR/ 12));
    Mayor(AGOL, APAC, ACAR);
    /*Se llama a la funcion MAYOR. Paso de parametros por valor. */
}
void Mayor(float R1, float R2, float R3)
/* Esta funcion obtiene la region con mayor promedio de lluvia anual.*/
{
    if (R1 > R2)
        if (R1 > R3)
        printf("\nRegion con mayor promedio: Region Golfo. promedio: %6.2f", R1 / 12);
    else
        if (R2 > R3)
        printf("\nRegion con mayor promedio: Region pacifico. Promedio %6.2f", R2 / 12);
    else
        printf("\nRegion con mayor promedio: Region caribe. promedio: %6.2f", R2 / 12);
}
