#include <stdio.h>

void splitAndMerge(int arr[15], int low, int high);
void display(int arr[15], int n);
void merge(int arr[15], int low, int mid, int high);

void main() {
    int arr[15], i, n;
    printf("Enter array size : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    splitAndMerge(arr, 0, n - 1);
    printf("After sorting the elements are : ");
    display(arr, n);
}

void display(int arr[15], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[15], int low, int mid, int high) {
    int temp[1005];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void splitAndMerge(int arr[15], int low, int high) {
    if (low < high) {
        int mid = (high - low) / 2 + low;

        splitAndMerge(arr, low, mid);
        splitAndMerge(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
