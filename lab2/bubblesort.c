// DAA Practical Lab 2



// Bubble Sort with best optimization
#include <stdio.h>
#include <stdlib.h>


int main () {
    int a[10], n, i, j, temp;
    int comparisons = 0, swaps = 0;
    int swapped;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    for (i = 0; i < n-1; i++) {
        swapped = 0; 
        for (j = 0; j < n-i-1; j++) {
            comparisons++;
            if (a[j] > a[j+1]) {
            
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swaps++;
                swapped = 1; 
            }
        }

        printf("After pass %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");

        if (swapped == 0)
            break;
    }
    printf("comparisons: %d\n", comparisons);
    printf("swaps: %d\n", swaps);

    return 0;
}


// Worst - O(n^2)
// Best - O(n)