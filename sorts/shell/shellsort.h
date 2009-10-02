/*
    The Shell sort algorithm implemented with Donald Shell's
    ok, but not great gap sequence N / 2
*/

#ifndef SORTS_SHELL_SHELLSORT
#define SORTS_SHELL_SHELLSORT

#include <math.h>

void shellsort(int *l, int left, int right) {
    int gap, i, j, tmp, n = right - left + 1;
    for(gap = n / 2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i++) {
            tmp = l[i];
            j = i;
            for(; j >= gap && tmp < l[j - gap]; j -= gap)
                l[j] = l[j - gap];
            l[j] = tmp;
        }
    }
}

#endif
