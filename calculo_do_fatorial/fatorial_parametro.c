/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves de parametro 
*** Código produzido por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) {

	int n=0, total=1, cont=0;
	
	if ( argc != 2 ) {
		printf("-------------------------------------------------------------------\n");
		printf("Nao foi informado o valor.\n");
		printf("-------------------------------------------------------------------\n");
		exit(0);
	}

	n=atoi(argv[1]);

	for (cont = n; cont > 1; cont--) {    
		total = total * (cont);
	}
	
	printf("-------------------------------------------------------------------\n");
	printf("O Fatorial do numero %d e %d \n", n, total);
	printf("-------------------------------------------------------------------\n");

	return 0;

}

