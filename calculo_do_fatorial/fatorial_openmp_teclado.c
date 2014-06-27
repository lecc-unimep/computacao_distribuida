/*********************************************************************************************** 
*** Programa que calcula o fatorial de um numero, paralelamente, recebendo-o atraves do teclado 
*** Codigo produzido por Jose Luis Zem
***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char *argv[]) {

    int n=0, fat=0, f1=1, cont1=0, f2=1, cont2=0, limite=0;
    
    system("clear");
    
    printf("-----------------------------------------------------------------------------\n");
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &n);
    
    system("clear");
    
    limite = n/2;
   
    omp_set_num_threads(2);
    
    #pragma omp parallel shared(n, f1, f2) 
    { 
     
	int tid = omp_get_thread_num();

	if ( tid == 0 ) { 
	    for (cont1 = limite ; cont1 > 0; cont1--) {    
		f1 = f1 * (cont1);
	    }
	}
    
	if ( tid == 1 ) {
	    for (cont2 = n ; cont2 > limite; cont2--) {
		f2 = f2 * (cont2);
	    }
	}
    
    }
    
    fat = f1 * f2;

    printf("-----------------------------------------------------------------------------\n");	
    printf("O Fatorial do numero %d e %d \n", n, fat);
    printf("-----------------------------------------------------------------------------\n");
    	
    return 0;

}
