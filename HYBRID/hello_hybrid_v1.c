#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int main (argc, argv)
     int argc;
     char *argv[];
{
  MPI_Init (&argc, &argv);	/* starts MPI */
  omp_set_num_threads(6);
  // Fork a team of threads
#pragma omp parallel
  {
    printf( "Hello world!");
  }
  MPI_Finalize();              /* ends MPI */
  return 0;
}
