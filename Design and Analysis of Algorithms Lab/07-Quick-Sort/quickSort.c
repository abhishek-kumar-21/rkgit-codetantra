#include <stdio.h>

int partition(int a[], int p, int r) {
    int pivot = a[r];
    int i = p - 1;
    int j, temp;

    // Iterate through the array and place elements smaller than pivot to the left
    for (j = p; j < r; j++) {
        if (a[j] <= pivot) {
            i++;

            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place the pivot in its correct position
    temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;

    return (i + 1);
}

void quicksort(int a[], int p, int r) {
    int q;
    if (p < r) {
        // Find the partition index
        q = partition(a, p, r);

        // Recursively sort elements before and after partition
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void main() {
    int a[10], i, j, pivot, n, p, r;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    printf("Enter numbers to be sorted: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    p = 1;
    r = n;
    quicksort(a, p, r);
    printf("Sorted array is: ");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
