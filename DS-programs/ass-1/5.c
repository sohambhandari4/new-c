//	Write a C program to sort a random array of n integers (value of n accepted from user) by using Bubble Sort algorithm in ascending order
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
     {
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
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
     {
        arr[i] = rand() % 100;  
    }

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++)
     {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted Array (ascending order): ");
    for (int i = 0; i < n; i++)
     {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
