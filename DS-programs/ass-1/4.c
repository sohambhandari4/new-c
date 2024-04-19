//	Write a C program to read the data from the file “person.txt” which contains personno and
// personage and sort the data on age in ascending order using insertion Sort.


#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a person
struct Person {
    int personno;
    int personage;
};

// Function to perform the insertion sort on an array of persons based on age
void insertionSort(struct Person arr[], int n) {
    int i, j;
    struct Person key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].personage > key.personage) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    FILE *file;
    file = fopen("person.txt", "r");
    
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int n, i;

    // Count the number of lines (assuming each line corresponds to a person's record)
    n = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            n++;
        }
    }

    rewind(file);  // Reset the file pointer to the beginning

    // Create an array to hold the person data
    struct Person persons[n];

    // Read data from the file into the array
    for (i = 0; i < n; i++) {
        fscanf(file, "%d %d", &persons[i].personno, &persons[i].personage);
    }

    fclose(file);

    // Sort the array using insertion sort
    insertionSort(persons, n);

    // Display the sorted data
    printf("Sorted Person Records (ascending order by age):\n");
    for (i = 0; i < n; i++) {
        printf("Person No: %d, Person Age: %d\n", persons[i].personno, persons[i].personage);
    }

    return 0;
}
