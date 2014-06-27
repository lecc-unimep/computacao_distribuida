/***************************************************************************************************
*** Programa que calcula o determinante de uma matriz, paralelamente, recebendo-a atraves de arquivo
*** Codigo produzido por Jose Luis Zem
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *arquivo_matriz;
pthread_t id_filho1, id_filho2;
int indice=0;
float matriz[20],diagonais_principais=0, diagonais_secundarias=0, determinante=0;

void* filho1() {
	diagonais_principais = (matriz[1]*matriz[5]*matriz[9]) + (matriz[2]*matriz[6]*matriz[7]) + (matriz[3]*matriz[4]*matriz[8]);
}

void* filho2() {
	diagonais_secundarias = - (matriz[3]*matriz[5]*matriz[7]) - (matriz[1]*matriz[6]*matriz[8]) - (matriz[2]*matriz[4]*matriz[9]);
}                                

int main(int argc,char *argv[]) {

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

	pthread_create(&id_filho1,NULL,&filho1,NULL);
	pthread_create(&id_filho2,NULL,&filho2,NULL);
	                
	pthread_join(id_filho1,NULL);
	pthread_join(id_filho2,NULL);
                
	determinante = diagonais_principais + diagonais_secundarias;
        
        printf("-----------------------------------------------------------------------------\n");
	printf("O Determinante e %f \n", determinante);
        printf("-----------------------------------------------------------------------------\n");
        
	return 0;
}

