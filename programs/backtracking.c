/*
 * 24. N-QUEENS USING BACKTRACKING
 * For the lab question, enter N = 4.
 * Compile: gcc backtracking.c -o backtracking
 */
#include <stdio.h>
#define MAX 20

int board[MAX][MAX];

int isSafe(int row, int col, int n) {
    /* Check the same column in previous rows. */
    for (int i = 0; i < row; i++)
        if (board[i][col]) return 0;

    /* Check upper-left diagonal. */
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    /* Check upper-right diagonal. */
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return 0;

    return 1;
}

int solveNQueens(int row, int n) {
    if (row == n) return 1;
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(row + 1, n)) return 1;
            board[row][col] = 0; /* Backtrack. */
        }
    }
    return 0;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
}

int main(void) {
    int n;
    printf("Enter N (enter 4 for the 4-Queens problem): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Enter N between 1 and %d.\n", MAX);
        return 1;
    }
    if (solveNQueens(0, n)) {
        printf("One valid arrangement:\n");
        printBoard(n);
    } else {
        printf("No solution exists for N = %d.\n", n);
    }
    return 0;
}
