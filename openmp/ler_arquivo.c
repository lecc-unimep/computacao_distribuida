#include <stdio.h>

int main() {
   
   FILE *arquivo;
   int registro=0;
   
   float coluna01, coluna02;
   
   arquivo = fopen("resultado.dat","r");
   
   while ( !feof(arquivo) ) {
         registro = registro +1;
         fscanf(arquivo, "%f %f", &coluna01, &coluna02);
         printf("Registro = %d Coluna 01 = %f Coluna 02 = %f \n", registro, coluna01, coluna02);
   }

   fclose(arquivo);

   return 0;
}
   
