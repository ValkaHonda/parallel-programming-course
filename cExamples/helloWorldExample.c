// OpenMP_HelloWorld.cpp : Defines the entry point for the console application.
//#include "stdafx.h"
#include <omp.h>
#include <stdio.h>
int main(int argc)
{
int tid, nthreads, nprocs;
// Sets the number of processors that are available to the program
nprocs = omp_get_num_procs();
printf("Number of processors = %d\n", nprocs);
//Sets the number of threads in subsequent parallel regions to be equal to the
//number of logical processors on the machine. For example, if you have a machine with
//one physical processor that has hyperthreading enabled, it will have two logical
//processors and, therefore, two threads.
omp_set_num_threads(nprocs);
//
#pragma omp parallel private(nthreads, tid)
{
// Determine the number of threads that will be deployed for the parallel
//region
tid = omp_get_thread_num();
printf("\nHello World is being printed by the thread id %d\n", tid);
// The master thread of the team is thread 0
if (tid == 0)
{
printf("\nMaster prints Num of threads \n");
nthreads = omp_get_num_threads();
printf("Total number of threads = %d\n", nthreads);
} else {
    puts("Not a Master thread.");
}

}
return 0;
}