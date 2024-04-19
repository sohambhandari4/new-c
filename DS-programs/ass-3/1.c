//1)	Write a C program to accept n elements from user store it in an array.
//   Accept a value from the user and use linear/Sequential search method 
//  to check whether the value is present in array or not.
//   Display proper message.#include <stdio.h>

int linearSearch(int arr[], int n, int key)
 {
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key)
         {
            return 1; // Element found
        }
    }
    return 0; // Element not found
}
int main()
 {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
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
