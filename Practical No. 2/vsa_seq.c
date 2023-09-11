#include <omp.h>
#include <stdio.h>
#include <pthread.h>

int main()
{
    int N = 100;
    int A[N];
    for(int i=0;i<N;i++)A[i] = i + 1;
    int S = 2000;

    double itime, ftime, exec_time;
    itime = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        A[i] += S;
        printf("Thread: %d Index: %d\n", omp_get_thread_num(),i);
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    
    printf("\nTime taken is %f\n", exec_time);
    printf("\n");
}
