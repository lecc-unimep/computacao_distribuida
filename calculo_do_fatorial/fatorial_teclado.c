/******************************************************************************* 
*** Programa que calcula o fatorial de um numero, recebendo-o atraves do teclado 
*** Codigo produzido por Jose Luis Zem
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) {

	int n=0, total=1, cont=0;

	system("clear");
	
	printf("-------------------------------------------------------------------\n");
	printf("Digite um numero para calcular o fatorial: ");
	scanf("%d", &n);
     
	for (cont = n; cont > 1; cont--) {    
		total = total * (cont);
	}
	
	system("clear");
	
	printf("-------------------------------------------------------------------\n");
	printf("O Fatorial do numero %d e %d \n", n, total);
	printf("-------------------------------------------------------------------\n");

	return 0;

}

