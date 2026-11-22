/* Breadth-First Search (BFS) - Undirected graph using adjacency list */
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], queue[MAX];
int main(void) {
    int n, m, u, v, start, front = 0, rear = 0;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d%d", &n, &m) != 2 || n < 1 || n > MAX || m < 0 || m > MAX * MAX) return 1;
    printf("Enter each edge (u v), using vertices 0 to %d:\n", n - 1);
    for (int i = 0; i < m; i++) {
        if (scanf("%d%d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n) return 1;
        graph[u][v] = graph[v][u] = 1;
    }
    printf("Enter starting vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) return 1;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);
        for (v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}