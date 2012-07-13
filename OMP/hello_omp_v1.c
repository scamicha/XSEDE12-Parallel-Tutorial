#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {


 // Fork a team of threads
#pragma omp parallel
 {
   printf("Hello World! \n");
 }

}

