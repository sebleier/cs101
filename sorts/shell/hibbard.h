/*
    Shell sort using Hibbard increments
*/
#ifndef SORTS_SHELL_HIBBARD_H
#define SORTS_SHELL_HIBBARD_H

#include <math.h>
#include "../utils.h"

void hibbard(int *l, int left, int right) {
    int gap, i, j, tmp, n = right - left + 1;
    int k = (int)(log(n + 1) / log(2));
    for(gap = power(2, k) - 1; k > 0; gap = power(2, --k) - 1) {
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
