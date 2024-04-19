#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create and display the adjacency list from an adjacency matrix
void createAndDisplayAdjList(int matrix[][100], int vertices) {
    struct AdjList adjList[100]; // Assuming a maximum of 100 vertices

    // Initialize the adjacency list
    for (int i = 0; i < vertices; i++) {
        adjList[i].head = NULL;
    }

    // Convert the adjacency matrix to the adjacency list
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j] == 1) {
                struct Node* newNode = createNode(j);
                newNode->next = adjList[i].head;
                adjList[i].head = newNode;
            }
        }
    }

    // Display the adjacency list
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d -> ", i);
        struct Node* current = adjList[i].head;
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[100][100];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    createAndDisplayAdjList(adjacencyMatrix, vertices);

    return 0;
}
