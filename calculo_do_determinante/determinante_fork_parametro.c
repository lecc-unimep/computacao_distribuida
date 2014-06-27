/*****************************************************************************************************
*** Programa que calcula o determinante de uma matriz, paralelamente, recebendo-a atraves de parametro
*** Codigo produzido por Jose Luis Zem
******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {

	FILE *arquivo_filho1, *arquivo_filho2;
	pid_t id_filho1, id_filho2;
	int estado_filho1, estado_filho2, indice=0;
	float matriz[20],diagonais_principais=0, diagonais_secundarias=0, determinante=0;

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
                                                                                                            
        
	id_filho1 = fork();
	if ( id_filho1 == 0 ){
		diagonais_principais = (matriz[1]*matriz[5]*matriz[9]) + (matriz[2]*matriz[6]*matriz[7]) + (matriz[3]*matriz[4]*matriz[8]);
		arquivo_filho1 = fopen("./arq_filho1.txt","w");
		fprintf(arquivo_filho1,"%f",diagonais_principais);
		fclose(arquivo_filho1);
		exit(0);
	}
        
	id_filho2 = fork();
	if ( id_filho2 == 0 ) {
		diagonais_secundarias = - (matriz[3]*matriz[5]*matriz[7]) - (matriz[1]*matriz[6]*matriz[8]) - (matriz[2]*matriz[4]*matriz[9]);        
                arquivo_filho2 = fopen("./arq_filho2.txt","w");
                fprintf(arquivo_filho2,"%f",diagonais_secundarias);
                fclose(arquivo_filho2);
                exit(0);
	}

        waitpid(id_filho1,estado_filho1,0);
        waitpid(id_filho2,estado_filho2,0);
                
        arquivo_filho1 = fopen("./arq_filho1.txt","r");
        fscanf(arquivo_filho1,"%f",&diagonais_principais);
        fclose(arquivo_filho1);
                              
        arquivo_filho2 = fopen("./arq_filho2.txt","r");
        fscanf(arquivo_filho2,"%f",&diagonais_secundarias);
        fclose(arquivo_filho2);
                                                        
	determinante = diagonais_principais + diagonais_secundarias;
        
        printf("-----------------------------------------------------------------------------\n");
	printf("O Determinante e %f \n", determinante);
        printf("-----------------------------------------------------------------------------\n");
        
        remove("./arq_filho1.txt");
        remove("./arq_filho2.txt");
                                
	return 0;
}

