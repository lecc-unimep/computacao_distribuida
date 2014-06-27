/**************************************************************************************
*** Programa que calcula o determinante de uma matriz, recebendo-a atraves de teclado‹
*** Código produzido por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc,char *argv[]) {

        float matriz[20], diagonais_principais=0, diagonais_secundarias=0, determinante=0;
        int indice=0;

        for (indice = 1; indice <= 9; indice++) {
            printf("Entre o %do. valor da matriz: ",indice);
			scanf("%f",&matriz[indice]);
        }

	omp_set_num_threads(3);

        #pragma omp parallel shared(matriz, diagonais_principais, diagonais_secundarias) 
        {
        
            int tid = omp_get_thread_num();
            
            if ( tid == 0 ) {
               printf("Filho %d: Eu nao faco nada...\n",tid);
            }
        
            if ( tid == 1 ) {
               printf("Filho %d: Calculando as Diagonais Principais.\n",tid);
               diagonais_principais = (matriz[1]*matriz[5]*matriz[9]) + (matriz[2]*matriz[6]*matriz[7]) + (matriz[3]*matriz[4]*matriz[8]);
               printf("Filho %d: O resultado das diagonais principais e %f\n",tid, diagonais_principais); 
            }
        
            if ( tid == 2 ) {
               printf("Filho %d: Calculando as Diagonais Secundarias.\n",tid);
               diagonais_secundarias = - (matriz[3]*matriz[5]*matriz[7]) - (matriz[1]*matriz[6]*matriz[8]) - (matriz[2]*matriz[4]*matriz[9]);
               printf("Filho %d: O resultado das diagonais secundarias e %f\n",tid, diagonais_secundarias);
            }
        }

        determinante = diagonais_principais + diagonais_secundarias;
        printf("O Determinante e %f \n", determinante);
        return 0;
}
