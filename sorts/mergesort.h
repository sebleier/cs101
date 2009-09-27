#ifndef SORTS_MERGESORT_H
#define SORTS_MERGESORT_H

void merge(int *l, int *tmp, int left, int center, int right) {
    int i = left;
    int j = center + 1;
    int ptr = left;
    while(i <= center && j <= right) {
        if(l[i] <= l[j])
            tmp[ptr++] = l[i++];
        else
            tmp[ptr++] = l[j++];
    }
    while(i <= center) { tmp[ptr++] = l[i++]; } // copy remaining left half
    while(j <= right) { tmp[ptr++] = l[j++]; } // copy remaining right half
    for(i = left; i <= right; i++) { l[i] = tmp[i]; } // copy temp array back to original
}

void _mergesort(int *l, int *tmp, int left, int right) {
    if(right > left) {
        int center = left + ((right - left) / 2);
        _mergesort(l, tmp, left, center);
        _mergesort(l, tmp, center + 1, right);
        merge(l, tmp, left, center, right);
    }
}

void mergesort(int *l, int left, int right) {
    int *tmp = malloc((right - left + 1) * sizeof (int));
    _mergesort(l, tmp, left, right);
}

#endif
