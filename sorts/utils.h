// Swap elements in position i and j in list l
void swap(int *l, int i, int j) {
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

// Print all elements in the list l
void print(int *l, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d, ", l[i]);
    }
    printf("\n");
    return;
}
