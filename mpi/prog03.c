#include "mpi.h" 
#include <stdio.h> 
 
int main( argc, argv ) 
int argc;
char **argv; 
{ 
   int indice=0, elementos=3, rank, nprocs, x[3], y[3], type = 99, quadrado_x[3], quadrado_y[3], produto_xy[3]; 
   MPI_Status status;
   MPI_Init( &argc, &argv ); 
   MPI_Comm_size(MPI_COMM_WORLD,&nprocs); 
   MPI_Comm_rank(MPI_COMM_WORLD,&rank); 
 
   x[0] = 1;
   x[1] = 2;
   x[2] = 3;
   y[0] = 4;
   y[1] = 5;
   y[2] = 6;
  
   if ( rank == 0 ) {
   
      MPI_Recv(&quadrado_x, 13, MPI_INT, 1, type, MPI_COMM_WORLD, &status);
      for (indice=0; indice < elementos; indice++) { 
          printf("Processo-Pai: O quadrado de X[%d] e %d \n",indice, quadrado_x[indice]);
      }
      
      MPI_Recv(&quadrado_y, 13, MPI_INT, 2, type, MPI_COMM_WORLD, &status);
      for (indice=0; indice < elementos; indice++) {
          printf("Processo-Pai: O quadrado de Y[%d] e %d \n",indice, quadrado_y[indice]);
      }
      
      MPI_Recv(&produto_xy, 13, MPI_INT, 3, type, MPI_COMM_WORLD, &status);
      for (indice=0; indice < elementos; indice++) {
          printf("Processo-Pai: O produto de XY[%d] e %d \n",indice, produto_xy[indice]);
      }
      
   }

   if ( rank == 1 ) {
      for (indice=0; indice < elementos; indice++) { 
          quadrado_x[indice] = x[indice] * x[indice];
      }
      MPI_Send(&quadrado_x, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
      MPI_Recv
   }

   if ( rank == 2 ) {
      for (indice=0; indice < elementos; indice++) {
          quadrado_y[indice] = y[indice] * y[indice];
      }
      MPI_Send(&quadrado_y, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
   }
   
   if ( rank == 3 ) {
      for (indice=0; indice < elementos; indice++) {
           produto_xy[indice] = x[indice] * y[indice];
      }
      MPI_Send(&produto_xy, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
   }
   
   MPI_Finalize(); 
   return 0; 
}
