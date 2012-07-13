#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

  omp_set_num_threads(6);
 // Fork a team of threads
#pragma omp parallel
 {
   printf("Hello World! \n");
 }

}

