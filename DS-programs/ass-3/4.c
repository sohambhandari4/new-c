//2)	Write a C program to accept n student names from user store it in an array.
// Accept a student name from the user and use linear/Sequential search method to check 
// whether the student name is present in array or not. Display proper message.
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

int linearSearch(char names[][MAX_NAME_LENGTH], int n, char key[])
 {
    for (int i = 0; i < n; i++)
     {
        if (strcmp(names[i], key) == 0) 
        {
            return 1; // Name found
        }
    }
    return 0; // Name not found
}

int main() {
    int n;
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];

    printf("Enter the number of student names: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS) 
    {
        printf("Exceeded the maximum number of students.\n");
        return 1;
    }

    printf("Enter %d student names:\n", n);
    for (int i = 0; i < n; i++)
     {
        scanf("%s", names[i]);
    }

    char key[MAX_NAME_LENGTH];
    printf("Enter the student name to search: ");
    scanf("%s", key);

    int result = linearSearch(names, n, key);

    if (result) 
    {
        printf("Student name \"%s\" is present in the array.\n", key);
    }
     else
      {
        printf("Student name \"%s\" is not present in the array.\n", key);
    }

    return 0;
}
