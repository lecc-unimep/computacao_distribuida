/*********************************************************************************************** 
*** Programa que calcula o fatorial de um numero, paralelamente, recebendo-o atraves de arquivo
*** Codigo produzido por Jose Luis Zem
***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char *argv[]) {

    FILE *arquivo_n;
    int n=0, fat=0, f1=1, cont1=0, f2=1, cont2=0, limite=0;
    
    system("clear");

    arquivo_n=fopen("arquivo_n.txt","r");
    if ( arquivo_n == NULL ) {
        printf("-----------------------------------------------------------------------------\n");
	printf("Erro: Nao foi possivel abrir o arquivo com o valor de N.\n");
        printf("-----------------------------------------------------------------------------\n");
        return 1;
    }
                                                                                        
    fscanf(arquivo_n,"%d",&n);
    fclose(arquivo_n);    
    
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
