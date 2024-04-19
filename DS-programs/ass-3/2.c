//2)	Write a C program to accept n elements from user store it in an array.
// Accept a value from the user and use recursive binary search method to check whether the value is present in array or not.
//  Display proper message.

#include <stdio.h>
int binarySearch(int arr[], int left, int right, int key) 
{
    if (left <= right)
     {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
        {
            return 1; // Element found
        }

        if (arr[mid] > key)
         {
            return binarySearch(arr, left, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, right, key);
    }

    return 0; // Element not found
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements (in sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result) 
    {
        printf("Element %d is present in the array.\n", key);
    } 
    else
     {
        printf("Element %d is not present in the array.\n", key);
    }
    return 0;
}
