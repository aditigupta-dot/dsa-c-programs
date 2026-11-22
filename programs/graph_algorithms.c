/*
 * GRAPH ALGORITHMS
 * Compile: gcc graph_algorithms.c -o graph_algorithms
 * Input graph as vertices and weighted edges (0-based vertex numbers).
 * For unweighted DFS/cycle/topological tasks, enter weight 1.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXE 5000
#define INF 1000000000

typedef struct { int u, v, w; } Edge;

/* 15. PRIM'S MINIMUM SPANNING TREE (undirected, connected graph). */
void prim(int g[MAX][MAX], int n) {
    int key[MAX], parent[MAX], used[MAX] = {0};
    for (int i = 0; i < n; i++) { key[i] = INF; parent[i] = -1; }
    key[0] = 0;
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!used[v] && (u == -1 || key[v] < key[u])) u = v;
        if (u == -1 || key[u] == INF) break;
        used[u] = 1;
        for (int v = 0; v < n; v++)
            if (!used[v] && g[u][v] < key[v]) {
                key[v] = g[u][v]; parent[v] = u;
            }
    }
    int total = 0, edges = 0;
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            printf("%d - %d : %d\n", parent[v], v, g[parent[v]][v]);
            total += g[parent[v]][v]; edges++;
        }
    }
    if (edges != n - 1) printf("Graph is disconnected; no single MST exists.\n");
    else printf("MST total weight = %d\n", total);
}

/* 16. KRUSKAL'S MINIMUM SPANNING TREE. */
int findSet(int parent[], int x) {
    if (parent[x] != x) parent[x] = findSet(parent, parent[x]);
    return parent[x];
}
void unionSet(int parent[], int rank[], int a, int b) {
    a = findSet(parent, a); b = findSet(parent, b);
    if (a == b) return;
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[a] > rank[b]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}
int compareEdge(const void *a, const void *b) {
    int x = ((const Edge *)a)->w, y = ((const Edge *)b)->w;
    return (x > y) - (x < y);
}
void kruskal(Edge edges[], int n, int m) {
    int parent[MAX], rank[MAX] = {0}, total = 0, chosen = 0;
    for (int i = 0; i < n; i++) parent[i] = i;
    qsort(edges, (size_t)m, sizeof(Edge), compareEdge);
    for (int i = 0; i < m && chosen < n - 1; i++) {
        int a = findSet(parent, edges[i].u), b = findSet(parent, edges[i].v);
        if (a != b) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w; chosen++;
            unionSet(parent, rank, a, b);
        }
    }
    if (chosen != n - 1) printf("Graph is disconnected; minimum spanning forest shown.\n");
    printf("Total weight = %d\n", total);
}

/* 17. DIJKSTRA'S SHORTEST PATH: all edge weights must be non-negative. */
void dijkstra(int g[MAX][MAX], int n, int source) {
    int dist[MAX], done[MAX] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (u == -1 || dist[u] == INF) break;
        done[u] = 1;
        for (int v = 0; v < n; v++)
            if (!done[v] && g[u][v] != INF && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("Distance to %d = INF\n", i);
        else printf("Distance to %d = %d\n", i, dist[i]);
    }
}

/* 18. BELLMAN-FORD: directed edges; supports negative weights. */
void bellmanFord(const Edge edges[], int m, int n, int source) {
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;
    for (int i = 1; i < n; i++) {
        int changed = 0;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; changed = 1;
            }
        }
        if (!changed) break;
    }
    for (int j = 0; j < m; j++)
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("Reachable negative-weight cycle exists.\n");
            return;
        }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("Distance to %d = INF\n", i);
        else printf("Distance to %d = %d\n", i, dist[i]);
    }
}

/* 19. FLOYD-WARSHALL: all-pairs shortest paths. */
void floydWarshall(int dist[MAX][MAX], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (dist[i][j] == INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        printf("\n");
    }
}

/* 21. TOPOLOGICAL SORT using DFS; detects a directed cycle. */
int topoDfs(int g[MAX][MAX], int n, int v, int state[], int stack[], int *top) {
    state[v] = 1;
    for (int u = 0; u < n; u++) if (g[v][u] != INF && v != u) {
        if (state[u] == 1) return 0;
        if (state[u] == 0 && !topoDfs(g, n, u, state, stack, top)) return 0;
    }
    state[v] = 2;
    stack[(*top)++] = v;
    return 1;
}
void topologicalSort(int g[MAX][MAX], int n) {
    int state[MAX] = {0}, stack[MAX], top = 0;
    for (int v = 0; v < n; v++)
        if (state[v] == 0 && !topoDfs(g, n, v, state, stack, &top)) {
            printf("Topological sort is not possible: graph contains a cycle.\n");
            return;
        }
    printf("Topological order: ");
    while (top > 0) printf("%d ", stack[--top]);
    printf("\n");
}

