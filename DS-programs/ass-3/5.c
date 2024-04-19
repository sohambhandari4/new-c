#include <stdio.h>
#include <string.h>

#define MAX_CITY_LENGTH 50
#define MAX_CITIES 10

int linearSearch(char cities[][MAX_CITY_LENGTH], int stdCodes[], int n, char key[]) 
{
    for (int i = 0; i < n; i++)
     {
        if (strcmp(cities[i], key) == 0) 
        {
            return stdCodes[i]; // City found, return STD code
        }
    }
    return -1; // City not found
}

int main() {
    char cities[MAX_CITIES][MAX_CITY_LENGTH];
    int stdCodes[MAX_CITIES];
    int n = 0; // Number of cities read from the file

    FILE *file = fopen("cities.txt", "r");
    if (file == NULL)
     {
        printf("File 'cities.txt' not found.\n");
        return 1;
    }

    // Read city names and STD codes from the file
    while (fscanf(file, "%s %d", cities[n], &stdCodes[n]) != EOF) 
    {
        n++;
    }

    fclose(file);

    char key[MAX_CITY_LENGTH];
    printf("Enter the name of the city to search: ");
    scanf("%s", key);

    int result = linearSearch(cities, stdCodes, n, key);

    if (result != -1) {
        printf("STD code for %s is %d.\n", key, result);
    } else {
        printf("City not in the list.\n");
    }

    return 0;
}
