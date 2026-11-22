/* DFS-based Topological Sort using an adjacency list */
#include <stdio.h>
#define MAXV 100
#define MAXE 5000
int head[MAXV], to[MAXE], nextEdge[MAXE], edgeCount;
int state[MAXV], order[MAXV], top, n;
void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}
int dfs(int v) {
    state[v] = 1;
    for (int e = head[v]; e != -1; e = nextEdge[e]) {
        int u = to[e];
        if (state[u] == 1) return 0;
        if (state[u] == 0 && !dfs(u)) return 0;
    }
    state[v] = 2;
    order[top++] = v;
    return 1;
}
int main(void) {
    int m, u, v;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d%d", &n, &m) != 2 || n < 1 || n > MAXV || m < 0 || m > MAXE) return 1;
    for (int i = 0; i < n; i++) head[i] = -1;
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        if (scanf("%d%d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n) return 1;
        addEdge(u, v);
    }
    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && !dfs(i)) {
            printf("Cycle detected: topological ordering is not possible.\n");
            return 0;
        }
    }
    printf("Topological order: ");
    while (top > 0) printf("%d ", order[--top]);
    printf("\n");
    return 0;
}