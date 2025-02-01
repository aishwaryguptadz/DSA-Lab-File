// 1) Algorithm Dijkstra(graph, src, vertices)
// 2) Pre: graph is an adjacency matrix, src is the source vertex
// 3) Post: Shortest path from the source to all other vertices is calculated
// 4) Initialize dist[vertices] ← ∞ for all vertices
// 5) Initialize visited[vertices] ← 0 (not visited)
// 6) dist[src] ← 0
// 7) for count ← 0 to vertices - 1 do
// 8)     Find the vertex u with the minimum dist[u] that has not been visited
// 9)     visited[u] ← 1
// 10)    for each adjacent vertex v of u do
// 11)        if graph[u][v] ≠ 0 and visited[v] = 0 and dist[u] + graph[u][v] < dist[v] then
// 12)            dist[v] ← dist[u] + graph[u][v]
// 13)        end if
// 14)    end for
// 15) end for
// 16) Print the shortest distance from the source to all vertices
// 17) end Dijkstra

// 1) Algorithm FloydWarshall(graph, vertices)
// 2) Pre: graph is an adjacency matrix
// 3) Post: Shortest path matrix for all pairs of vertices is computed
// 4) Initialize dist[vertices][vertices] ← graph
// 5) for k ← 0 to vertices - 1 do
// 6)     for i ← 0 to vertices - 1 do
// 7)         for j ← 0 to vertices - 1 do
// 8)             if dist[i][j] > dist[i][k] + dist[k][j] then
// 9)                 dist[i][j] ← dist[i][k] + dist[k][j]
// 10)            end if
// 11)        end for
// 12)    end for
// 13) end for
// 14) Print the shortest distance matrix
// 15) end FloydWarshall

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Graph structure
typedef struct {
    int adjMatrix[MAX][MAX];
    int vertices;
} Graph;

// Function to initialize the graph
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge
void addEdge(Graph* g, int u, int v, int weight) {
    g->adjMatrix[u][v] = weight;
    g->adjMatrix[v][u] = weight;  // For undirected graph
}

// Function to take user input for the graph
void inputGraph(Graph* g) {
    int edges, u, v, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &g->vertices);
    initGraph(g, g->vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(g, u, v, weight);
    }
}

// Prim’s Algorithm to find MST
void primMST(Graph* g) {
    int parent[MAX]; // Array to store MST
    int key[MAX];    // Key values to pick minimum weight edge
    int visited[MAX]; // To track vertices in MST

    for (int i = 0; i < g->vertices; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;  // Starting from the first vertex
    parent[0] = -1;

    for (int count = 0; count < g->vertices - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < g->vertices; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < g->vertices; v++) {
            if (g->adjMatrix[u][v] && !visited[v] && g->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adjMatrix[u][v];
            }
        }
    }

    printf("Prim's MST:\n");
    for (int i = 1; i < g->vertices; i++) {
        printf("%d - %d: %d\n", parent[i], i, g->adjMatrix[i][parent[i]]);
    }
}

int main() {
    Graph g;
    inputGraph(&g);
    primMST(&g);
    return 0;
}
