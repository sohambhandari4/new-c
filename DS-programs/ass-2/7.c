//3)	Write a C program to sort the elements by initializing the array 
//(e.g. int A[5] = {11, 12,15, 16, 17}) using Quick Sort 
#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int A[] = {11, 12, 15, 16, 17};
    int n = sizeof(A) / sizeof(A[0]); // Calculate the number of elements in the array

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Sort the array using quick sort
    quickSort(A, 0, n - 1);

    printf("Sorted Array (ascending order): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
