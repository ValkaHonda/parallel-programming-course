#include <omp.h>
#include <stdio.h>

int main(void)
{
  #pragma omp parallel
  printf("Hello, world.\n");
  return 0;
}

//gcc -fopenmp simpleExample.c -o simpleExample.output
//./simpleExample.output 
