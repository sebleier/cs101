#ifndef SORTS_QUICKSORT_H
#define SORTS_QUICKSORT_H

#include "insertion.h"
#include "utils.h"


// Selection technique for choosing a pivot for quicksort
int median3(int *l, int left, int right) {
    int center = (left + right) / 2;
    if(l[center] < l[left])
        swap(l, left, center);
    if(l[right] < l[left])
        swap(l, left, right);
    if(l[right] < l[center])
        swap(l, center, right);
    swap(l, center, right - 1);
    return l[right - 1];
}

/*
    Recursive implementation of quicksort.
    If the gap between the left and right are less than a certain number, use
    insertion sort.

    Running Times:
    ==============

        Worst Case: O(n^2)
        Best Case: O(n*log(n))
*/
void quicksort(int *l, int left, int right) {
    int i, j, p;
    if(right - left > 16) {
        p = median3(l, left, right);
        i = left; j = right - 1;
        for( ; ; ) {
            while(l[++i] < p) {}
            while(p < l[--j]) {}
            if(i < j)
                swap(l, i, j);
            else
                break;
        }
        swap(l, i, right-1);
        quicksort(l, left, i-1);
        quicksort(l, i+1, right);
    }
    else
        insertion(l, left, right);
    return;
}
#endif

