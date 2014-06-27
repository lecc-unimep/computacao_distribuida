#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define elementos 10000

int main() {
  char traco[80]="---------------------------------------------------------------------------";
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
  
  printf("\nCalcular o quadrado de X.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      x2[indice] = x[indice] * x[indice];
      printf("O valor para x2[%d]:%f\n", indice,x2[indice]);
  }
                  
  printf("\nCalcular o quadrado de Y.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      y2[indice] = y[indice] * y[indice];
      printf("O valor para y2[%d]:%f\n", indice,y2[indice]);
  }
                  
  printf("\nCalcular o produto de XY.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      xy[indice] = x[indice] * y[indice];
      printf("O valor para xy[%d]:%f\n", indice,xy[indice]);
  }
                  
  printf("\nCalcular os somatorios.\n%s\n", traco);
  for (indice=0;indice < n; indice++) {
      somatorio_x =  somatorio_x + x[indice];
      somatorio_y = somatorio_y + y[indice];
      somatorio_x2 = somatorio_x2 + x2[indice];
      somatorio_y2 =  somatorio_y2 + y2[indice];
      somatorio_xy = somatorio_xy + xy[indice];
  }
  printf("Somatorio X = %f\n", somatorio_x);
  printf("Somatorio Y = %f\n", somatorio_y);
  printf("Somatorio X2 = %f\n", somatorio_x2);
  printf("Somatorio Y2 = %f\n", somatorio_y2);
  printf("Somatorio XY = %f\n", somatorio_xy);
  
  printf("\nCalcular Sxx.\n%s\n", traco);
  sxx = somatorio_x2 - ((somatorio_x * somatorio_x) / n);  
  printf("Sxx = %f \n",sxx);
  
  printf("\nCalcular Syy.\n%s\n", traco);
  syy = somatorio_y2 - ((somatorio_y * somatorio_y) / n);
  printf("Syy = %f \n",syy);
  
  printf("\nCalcular Sxy.\n%s\n", traco);
  sxy = somatorio_xy - ((somatorio_x * somatorio_y) / n);
  printf("Sxy = %f \n",sxy);

  printf("\nCalcular a Correlacao.\n%s\n", traco);
  r = sxy / sqrt((sxx * syy));
  printf("r = %f \n",r);   
   
  printf("\nCalcular Coeficiente de Determinacao.\n%s\n", traco);
  r2 = r * r;
  printf("r2 = %f \n",r2);
        
  
  return 0;
}
