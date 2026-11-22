# DSA C Programs

A collection of complete, commented C programs for DSA lab practice and exam revision.

## Programs included

| Source file | Algorithms |
|---|---|
| `programs/sorting_searching.c` | Merge Sort, Quick Sort, Bucket Sort, Radix Sort, Bubble Sort, Insertion Sort, Linear Search, Binary Search |
| `programs/recursion_and_series.c` | Geometric series (formula, single loop, nested loop), Tower of Hanoi (recursive and iterative) |
| `programs/greedy_dynamic_programming.c` | Kadane's Algorithm, Fractional Knapsack, Job Scheduling with Deadlines, 0/1 Knapsack |
| `programs/graph_algorithms.c` | Prim, Kruskal, Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort, Connected Components, directed and undirected cycle detection |
| `programs/backtracking.c` | N-Queens / 4-Queens using backtracking |

The lab questions on connected components, undirected cycle detection, 4-Queens, directed and undirected cycle detection, and topological sorting are included in the graph/backtracking files.

## Compile and run

Install GCC, then compile a source file:

```bash
gcc programs/sorting_searching.c -o sorting_searching
./sorting_searching
```

For the geometric-series and Hanoi file, link the math library:

```bash
gcc programs/recursion_and_series.c -o recursion_and_series -lm
./recursion_and_series
```

On Windows, run the generated `.exe` file after compiling.

## Important assumptions

- Binary Search requires an ascending sorted array.
- Bucket Sort expects values in the range `[0, 1)`.
- Radix Sort expects non-negative integers.
- Dijkstra's algorithm requires non-negative edge weights.
- Bellman-Ford supports negative edges and checks for reachable negative-weight cycles.
- Prim's and Kruskal's algorithms are for undirected weighted graphs.
- Topological Sort applies only to a directed acyclic graph (DAG).
- Graph algorithms use 0-based vertex numbers and read edges as `source destination weight`.
- Job Scheduling assumes each job takes one time unit.
- The N-Queens program accepts N from 1 to 20; enter 4 for the 4-Queens lab problem.

## Website

The static website is hosted with GitHub Pages. It can display and copy source code, but it cannot compile or run C in the browser. Compile the downloaded source files locally.

Repository: https://github.com/aditigupta-dot/dsa-c-programs
