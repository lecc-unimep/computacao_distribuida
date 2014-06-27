/*********************************************************************************************** 
*** Programa que calcula, paralelamente, o fatorial de um número, recebendo-o atraves de arquivo 
*** Codigo produzido por José Luís Zem
***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *arquivo_n;
int n=0, fat1=1, fat2=1, fatorial=1, cont1=0, cont2=0;
pthread_t id_filho1, id_filho2;
int limite;
                                

void* filho1 () {
	for (cont1 = limite; cont1 > 0; cont1--) {
		fat1 = fat1 * cont1;
	}
}

void* filho2() {
	for (cont2 = n; cont2 > limite; cont2--) {
		fat2 = fat2 * cont2;
	}
}

int main(int argc,char *argv[]) {

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

	pthread_create(&id_filho1,NULL,&filho1,NULL);
	pthread_create(&id_filho2,NULL,&filho2,NULL);

	pthread_join(id_filho1,NULL);
	pthread_join(id_filho2,NULL);

        fatorial = fat1 * fat2;

        printf("-----------------------------------------------------------------------------\n");
        printf("O Fatorial do numero %d e %d \n", n, fatorial);
        printf("-----------------------------------------------------------------------------\n");
                        
	return 0;

}

