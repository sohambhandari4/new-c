//4)	Write a C program to sort the elements by initializing the array (e.g int A[5] = {10, 20, 35, 23, 12}) using bubble sort

#include <stdio.h>

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++)
         {
            if (arr[j] > arr[j + 1])
             {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int A[] = {10, 20, 35, 23, 12};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    bubbleSort(A, n);

    printf("Sorted Array (ascending order): ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
