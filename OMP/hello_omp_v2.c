#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

  int nthreads, tid;

  omp_set_num_threads(6);
#pragma omp master
  {
    nthreads = omp_get_num_threads();
    printf("There are %d threads available. \n", nthreads);
  }

 // Fork a team of threads and give a private copy of their thread number
#pragma omp parallel private(tid)
  {
    // Obtain thread number
   tid = omp_get_thread_num();
   printf("Hello World from thread = %d\n", tid);
  }

}

