#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_POINTS 100000000

int main() {
    srand(time(NULL));

    clock_t start_time = clock();

    int inside_circle = 0;

    omp_set_num_threads(4);

    #pragma omp parallel for reduction(+:inside_circle)
    for (int i = 0; i < NUM_POINTS; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        double distance = x * x + y * y;

        if (distance <= 1.0) {
            inside_circle++;
        }
    }

    double pi = 4.0 * inside_circle / NUM_POINTS;
    printf("Estimated Pi value (parallel): %lf\n", pi);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time (parallel): %lf seconds\n", execution_time);

    return 0;
}
