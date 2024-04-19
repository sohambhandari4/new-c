#include <stdio.h>

// Function to read a graph as an adjacency matrix
void readGraph(int matrix[][100], int vertices) {
    printf("Enter the adjacency matrix for the graph:\n");

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display the adjacency matrix
void displayGraph(int matrix[][100], int vertices) {
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[100][100];

    readGraph(adjacencyMatrix, vertices);
    displayGraph(adjacencyMatrix, vertices);

    return 0;
}
