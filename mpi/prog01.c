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
 
   //system("clear");
  
   if ( rank == 0 ) {
      printf("Processo-Pai: O valor de N e %d\n",n);
      n = 5;
      printf ("Processo-Pai: O valor de N e %d\n",n);
      //MPI_Send( &n, 13, MPI_INT, 1, type, MPI_COMM_WORLD);
      //MPI_Send( &n, 13, MPI_INT, 2, type, MPI_COMM_WORLD);
      //MPI_Send( &n, 13, MPI_INT, 3, type, MPI_COMM_WORLD);
   }

   if ( rank == 1 ) {
      //MPI_Recv(&n, 13, MPI_INT, 0, type, MPI_COMM_WORLD, &status);
      printf ("Processo-Filho 1: O valor de N e %d \n",n);
   }

   if ( rank == 2 ) {
      //MPI_Recv(&n, 13, MPI_INT, 0, type, MPI_COMM_WORLD, &status);
      printf ("Processo-Filho 2: O valor de N e %d \n",n);
   }
   
   if ( rank == 3 ) {
      //MPI_Recv(&n, 13, MPI_INT, 0, type, MPI_COMM_WORLD, &status);
      printf ("Processo-Filho 3: O valor de N e %d \n",n);
   }
   
   MPI_Finalize(); 
   return 0; 
}
