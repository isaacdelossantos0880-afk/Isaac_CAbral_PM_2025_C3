#include <stdio.h>

 /* Eleccion.
 El programa obtiene el total de votos de cada candidato y el porcentage correspondiente. tambien considera votos nulos.

 VOT, C1, C2, C3, C4, C5, NU, SVO: variables de tipo entero.
 P01, P02, P03, P04, P05, PON: variables de tipo real. */

  void main (void)
  {
      int VOT, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, NU = 0, SVO;
      float P01, P02, P03, P04, P05, PON;
      printf("Ingrese el primer voto: ");
      scanf("%d", &VOT);
      while (VOT)
      {
          switch (VOT)
          {
              case 1: C1++; break;
              case 2: C2++; break;
              case 3: C3++; break;
              case 4: C4++; break;
              case 5: C5++;break;
              default: NU++; break;
          }
          printf("ingrese el siguiente voto -0 para terminar-: ");
          scanf("%d", &VOT);
      }
      SVO = C1 + C2 + C3 + C4 + C5 + NU;
      P01 = ((float)C1 / SVO) * 100;
      P02 = ((float)C2 / SVO) * 100;
      P03 = ((float)C3 / SVO) * 100;
      P04 = ((float)C4 / SVO) * 100;
      P05 = ((float)C5 / SVO) * 100;
      printf("\nTotal de votos: %d", SVO);
      printf("\nCandidato 1: %d votos -- porcentaje 5.2f",  C1, P01);
      printf("\nCandidato 2: %d votos -- porcentaje %5.2f", C2, P02);
      printf("\nCandidato 3: %d votos -- porcentahe %5.2f", C3, P03);
      printf("\ncandidato 4: %d votos -- porcentaje %5.2f", C4, P04);
      printf("\ncandidato 5: %d votos -- porcentaje %5.2f", C5, P05);
      printf("\nNulos:       %d votos -- porcentaje %5.2",NU, PON);
  }
