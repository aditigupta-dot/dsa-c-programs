/*
 * GREEDY AND DYNAMIC PROGRAMMING
 * Compile: gcc greedy_dynamic_programming.c -o greedy_dp
 */
#include <stdio.h>
#include <stdlib.h>

/* 12. KADANE'S ALGORITHM: maximum sum of a non-empty contiguous subarray. */
int kadane(const int a[], int n) {
    int current = a[0], best = a[0];
    for (int i = 1; i < n; i++) {
        current = (a[i] > current + a[i]) ? a[i] : current + a[i];
        if (current > best) best = current;
    }
    return best;
}

/* 13. FRACTIONAL KNAPSACK. */
typedef struct { double weight, profit; } Item;
int compareRatio(const void *a, const void *b) {
    double r1 = ((const Item *)a)->profit / ((const Item *)a)->weight;
    double r2 = ((const Item *)b)->profit / ((const Item *)b)->weight;
    return (r1 < r2) ? 1 : (r1 > r2) ? -1 : 0;
}
double fractionalKnapsack(Item items[], int n, double capacity) {
    qsort(items, (size_t)n, sizeof(Item), compareRatio);
    double total = 0.0;
    for (int i = 0; i < n && capacity > 0.0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total += items[i].profit;
        } else {
            total += items[i].profit * capacity / items[i].weight;
            capacity = 0.0;
        }
    }
    return total;
}

/* 14. JOB SEQUENCING WITH DEADLINES: each job takes one time unit. */
typedef struct { int id, deadline, profit; } Job;
int compareProfit(const void *a, const void *b) {
    int p1 = ((const Job *)a)->profit, p2 = ((const Job *)b)->profit;
    return (p1 < p2) ? 1 : (p1 > p2) ? -1 : 0;
}
void jobScheduling(Job jobs[], int n) {
    qsort(jobs, (size_t)n, sizeof(Job), compareProfit);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    if (maxDeadline > n) maxDeadline = n;

    int *slots = calloc((size_t)maxDeadline + 1, sizeof(int));
    if (!slots) { fprintf(stderr, "Memory allocation failed\n"); exit(EXIT_FAILURE); }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        int last = jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline;
        for (int t = last; t >= 1; t--) {
            if (slots[t] == 0) {
                slots[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Jobs in scheduled time slots: ");
    for (int t = 1; t <= maxDeadline; t++)
        if (slots[t] != 0) printf("%d ", slots[t]);
    printf("\nMaximum profit = %d\n", totalProfit);
    free(slots);
}

/* 20. 0/1 KNAPSACK using dynamic programming. */
int knapsack01(const int weight[], const int profit[], int n, int capacity) {
    int dp[101][1001] = {{0}};
    if (n < 0 || n > 100 || capacity < 0 || capacity > 1000) return -1;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w) {
                int value = profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                if (value > dp[i][w]) dp[i][w] = value;
            }
        }
    }
    return dp[n][capacity];
}

int main(void) {
    int choice;
    printf("1 Kadane's Algorithm\n2 Fractional Knapsack\n3 Job Scheduling\n4 0/1 Knapsack\nChoice: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        printf("Maximum subarray sum = %d\n", kadane(a, 9));
    } else if (choice == 2) {
        Item items[] = {{10, 60}, {20, 100}, {30, 120}};
        printf("Maximum profit = %.2f\n", fractionalKnapsack(items, 3, 50));
    } else if (choice == 3) {
        Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
        jobScheduling(jobs, 5);
    } else if (choice == 4) {
        int weight[] = {10, 20, 30}, profit[] = {60, 100, 120};
        printf("Maximum profit = %d\n", knapsack01(weight, profit, 3, 50));
    } else {
        printf("Invalid choice\n");
        return 1;
    }
    return 0;
}
