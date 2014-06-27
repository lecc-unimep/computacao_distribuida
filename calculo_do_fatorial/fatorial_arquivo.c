/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves de um arquivo 
*** Código produzido por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {

	int n=0, total=1, cont=0;
	FILE *arquivo;
  
	arquivo=fopen("arquivo_n.txt","r");

	if ( arquivo == NULL ) {
	        printf("-------------------------------------------------------------------\n");
		printf("Nao foi possivel abrir o arquivo.\n");
		printf("-------------------------------------------------------------------\n");
		exit(0);
	}

	fscanf(arquivo,"%d",&n);
	fclose(arquivo);
	
	for (cont = n; cont > 1; cont--) {    
		total = total * (cont);
	}
	
	printf("-------------------------------------------------------------------\n");
	printf("O Fatorial do numero %d e %d \n", n, total);
	printf("-------------------------------------------------------------------\n");

	return 0;
}

