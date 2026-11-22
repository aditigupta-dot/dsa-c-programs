# DSA C Programs — 27 Separate Programs

Every algorithm is stored in its **own folder** with an independent `main.c`. Nothing is combined into multi-algorithm source files.

## Program list

1. **Merge Sort** — [`programs/01-merge-sort/main.c`](programs/01-merge-sort/main.c)
2. **Quick Sort** — [`programs/02-quick-sort/main.c`](programs/02-quick-sort/main.c)
3. **Bucket Sort** — [`programs/03-bucket-sort/main.c`](programs/03-bucket-sort/main.c)
4. **Radix Sort** — [`programs/04-radix-sort/main.c`](programs/04-radix-sort/main.c)
5. **Bubble Sort** — [`programs/05-bubble-sort/main.c`](programs/05-bubble-sort/main.c)
6. **Insertion Sort** — [`programs/06-insertion-sort/main.c`](programs/06-insertion-sort/main.c)
7. **Linear Search** — [`programs/07-linear-search/main.c`](programs/07-linear-search/main.c)
8. **Binary Search** — [`programs/08-binary-search/main.c`](programs/08-binary-search/main.c)
9. **Geometric Series — Formula** — [`programs/09-geometric-series-formula/main.c`](programs/09-geometric-series-formula/main.c)
10. **Geometric Series — Single Loop** — [`programs/10-geometric-series-loop/main.c`](programs/10-geometric-series-loop/main.c)
11. **Geometric Series — Nested Loop** — [`programs/11-geometric-series-nested-loop/main.c`](programs/11-geometric-series-nested-loop/main.c)
12. **Tower of Hanoi — Recursive** — [`programs/12-tower-of-hanoi-recursive/main.c`](programs/12-tower-of-hanoi-recursive/main.c)
13. **Tower of Hanoi — Iterative** — [`programs/13-tower-of-hanoi-iterative/main.c`](programs/13-tower-of-hanoi-iterative/main.c)
14. **Kadane's Algorithm** — [`programs/14-kadanes-algorithm/main.c`](programs/14-kadanes-algorithm/main.c)
15. **Fractional Knapsack** — [`programs/15-fractional-knapsack/main.c`](programs/15-fractional-knapsack/main.c)
16. **Job Scheduling with Deadlines** — [`programs/16-job-scheduling-deadlines/main.c`](programs/16-job-scheduling-deadlines/main.c)
17. **Prim's Algorithm** — [`programs/17-prims-algorithm/main.c`](programs/17-prims-algorithm/main.c)
18. **Kruskal's Algorithm** — [`programs/18-kruskals-algorithm/main.c`](programs/18-kruskals-algorithm/main.c)
19. **Dijkstra's Algorithm** — [`programs/19-dijkstras-algorithm/main.c`](programs/19-dijkstras-algorithm/main.c)
20. **Bellman-Ford Algorithm** — [`programs/20-bellman-ford/main.c`](programs/20-bellman-ford/main.c)
21. **Floyd-Warshall Algorithm** — [`programs/21-floyd-warshall/main.c`](programs/21-floyd-warshall/main.c)
22. **0/1 Knapsack** — [`programs/22-0-1-knapsack/main.c`](programs/22-0-1-knapsack/main.c)
23. **Topological Sort** — [`programs/23-topological-sort/main.c`](programs/23-topological-sort/main.c)
24. **Connected Components (DFS)** — [`programs/24-connected-components/main.c`](programs/24-connected-components/main.c)
25. **Undirected Cycle Detection (DFS)** — [`programs/25-undirected-cycle-detection/main.c`](programs/25-undirected-cycle-detection/main.c)
26. **Directed Cycle Detection (DFS)** — [`programs/26-directed-cycle-detection/main.c`](programs/26-directed-cycle-detection/main.c)
27. **4-Queens (Backtracking)** — [`programs/27-four-queens/main.c`](programs/27-four-queens/main.c)

## Compile and run

Open the folder of the program you want and compile its `main.c`:

```bash
gcc main.c -o program
./program
```

For `09-geometric-series-formula`, link the math library:

```bash
gcc main.c -o program -lm
./program
```

On Windows, run `program.exe` after compilation.

## Lab questions covered

- Q1 Connected Components — program 24
- Q2 Undirected Cycle Detection — program 25
- Q3 4-Queens — program 27
- Q4 Directed and Undirected Cycle Detection — programs 25 and 26
- Q5 Topological Sort — program 23

## Notes

- Binary Search expects ascending sorted input.
- Bucket Sort accepts values in `[0, 1)`.
- Radix Sort accepts non-negative integers.
- Dijkstra requires non-negative edge weights.
- Prim and Kruskal work on undirected weighted graphs.
- Bellman-Ford supports negative edge weights and detects reachable negative cycles.
- Graph vertices use zero-based numbering.
- Job Scheduling assumes unit-time jobs.

## Website

GitHub Pages homepage: [index.html](index.html)
