

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

// Function to perform BFS traversal
void BFS(struct AdjList adjList[], int vertices, int startVertex) {
    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of the dequeued vertex
        struct Node* temp = adjList[currentVertex].head;
        while (temp != NULL) {
            int adjacentVertex = temp->vertex;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                queue[rear++] = adjacentVertex;
            }
            temp = temp->next;
        }
    }

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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(adjList, vertices, startVertex);

    return 0;
}
