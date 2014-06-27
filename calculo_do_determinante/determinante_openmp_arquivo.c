/****************************************************************************************************
*** Programa que calcula o determinante de uma matriz, paralelamente, recebendo-a atraves de arquivos
*** Código produzido por José Luís Zem
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char *argv[]) {

    FILE *arquivo_matriz;
    float matriz[20], diagonais_principais=0, diagonais_secundarias=0, determinante=0;
    int indice=0;

    system("clear");

    arquivo_matriz=fopen("matriz.txt","r");
    if ( arquivo_matriz == NULL ) {
        printf("-----------------------------------------------------------------------------\n");
        printf("Nao foi possivel abrir o arquivo.\n");
        printf("-----------------------------------------------------------------------------\n");
        exit(0);
    }
                                                                                        
    fscanf(arquivo_matriz,"%f %f %f %f %f %f %f %f %f",&matriz[1],&matriz[2],&matriz[3],&matriz[4],&matriz[5],&matriz[6],&matriz[7],&matriz[8],&matriz[9]);
    fclose(arquivo_matriz);
                                                                                                                                                                                                                    
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

