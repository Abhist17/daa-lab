#include <stdio.h>

int main() {
    int a[10], n, i, j, min, temp;
    int comparisons = 0, swaps = 0;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min])
                min = j;
        }

        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }

        printf("After pass %d: ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    return 0;
}


// Worst and Best - O(n^2)