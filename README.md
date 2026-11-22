# DSA C Programs

A simple category-based website containing **29 standalone C programs**. Every algorithm has its own `main.c` file.

## Website navigation

Open the website and choose a category:
- **Sorting:** Merge, Quick, Bucket, Radix, Bubble, Insertion, Selection
- **Searching:** Linear, Binary
- **Series:** Geometric series (formula, single loop, nested loop)
- **Recursion:** Tower of Hanoi (recursive and iterative)
- **Greedy & Dynamic Programming:** Kadane's, Fractional Knapsack, Job Scheduling, 0/1 Knapsack
- **Graphs:** Prim's, Kruskal's, Dijkstra's, Bellman-Ford, Floyd-Warshall, Topological Sort, BFS, Connected Components, Directed/Undirected Cycle Detection
- **Backtracking:** 4-Queens

## Important assignment programs from the lab sheet

1. **Merge Sort and Quick Sort** — `programs/sorting/01-merge-sort/main.c`, `programs/sorting/02-quick-sort/main.c`
2. **Fractional Knapsack (Greedy)** — `programs/15-fractional-knapsack/main.c`
3. **Bellman-Ford with negative-cycle detection** — `programs/20-bellman-ford/main.c`
4. **DFS Topological Sort using adjacency list** — `programs/graphs/07-topological-sort/main.c`
5. **BFS traversal** — `programs/graphs/11-breadth-first-search/main.c`

## Compile and run

Open the folder containing the required `main.c` file:

```bash
gcc main.c -o program
./program
```

For `programs/09-geometric-series-formula/main.c`, link the math library:

```bash
gcc main.c -o program -lm
./program
```

On Windows, run `program.exe`.

## Notes

- Binary Search expects ascending sorted input.
- Bucket Sort accepts values in [0, 1).
- Radix Sort accepts non-negative integers.
- Dijkstra requires non-negative edge weights.
- Prim and Kruskal are for undirected weighted graphs.
- Bellman-Ford supports negative edge weights and detects reachable negative cycles.
- Graph vertices are numbered from 0.
- BFS and Topological Sort use adjacency-list representations.
- Topological Sort source code uses a DFS traversal and adjacency list, and reports a cycle if no topological order exists.
- GitHub Pages displays source code; it does not compile or run C programs in the browser.
