/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves do teclado 
*** Código produzido por Alessandro Frasson
*** Alterações promovidas por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) {

    int num=0, total=1, cont=0;
	
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &num);
     
    for (cont = num; num > 1; num--) {    
         total = total * (num);
    }
	
    printf("O Fatorial do numero digitado e = %d \n", total);
}
