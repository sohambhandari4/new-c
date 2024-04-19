#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

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

// Function to add an edge to the adjacency list
void addEdge(struct AdjList adjList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;
}

// Function for the DFS traversal
void DFSUtil(struct AdjList adjList[], bool visited[], int currentVertex) {
    visited[currentVertex] = true;
    printf("%d ", currentVertex);

    struct Node* temp = adjList[currentVertex].head;
    while (temp != NULL) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFSUtil(adjList, visited, adjacentVertex);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal
void DFS(struct AdjList adjList[], int vertices, int startVertex) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFSUtil(adjList, visited, startVertex);
    printf("\n");
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    struct AdjList adjList[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        adjList[i].head = NULL;
    }

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    DFS(adjList, vertices, startVertex);

    return 0;
}
