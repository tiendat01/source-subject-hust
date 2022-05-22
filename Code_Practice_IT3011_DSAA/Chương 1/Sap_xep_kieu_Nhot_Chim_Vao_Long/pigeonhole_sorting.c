#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// apply only to positive number
void pigeonhole_sort(unsigned int a[], int n) {
    unsigned int *b;    // dynamic array store frequence of distinct numbers in a
    unsigned int max_number = 0; // max_number of a = size of b;
    for (int i = 0; i < n; i++)
        if (max_number < a[i]) 
            max_number = a[i];
    b = (int *)calloc(max_number+1, sizeof(int)); // initialize element in b[] by 0
    for (int i = 0; i < n; i++)
        b[a[i]]++;

    int new_index = 0; // index of a[] to fill the true order
    for (unsigned int i = 0; i <= max_number; i++) {
        while (b[i]) {
            a[new_index++] = i;
            b[i]--;
        }
    } // O(n^2)
}

int main() {
    int n = 9, i;
 
    int input[] = {1, 5, 2, 7, 3, 4, 4, 1, 5};

    pigeonhole_sort(input, 9);

    printf("Sorted Array : ");
    for(i = 0; i < n; i++)
        printf("%d ", input[i]);
 
    return 0;
}