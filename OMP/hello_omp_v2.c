#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

  int nthreads, tid, maxthreads;

  omp_set_num_threads(6);

#pragma omp master
  {
    maxthreads = omp_get_max_threads();
    nthreads = omp_get_num_threads();
    printf("There are %d threads available. %d of these threads are currently active. \n", nthreads);
  }

 // Fork a team of threads and give a private copy of their thread number
#pragma omp parallel private(tid)
  {
    #pragma omp master
    {
      maxthreads = omp_get_max_threads();
      nthreads = omp_get_num_threads();
      printf("There are %d threads available. %d of these threads are currently active. \n", nthreads);
    }
    // Obtain thread number
   tid = omp_get_thread_num();
   printf("Hello World from thread = %d\n", tid);
  }

}

