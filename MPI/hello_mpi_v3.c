#include <stdio.h>
#include <mpi.h>

int main (argc, argv)
     int argc;
     char *argv[];
{
  int rank, size;
  int namelen;

  /* Message tag */
  int tag = 1;

  MPI_Init (&argc, &argv);	/* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);	/* get number of processes */

  if (rank == 0) {         /* Rank 0 is the master process */
    int x;
    char msg[50];
    MPI_Status status;
    
    printf( "From master: Hello world from process %d of %d\n", rank, size );

    for (x = 1; x < size; x++) {
      /* Receive messages in for loop order */
      MPI_Recv(msg, 50, MPI_CHARACTER, x, tag, MPI_COMM_WORLD, &status); 
      printf("From worker %d: %s", status.MPI_SOURCE, msg);
    }
  } else {
      char msg[50];

      snprintf(msg, 50,  "Hello world from process %d of %d\n", rank, size);
      MPI_Send(msg, 50, MPI_CHARACTER, 0, tag, MPI_COMM_WORLD);
   }

   MPI_Finalize();
   return 0;
}
