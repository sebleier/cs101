#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quicksort.h"


// Driver program to create a sample of a certain amount of pseudo-random
// integers seeded by the time.  It also tracks the amount of time needed
// to execute.
int main(int argc, char *argv[]) {
    int i;
    clock_t tick_count, cycles;
    int n = 20000000;
    int *sample = malloc(n * sizeof (int));

    // initialize random sample
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        sample[i] = rand() % n;
    }
    //print(sample, n);
	tick_count = clock();
    // timer started
    quicksort(sample, 0, n - 1);
    // stop timer
    //print(sample, n);
    cycles = clock() - tick_count;
	printf("Time: %f\n", (float)cycles / (float)CLOCKS_PER_SEC);

    return 0;
}

