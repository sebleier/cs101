/*
    Sorting Algorithm Driver:
    =========================

    The driver program will create three arrays of size n.  One array will be
    a set of completely pseudo-random numbers, seeded by time.  The other two
    will be nearly sorted, one in ascending and one in decending.  To break up
    the ordered arrays, I'm going to start on both ends and every
    (50 + rand() % 50)th element going inward will be swapped until the right
    side is less than the left side.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "quicksort.h"
#include "insertion.h"
#include "heapsort.h"


/*
    Use function pointer to call sorting algorithm
*/
float benchmark(int *l, int n, void(*func)(int *, int, int)) {
    int *sample = copy_array(l, n);
    clock_t cycles, tick_count = clock(); // start

    func(sample, 0, n - 1);

    cycles = clock() - tick_count; // stop
    free(sample);
	return (float)cycles / (float)CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {
    int i, j;
    clock_t tick_count, cycles;
    int n = parse_int(argv[1]);
    // initialize random sample
    printf("Initialize random sample\n");
    int *random = malloc(n * sizeof (int));
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        random[i] = rand() % n;
    }

    // initialize ascending sample
    printf("Initialize ascending sample\n");
    int *ascending = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        ascending[i] = i;
    }
    skew_array(ascending, n);

    // initialize decending sample
    printf("Initialize descending sample\n");
    int *descending = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        descending[n - 1 - i] = i;
    }
    skew_array(descending, n);

	printf("Quicksort Times:\n");
	printf("    Random: %f\n", benchmark(random, n, quicksort));
	printf("    Near Ascending Order: %f\n", benchmark(ascending, n, quicksort));
	printf("    Near Descending Order: %f\n", benchmark(descending, n, quicksort));

    /*
    Fuck Insertion sort! It's too slow for large datasets (not surprisingly)
	printf("Insertion Sort Times:\n");
	printf("    Random: %f\n", benchmark(random, n, insertion));
	printf("    Near Ascending Order: %f\n", benchmark(ascending, n, insertion));
	printf("    Near Descending Order: %f\n", benchmark(descending, n, insertion));
    */

    printf("Heap Sort Times:\n");
	printf("    Random: %f\n", benchmark(random, n, heapsort));
	printf("    Near Ascending Order: %f\n", benchmark(ascending, n, heapsort));
	printf("    Near Descending Order: %f\n", benchmark(descending, n, heapsort));

    return 0;
}

