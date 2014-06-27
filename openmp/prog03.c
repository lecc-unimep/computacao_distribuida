#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

  int var1, var2, var3;
  printf("Esta parte do código foi executada serialmente ...\n");
  #pragma omp parallel private(var1, var2) shared(var3) 
  {
     int tid = omp_get_thread_num(); 
     printf("Thread %d: Hello World.\n", tid);
     
     if ( tid == 0 )
     {
       int nthreads = omp_get_num_threads();
       printf("Thread %d: Numero de threads = %d.\n", tid, nthreads);
     }
  }
  printf("Esta parte do código foi executada serialmente ...\n");
  return 0;
}

