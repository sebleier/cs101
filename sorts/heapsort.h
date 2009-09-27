#ifndef SORTS_HEAP_H
#define SORTS_HEAP_H

#include "../datastructures/heaps/binary.h"
#include "utils.h"
#include <stdio.h>

void heapsort(int *l, int left, int right) {

    int i = 0;
    struct BinaryHeap bh;
    bh.length = right - left + 1;
    bh.array = copy_array(l, bh.length);
    build_heap(&bh);
    while(!is_empty(&bh)) {
        l[i++] = remove_min(&bh);
    }
}

#endif
