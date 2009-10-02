#ifndef SORTS_RADIX_H
#define SORTS_RADIX_H
/*
    1001 % 10 ^ (k + 1) = 1 /
    4000000000
*/
#include "utils.h"
#include <stdlib.h>


void radixsort(int *l, int left, int right) {
    int i, j, k, d;
    int n = right - left + 1;
    int sizes[10] = {0};
    int counts[10];
    int **bucket;
    bucket = (int **) malloc(10 * sizeof(int *));

    /*
        Go through each number and then each digit and increment a counter of
        how many times a number is seen in each
    */
    for(k = 0; k < 16; k++) {
        // initialize sizes
        for(d = 0; d < 10; d++) {
            sizes[d] = 0;
        }

        // Count the number of buckets required for each digit
        for(i = 0; i < n; i++) {
            d = (l[i] % power(10, k + 1)) / power(10, k);
            sizes[d]++;
        }

        // allocate the buckets for each digit
        for(d = 0; d < 10; d++) {
            bucket[d] = (int*)malloc(sizes[d] * sizeof(int));
        }

        // Initialize counts
        for(j = 0; j < 10; j++)
            counts[j] = 0;

        // Enqueue the numbers into their buckets
        for(i = 0; i < n; i++) {
            d = (l[i] % power(10, k + 1)) / power(10, k);
            bucket[d][counts[d]++] = l[i];
        }

        // Reinitialize counts
        for(j = 0; j < 10; j++)
            counts[j] = 0;

        // Dequeue the numbers back onto the original array
        i = 0;
        for(d = 0; d < 10; d++) {
            for(j = 0; j < sizes[d];j++) {
                l[i++] = bucket[d][j];
            }
        }

        // Deallocate memory for buckets
        for(d = 0; d < 10; d++) {
            free(bucket[d]);
        }
    }
}


#endif
