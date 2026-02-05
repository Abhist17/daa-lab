#include <stdio.h>

int main() {
    int a[10], n, i, j, key;
    int comparisons = 0, swaps = 0;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            comparisons++;
            a[j + 1] = a[j];
            swaps++;
            j--;
        }
        a[j + 1] = key;

        printf("After step %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("Comparisons: %d\n", comparisons);
    printf("Shifts: %d\n", swaps);

    return 0;
}


// Worst - O(n^2)
// Best - O(n)