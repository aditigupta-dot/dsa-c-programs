/*
 * GEOMETRIC SERIES AND TOWER OF HANOI
 * Compile: gcc recursion_and_series.c -o recursion_and_series
 */
#include <stdio.h>
#include <math.h>

#define MAX_DISKS 20

/* 9A. Geometric series using formula: S = (x^(n+1)-1)/(x-1). */
double geometricFormula(double x, int n) {
    if (x == 1.0) return (double)n + 1.0;
    return (pow(x, n + 1) - 1.0) / (x - 1.0);
}

/* 9B. Geometric series using one loop. */
double geometricLoop(double x, int n) {
    double sum = 0.0, term = 1.0;
    for (int i = 0; i <= n; i++) {
        sum += term;
        term *= x;
    }
    return sum;
}

/* 9C. Geometric series using nested loops. */
double geometricNestedLoop(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double term = 1.0;
        for (int j = 1; j <= i; j++) term *= x;
        sum += term;
    }
    return sum;
}

/* 10. RECURSIVE TOWER OF HANOI. */
void hanoiRecursive(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    hanoiRecursive(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoiRecursive(n - 1, auxiliary, source, destination);
}

/* 11. ITERATIVE TOWER OF HANOI. */
typedef struct {
    int disks[MAX_DISKS + 1];
    int top;
    char name;
} Peg;

void push(Peg *p, int disk) { p->disks[++p->top] = disk; }
int pop(Peg *p) { return p->disks[p->top--]; }

void legalMove(Peg *a, Peg *b) {
    int disk;
    if (a->top == -1) {
        disk = pop(b); push(a, disk);
        printf("Move disk %d from %c to %c\n", disk, b->name, a->name);
    } else if (b->top == -1) {
        disk = pop(a); push(b, disk);
        printf("Move disk %d from %c to %c\n", disk, a->name, b->name);
    } else if (a->disks[a->top] < b->disks[b->top]) {
        disk = pop(a); push(b, disk);
        printf("Move disk %d from %c to %c\n", disk, a->name, b->name);
    } else {
        disk = pop(b); push(a, disk);
        printf("Move disk %d from %c to %c\n", disk, b->name, a->name);
    }
}

void hanoiIterative(int n) {
    Peg source = {.top = -1, .name = 'S'};
    Peg auxiliary = {.top = -1, .name = 'A'};
    Peg destination = {.top = -1, .name = 'D'};
    for (int i = n; i >= 1; i--) push(&source, i);

    Peg *aux = &auxiliary, *dest = &destination;
    if (n % 2 == 0) { Peg *temp = aux; aux = dest; dest = temp; }

    unsigned long long moves = (1ULL << n) - 1;
    for (unsigned long long i = 1; i <= moves; i++) {
        if (i % 3 == 1) legalMove(&source, dest);
        else if (i % 3 == 2) legalMove(&source, aux);
        else legalMove(aux, dest);
    }
}

int main(void) {
    int choice, n;
    double x;
    printf("1 Geometric Series - Formula\n2 Geometric Series - Single Loop\n");
    printf("3 Geometric Series - Nested Loop\n4 Tower of Hanoi - Recursive\n");
    printf("5 Tower of Hanoi - Iterative\nChoice: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice >= 1 && choice <= 3) {
        printf("Enter x and n for 1 + x + x^2 + ... + x^n: ");
        if (scanf("%lf%d", &x, &n) != 2 || n < 0) return 1;
        double sum;
        if (choice == 1) sum = geometricFormula(x, n);
        else if (choice == 2) sum = geometricLoop(x, n);
        else sum = geometricNestedLoop(x, n);
        printf("Sum = %.6f\n", sum);
    } else if (choice == 4 || choice == 5) {
        printf("Enter number of disks (1-%d): ", MAX_DISKS);
        if (scanf("%d", &n) != 1 || n < 1 || n > MAX_DISKS) return 1;
        if (choice == 4) hanoiRecursive(n, 'S', 'A', 'D');
        else hanoiIterative(n);
    } else {
        printf("Invalid choice\n");
        return 1;
    }
    return 0;
}
