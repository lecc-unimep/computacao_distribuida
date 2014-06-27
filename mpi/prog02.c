#include "mpi.h" 
#include <stdio.h> 
 
int main( argc, argv ) 
int argc;
char **argv; 
{ 
   int rank, nprocs, x=3, y=2, type = 99, quadrado_x=0, quadrado_y=0, produto_xy=0; 
   MPI_Status status;
   MPI_Init( &argc, &argv ); 
   MPI_Comm_size(MPI_COMM_WORLD,&nprocs); 
   MPI_Comm_rank(MPI_COMM_WORLD,&rank); 
 
  
   if ( rank == 0 ) {
   
      MPI_Recv(&quadrado_x, 13, MPI_INT, 1, type, MPI_COMM_WORLD, &status);
      printf("Processo-Pai: O quadrado de X e %d \n",quadrado_x);
      
      MPI_Recv(&quadrado_y, 13, MPI_INT, 2, type, MPI_COMM_WORLD, &status);
      printf("Processo-Pai: O quadrado de Y e %d \n",quadrado_y);
      
      MPI_Recv(&produto_xy, 13, MPI_INT, 3, type, MPI_COMM_WORLD, &status);
      printf("Processo-Pai: O produto de XY e %d \n",produto_xy);

   }

   if ( rank == 1 ) {
      quadrado_x = x * x;
      MPI_Send(&quadrado_x, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
      printf("Processo-Filho 1: O quadrado de X e %d \n", quadrado_x);
   }

   if ( rank == 2 ) {
      quadrado_y = y * y;
      MPI_Send(&quadrado_y, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
      printf("Processo-Filho 2: O quadrado de Y e %d \n", quadrado_y);
   }
   
   if ( rank == 3 ) {
      produto_xy = x * y;
      MPI_Send(&produto_xy, 13, MPI_INT, 0, type, MPI_COMM_WORLD);
      printf("Processo-Filho 3: O produto de XY e %d \n", produto_xy);
   }
   
   MPI_Finalize(); 
   return 0; 
}
