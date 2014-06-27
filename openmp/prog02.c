#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

  int var1, var2, var3;
  printf("Esta parte do código foi executada serialmente ...\n");
  #pragma omp parallel private(var1, var2) shared(var3) 
  {
     printf("Esta parte do código esta paralelizada ...\n");	
     int tid = omp_get_thread_num(); 
     printf("Hello World da thread = %d.\n", tid);
  }
  printf("Esta parte do código foi executada serialmente ...\n");
  return 0;
}