/* 22. CONNECTED COMPONENTS in an undirected graph. */
void componentDfs(int g[MAX][MAX], int n, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int u = 0; u < n; u++)
        if (g[v][u] != INF && v != u && !visited[u])
            componentDfs(g, n, u, visited);
}
void connectedComponents(int g[MAX][MAX], int n) {
    int visited[MAX] = {0}, count = 0;
    for (int v = 0; v < n; v++) if (!visited[v]) {
        printf("Component %d: ", ++count);
        componentDfs(g, n, v, visited);
        printf("\n");
    }
    printf("Total connected components = %d\n", count);
}

/* 23A. UNDIRECTED CYCLE DETECTION using DFS and parent. */
int undirectedDfs(int g[MAX][MAX], int n, int v, int parent, int visited[]) {
    visited[v] = 1;
    for (int u = 0; u < n; u++) if (g[v][u] != INF && u != v) {
        if (!visited[u]) {
            if (undirectedDfs(g, n, u, v, visited)) return 1;
        } else if (u != parent) return 1;
    }
    return 0;
}
int hasUndirectedCycle(int g[MAX][MAX], int n) {
    int visited[MAX] = {0};
    for (int v = 0; v < n; v++)
        if (!visited[v] && undirectedDfs(g, n, v, -1, visited)) return 1;
    return 0;
}

/* 23B. DIRECTED CYCLE DETECTION using recursion-stack states. */
int directedDfs(int g[MAX][MAX], int n, int v, int state[]) {
    state[v] = 1;
    for (int u = 0; u < n; u++) if (g[v][u] != INF && u != v) {
        if (state[u] == 1) return 1;
        if (state[u] == 0 && directedDfs(g, n, u, state)) return 1;
    }
    state[v] = 2;
    return 0;
}
int hasDirectedCycle(int g[MAX][MAX], int n) {
    int state[MAX] = {0};
    for (int v = 0; v < n; v++)
        if (state[v] == 0 && directedDfs(g, n, v, state)) return 1;
    return 0;
}

int main(void) {
    int choice, n, m, directed = 0;
    int graph[MAX][MAX];
    Edge edges[MAXE];

    printf("1 Prim's MST (undirected)\n2 Kruskal's MST (undirected)\n");
    printf("3 Dijkstra (directed)\n4 Bellman-Ford (directed)\n5 Floyd-Warshall (directed)\n");
    printf("6 Topological Sort (directed)\n7 Connected Components (undirected)\n");
    printf("8 Undirected Cycle Detection\n9 Directed Cycle Detection\nChoice: ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 9) return 1;

    directed = (choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 9);
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter number of edges (0-%d): ", MAXE);
    if (scanf("%d", &m) != 1 || m < 0 || m > MAXE) return 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    printf("Enter each edge as: source destination weight (vertices 0 to %d)\n", n - 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        if (scanf("%d%d%d", &u, &v, &w) != 3 || u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge input\n"); return 1;
        }
        edges[i] = (Edge){u, v, w};
        if (w < graph[u][v]) graph[u][v] = w;
        if (!directed && w < graph[v][u]) graph[v][u] = w;
    }

    if (choice == 1) prim(graph, n);
    else if (choice == 2) kruskal(edges, n, m);
    else if (choice == 3) {
        int source;
        printf("Enter source vertex: ");
        if (scanf("%d", &source) != 1 || source < 0 || source >= n) return 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j] == 0 && i != j) graph[i][j] = INF;
        dijkstra(graph, n, source);
    } else if (choice == 4) {
        int source;
        printf("Enter source vertex: ");
        if (scanf("%d", &source) != 1 || source < 0 || source >= n) return 1;
        bellmanFord(edges, m, n, source);
    } else if (choice == 5) {
        floydWarshall(graph, n);
    } else if (choice == 6) {
        topologicalSort(graph, n);
    } else if (choice == 7) {
        connectedComponents(graph, n);
    } else if (choice == 8) {
        printf(hasUndirectedCycle(graph, n) ? "Cycle exists\n" : "No cycle\n");
    } else {
        printf(hasDirectedCycle(graph, n) ? "Cycle exists\n" : "No cycle\n");
    }
    return 0;
}
