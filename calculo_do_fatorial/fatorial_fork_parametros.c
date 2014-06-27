/**************************************************************************************************
*** Programa que calcula, paralelamente, o fatorial de um número, recebendo-o atraves de parametro 
*** Código produzido por José Luís Zem
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {

        FILE *arquivo_filho1, *arquivo_filho2;
        int n=0, fat1=1, fat2=1, fatorial=1, cont=0;
        pid_t id_filho1, id_filho2;
        int estado_filho1, estado_filho2, limite;

	system("clear");

	if ( argc == 1 ) {
	        printf("-----------------------------------------------------------------------------\n");
		printf("Erro: Quantidade de parâmetros informada esta incorreta.\n");
		printf("-----------------------------------------------------------------------------\n");
		return 1;
	}
	
	n = atoi(argv[1]);

        limite = n/2;

        id_filho1 = fork();
        if ( id_filho1 == 0) {
                for (cont = limite; cont > 0; cont--) {
                        fat1 = fat1 * cont;
                }
                arquivo_filho1 = fopen("./arq_filho1.txt","w");
                fprintf(arquivo_filho1,"%d",fat1);
                fclose(arquivo_filho1);
                exit(0);
        }

        id_filho2 = fork();
        if ( id_filho2 == 0) {
                for (cont = n; cont > limite; cont--) {
                        fat2 = fat2 * cont;
                }
                arquivo_filho2 = fopen("./arq_filho2.txt","w");
                fprintf(arquivo_filho2,"%d",fat2);
                fclose(arquivo_filho2);
                exit(0);
        }

        waitpid(id_filho1,estado_filho1,0);
        waitpid(id_filho2,estado_filho2,0);

        arquivo_filho1 = fopen("./arq_filho1.txt","r");
        fscanf(arquivo_filho1,"%d",&fat1);
        fclose(arquivo_filho1);

        arquivo_filho2 = fopen("./arq_filho2.txt","r");
        fscanf(arquivo_filho2,"%d",&fat2);
        fclose(arquivo_filho2);

        fatorial = fat1 * fat2;

	printf("-----------------------------------------------------------------------------\n");
        printf("O Fatorial do numero %d e %d \n", n, fatorial);
        printf("-----------------------------------------------------------------------------\n");

        remove("./arq_filho1.txt");
        remove("./arq_filho2.txt");

	return 0;
	
}

