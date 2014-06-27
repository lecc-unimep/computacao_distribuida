/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves de um arquivo 
*** Código produzido por Alessandro Frasson
*** Alterações promovidas por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {

    int num=0, total=1, cont=0;
    FILE *arquivo;
  
    arquivo=fopen("arq.txt","r");
	if ( arquivo == NULL ) {
		printf("Nao foi possivel abrir o arquivo.\n");
		exit(0);
	} else {
        fscanf(arquivo,"%d",&num);
        fclose(arquivo);
        for (cont = num; num > 1; num--) {    
            total = total * (num);
        }
        printf("O Fatorial do numero digitado e = %d \n", total);
	}
	return 0;
}
