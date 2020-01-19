#include <omp.h>
#include <stdio.h>

int main(void)
{
  #pragma omp parallel for // try to remove for for keyword
  for (int i = 0; i < 5; i++)
  {
      printf("Hi %d\n",i);
  }

  puts("End.");
  
  return 0;
}
