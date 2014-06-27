/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves de parametro 
*** Código produzido por Alessandro Frasson
*** Alterações promovidas por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) {

    int num=0, total=1, cont=0;
	
	if ( argc != 2 ) {
	    printf("Nao foi informado o valor.\n");
		exit(0);
	} else {
		num=atoi(argv[1]);
		for (cont = num; num > 1; num--) {    
			total = total * (num);
		}
		printf("O Fatorial do numero digitado e = %d \n", total);
	}
	return 0;
}
