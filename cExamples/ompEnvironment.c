#include <stdio.h>
#include <omp.h>
int main(int argc)
{
int nthreads, tid, procs, maxt, inpar, dynamic, nested;

printf("%d\n", omp_in_parallel());
// Start parallel region /
#pragma omp parallel private(nthreads, tid)
//Teaching Assistant: Assist. Prof., PhD Iva Nikolova, Computer Systems Department
{
// Obtain thread number
tid = omp_get_thread_num();
// Only master thread does this
if (tid == 0)
{
printf("Thread %d getting environment info...\n", tid);
// Get environment information
procs = omp_get_num_procs();
nthreads = omp_get_num_threads();
maxt = omp_get_max_threads();
inpar = omp_in_parallel();
dynamic = omp_get_dynamic();
nested = omp_get_nested();
// Print environment information
printf("Number of processors = %d\n", procs);
printf("Number of threads = %d\n", nthreads);
printf("Max threads = %d\n", maxt);
printf("In parallel? = %d\n", inpar);
printf("Dynamic threads enabled? = %d\n", dynamic);
printf("Nested parallelism supported? = %d\n", nested);
}
}
// Done
return 0;
}