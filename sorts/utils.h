#ifndef SORTS_UTILS_H
#define SORTS_UTILS_H
#include <stdio.h>

#define MIN_SPAN 50 // minimum span between elements swapped
#define VAR 50 // variability span


// Swap elements in position i and j in list l
void swap(int *l, int i, int j) {
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

void print(int *l, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d, ", l[i]);
    }
    printf("\n\n");
}

int* copy_array(int *l, int n) {
    int i;
    int *array = malloc(n * sizeof (int));
    for(i = 0; i < n; i++) {
        array[i] = l[i];
    }
    return array;
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

void skew_array(int *l, int n) {
    int i, j;
    i = 0;
    j = n - 1;
    while(i < j) {
        swap(l, i, j);
        i += MIN_SPAN + rand() % VAR;
        j -= MIN_SPAN + rand() % VAR;
    }
}
#endif
