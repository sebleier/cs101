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

int* copy(int *l, int n) {
    int i;
    int *array = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        array[i] = l[i];
    }
    return array;
}

float benchmark(int *l, int n, void(*func)(int *, int, int)) {
    int *sample = copy(l, n);
    clock_t cycles, tick_count = clock(); // start

    func(sample, 0, n - 1);

    cycles = clock() - tick_count; // stop
    free(sample);
	return (float)cycles / (float)CLOCKS_PER_SEC;
}

int power(int base, int exp) {
    int i;
    int prod = 1;
    if(exp == 0)
        return 1;
    for(i = 0; i < exp; i++) {
        prod *= base;
    }
    return prod;
}

int parse_int(char *num) {
    int i;
    int exp = 0;
    int sum = 0;
    while(num[i++] != '\0') {}
    i -= 2;
    while(i >= 0) {
        sum += ((int)num[i] - 48) * power(10, exp);
        exp += 1;
        i--;
    }
    return sum;
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
    skew(ascending, n);

    // initialize decending sample
    printf("Initialize descending sample\n");
    int *descending = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        descending[n - 1 - i] = i;
    }
    skew(descending, n);

	printf("Quicksort Times:\n");
	printf("    Random: %f\n", benchmark(random, n, quicksort));
	printf("    Near Ascending Order: %f\n", benchmark(ascending, n, quicksort));
	printf("    Near Descending Order: %f\n", benchmark(descending, n, quicksort));

	printf("Insertion Sort Times:\n");
	printf("    Random: %f\n", benchmark(random, n, insertion));
	printf("    Near Ascending Order: %f\n", benchmark(ascending, n, insertion));
	printf("    Near Descending Order: %f\n", benchmark(descending, n, insertion));

    return 0;
}

