/******************************************************************************************************
*** Programa que calcula o determinante de uma matriz, paralelamente, recebendo-a atraves de parametros
*** Código produzido por José Luís Zem
*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char *argv[]) {

    float matriz[20], diagonais_principais=0, diagonais_secundarias=0, determinante=0;
    int indice=0;

    system("clear");

    if ( argc != 10 ) {
	printf("-----------------------------------------------------------------------------\n");
	printf("Nao foi informada a matriz.\n");
	printf("-----------------------------------------------------------------------------\n");
	exit(0);
    }

    for (indice = 1; indice <= 9; indice++) {
	matriz[indice]=atoi(argv[indice]);
    }
                                                                                                                
    omp_set_num_threads(2);

    #pragma omp parallel shared(matriz, diagonais_principais, diagonais_secundarias) 
    {
        
	int tid = omp_get_thread_num();
            
	if ( tid == 0 ) {
	    diagonais_principais = (matriz[1]*matriz[5]*matriz[9]) + (matriz[2]*matriz[6]*matriz[7]) + (matriz[3]*matriz[4]*matriz[8]);
	}
        
	if ( tid == 1 ) {
   	    diagonais_secundarias = - (matriz[3]*matriz[5]*matriz[7]) - (matriz[1]*matriz[6]*matriz[8]) - (matriz[2]*matriz[4]*matriz[9]);
	}
    }

    determinante = diagonais_principais + diagonais_secundarias;

    printf("-----------------------------------------------------------------------------\n");
    printf("O Determinante e %f \n", determinante);
    printf("-----------------------------------------------------------------------------\n");

    return 0;

}

