#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i, int *swaps) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        (*swaps)++;
        heapify(arr, n, smallest, swaps);
    }
}

void buildMinHeap(int arr[], int n, int *swaps) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swaps);
}

void heapSort(int arr[], int n) {
    int swaps = 0;
    
    buildMinHeap(arr, n, &swaps);
    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        swaps++;
        heapify(arr, i, 0, &swaps);
    }
    
    printf("Total swaps: %d\n", swaps);
}

int main() {
    int arr[] = {7, 2, 9, 4, 5, 3, 1, 6, 8};
    int n = 9;
    
    printf("Original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    heapSort(arr, n);
    
    printf("Sorted (descending): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}