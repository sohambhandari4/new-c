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

// Function to count the total degree, in-degree, and out-degree of a vertex
void countDegrees(int matrix[][100], int vertices, int vertex) {
    int inDegree = 0;
    int outDegree = 0;

    for (int i = 0; i < vertices; i++) {
        if (matrix[vertex][i] == 1) {
            outDegree++;
        }
        if (matrix[i][vertex] == 1) {
            inDegree++;
        }
    }

    int totalDegree = inDegree + outDegree;

    printf("Vertex %d: Total Degree = %d, In-Degree = %d, Out-Degree = %d\n", vertex, totalDegree, inDegree, outDegree);
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[100][100];

    readGraph(adjacencyMatrix, vertices);
    displayGraph(adjacencyMatrix, vertices);

    int vertex;

    printf("Enter a vertex to count its degrees: ");
    scanf("%d", &vertex);

    countDegrees(adjacencyMatrix, vertices, vertex);

    return 0;
}
