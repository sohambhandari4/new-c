//	Write a C program to read the data from the file “employee.txt” 
// which contains empno and empname and sort the data on names alphabetically (use strcmp) using Bubble Sort.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of employees
#define MAX_EMPLOYEES 200

// Structure to store employee data
struct Employee {
    char name[20];
    int age;
    int sal;
};

int main() {
    struct Employee emp[MAX_EMPLOYEES];
    struct Employee temp;
    FILE *fp;
    int i = 0, size, j;
    char ch;

    // Open the file for reading
    fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("\nCannot open the file.\n");
        exit(0);
    }

    // Read employee data from the file
    while (ch != EOF) {
        fscanf(fp, "%s %d %d", emp[i].name, &emp[i].age, &emp[i].sal);
        ch = fgetc(fp);
        i++;
    }
    size = i - 1;

    // Bubble sort based on employee names
    for (i = 1; i < size; ++i) {
        for (j = 0; j < size - i; j++) {
            if (strcmp(emp[j + 1].name, emp[j].name) < 0) {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    // Create a new file to save the sorted data
    fp = fopen("empsorted.txt", "w");
    for (i = 0; i < size; i++) {
        fprintf(fp, "%s %d %d\n", emp[i].name, emp[i].age, emp[i].sal);
    }

    printf("\nThe file is sorted successfully and saved as empsorted.txt.\n\n");
    fclose(fp);
    return 0;
}
