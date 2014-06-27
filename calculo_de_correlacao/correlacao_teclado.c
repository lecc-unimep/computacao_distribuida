#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define elementos 10000

int main() {
  char traco[100]="--------------------------------------------------------------------------------------------";
  int indice, n;
  float x[elementos], y[elementos], x2[elementos],y2[elementos],xy[elementos];
  float somatorio_x=0, somatorio_y=0, somatorio_x2=0, somatorio_y2=0, somatorio_xy=0;
  float sxx, syy, sxy, r, r2;
  
  system("clear");
  
  printf("\nInformar a quantidade de elementos para X e Y.\n%s\n", traco);
  
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);
  
  if ( n > elementos ) { 
      system("clear");
      printf("%s\n", traco);
      printf("Você extrapolou o limite de elementos possíveis (%d).\n", elementos); 
      printf("%s\n", traco);
      exit(0);
  }
  
  printf("\nInformar os valores de X.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      printf("Digite o valor para x[%d]: ", indice);
      scanf("%f",&x[indice]);
  }  
  
  printf("\nInformar os valores de Y.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      printf("Digite o valor para y[%d]: ", indice);
      scanf("%f",&y[indice]);
  }  
  
  for (indice=0;indice < n; indice++) {
      x2[indice] = x[indice] * x[indice];
  }
                  
  for (indice=0;indice < n; indice++) {
      y2[indice] = y[indice] * y[indice];
  }
                  
  for (indice=0;indice < n; indice++) {
      xy[indice] = x[indice] * y[indice];
  }
                  
  for (indice=0;indice < n; indice++) {
      somatorio_x =  somatorio_x + x[indice];
      somatorio_y = somatorio_y + y[indice];
      somatorio_x2 = somatorio_x2 + x2[indice];
      somatorio_y2 =  somatorio_y2 + y2[indice];
      somatorio_xy = somatorio_xy + xy[indice];
  }
  
  sxx = somatorio_x2 - ((somatorio_x * somatorio_x) / n);  
  
  syy = somatorio_y2 - ((somatorio_y * somatorio_y) / n);
  
  sxy = somatorio_xy - ((somatorio_x * somatorio_y) / n);

  r = sxy / sqrt((sxx * syy));
   
  r2 = r * r;

  system("clear");
  
  printf("%s\n", traco);
  printf("O Indice de Correlacao e %f e o Coeficiente de Determinacao e %f.\n", r, r2 );
  printf("%s\n", traco);        
  
  return 0;
}

