#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define elementos 415000

char traco[100]="--------------------------------------------------------------------------------------------";
pthread_t id_filho1, id_filho2, id_filho3;
int registro=0, indice1, indice2, indice3, n;
float coluna01, coluna02;
float x[elementos], y[elementos], x2[elementos],y2[elementos],xy[elementos];
float somatorio_x=0, somatorio_y=0, somatorio_x2=0, somatorio_y2=0, somatorio_xy=0;
float sxx, syy, sxy, r, r2;
  
FILE *arquivo;
  
void* filho1() {
  for (indice1=0;indice1 < n; indice1++) {
  	x2[indice1] = x[indice1] * x[indice1];
  	somatorio_x =  somatorio_x + x[indice1];
  	somatorio_x2 = somatorio_x2 + x2[indice1];
  }  
  sxx = somatorio_x2 - ((somatorio_x * somatorio_x) / n);
}
  
  
void* filho2() {
  for (indice2=0;indice2 < n; indice2++) {
        y2[indice2] = y[indice2] * y[indice2];
        somatorio_y = somatorio_y + y[indice2];
        somatorio_y2 =  somatorio_y2 + y2[indice2];
  } 
  syy = somatorio_y2 - ((somatorio_y * somatorio_y) / n);  
}

void* filho3() {
  for (indice3=0;indice3 < n; indice3++) {
        xy[indice3] = x[indice3] * y[indice3];
        somatorio_xy = somatorio_xy + xy[indice3];
  }
  sxy = somatorio_xy - ((somatorio_x * somatorio_y) / n);
}

int main (int argc, char * argv[]) {  

  system("clear");
  
  arquivo = fopen(argv[1],"r");
  
  while ( !feof(arquivo) ) {
        fscanf(arquivo, "%f %f", &coluna01, &coluna02);
        x[registro] = coluna01;
        y[registro] = coluna02;
        registro = registro + 1;
  }
  
  fclose(arquivo);
  
  n = registro - 1;
  
  if ( n > elementos ) {
     system("clear");
     printf("%s\n", traco);
     printf("Você extrapolou o limite de elementos possíveis (%d).\n", elementos);
     printf("%s\n", traco);
     exit(0);
  }
                                  
  pthread_create(&id_filho1,NULL,&filho1,NULL);
  pthread_create(&id_filho2,NULL,&filho2,NULL);
  pthread_create(&id_filho3,NULL,&filho3,NULL);
                 
  pthread_join(id_filho1,NULL);
  pthread_join(id_filho2,NULL);
  pthread_join(id_filho3,NULL);
                                
  r = sxy / sqrt((sxx * syy));
   
  r2 = r * r;
  
  printf("%s\n", traco);
  printf("O Indice de Correlacao e %f e o Coeficiente de Determinacao e %f.\n", r, r2 ); 
  printf("%s\n", traco); 
  
  return 0;
}

