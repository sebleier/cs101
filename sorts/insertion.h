/*
    Insertion Sort:
    ===============

    Running Times:
        Worst Case: O(n^2)
        Best Case: O(n)
*/
void insertion_sort(int *l, int left, int right) {
    int i, p, tmp;
    for(p = left + 1; p <= right; p++) {
        tmp = l[p];
        for(i = p; i > left && tmp < l[i - 1]; i--)
            l[i] = l[i - 1];
        l[i] = tmp;
    }
    return;
}

