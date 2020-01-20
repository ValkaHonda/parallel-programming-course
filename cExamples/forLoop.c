#include <omp.h>
#include <stdio.h>

int main(void)
{
  #pragma omp parallel for // try to remove for for keyword
  for (int i = 0; i < 5; i++)
  {
    int tid = omp_get_thread_num();
      printf("Hi, from thread with ID:%d index--> %d\n",tid,i);
  }

  puts("End.");
  
  return 0;
}
