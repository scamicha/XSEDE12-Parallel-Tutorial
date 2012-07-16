#include <stdio.h>
#include <mpi.h>

int main (argc, argv)
     int argc;
     char *argv[];
{
  MPI_Init (&argc, &argv);	/* starts MPI */
  printf( "Hello world! \n");
  MPI_Finalize();              /* ends MPI */
  return 0;
}
