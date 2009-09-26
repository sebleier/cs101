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

#define MIN_SPAN 50 // minimum span between elements swapped
#define VAR 50 // variability span

void skew(int *l, int n) {
    int i, j;
    i = 0;
    j = n - 1;
    while(i < j) {
        swap(l, i, j);
        i += MIN_SPAN + rand() % VAR;
        j -= MIN_SPAN + rand() % VAR;
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    clock_t tick_count, cycles;
    int n = 20000000;

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
    skew(ascending, n);

    // initialize decending sample
    printf("Initialize descending sample\n");
    int *descending = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        descending[n - 1 - i] = i;
    }
    skew(descending, n);

	tick_count = clock();
    // timer started
    quicksort(random, 0, n - 1);
    // stop timer
    cycles = clock() - tick_count;
	printf("Random Time: %f\n", (float)cycles / (float)CLOCKS_PER_SEC);

	tick_count = clock();
    // timer started
    quicksort(ascending, 0, n - 1);
    // stop timer
    cycles = clock() - tick_count;
	printf("Near Ascending Order Time: %f\n", (float)cycles / (float)CLOCKS_PER_SEC);

	tick_count = clock();
    // timer started
    quicksort(descending, 0, n - 1);
    // stop timer
    cycles = clock() - tick_count;
	printf("Near Descending Order Time: %f\n", (float)cycles / (float)CLOCKS_PER_SEC);

    return 0;
}

