/* Breadth-First Search (BFS) using an adjacency list */
#include <stdio.h>
#define MAXV 100
#define MAXE 5000
int head[MAXV], to[2 * MAXE], nextEdge[2 * MAXE], edgeCount;
int visited[MAXV], queue[MAXV];
void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}
int main(void) {
    int n, m, u, v, start, front = 0, rear = 0;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d%d", &n, &m) != 2 || n < 1 || n > MAXV || m < 0 || m > MAXE) return 1;
    for (int i = 0; i < n; i++) head[i] = -1;
    printf("Enter each undirected edge (u v), vertices 0 to %d:\n", n - 1);
    for (int i = 0; i < m; i++) {
        if (scanf("%d%d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n) return 1;
        addEdge(u, v);
        addEdge(v, u);
    }
    printf("Enter starting vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) return 1;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);
        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            v = to[e];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}