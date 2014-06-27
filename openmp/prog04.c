#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

  int var1=1, var2=1, var3=1;

  printf("\nEsta parte do código foi executada serialmente ...\n");

  var1++;
  var2++;
  var3++;
  
  printf("VAR1 = %d, VAR2= %d, VAR3= %d .\n", var1, var2, var3);
  
  #pragma omp parallel shared(var1, var2,var3) 
  {
  
     int tid = omp_get_thread_num(); 
     printf("\nThread %d: Hello World.\n", tid);
     
     if ( tid == 0 ) {
       int nthreads = omp_get_num_threads();
       printf("Thread %d: Numero de threads = %d.\n", tid, nthreads);
     } else {
       var1 = var1 + tid;
       var2 = var2 + tid;
       printf("Thread %d: VAR1 = %d, VAR2 = %d, VAR3 = %d .\n", tid, var1, var2, var3);
     }

  }

  printf("\nEsta parte do código foi executada serialmente ...\n");
  printf("VAR1 = %d, VAR2 = %d, VAR3 = %d .\n", var1, var2, var3);
  
  return 0;
}

