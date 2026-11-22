/* 4-Queens using Backtracking - standalone C program */
#include <stdio.h>
#define N 4
int board[N][N];
int safe(int r,int c){for(int i=0;i<r;i++)if(board[i][c])return 0;for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)if(board[i][j])return 0;for(int i=r-1,j=c+1;i>=0&&j<N;i--,j++)if(board[i][j])return 0;return 1;}
int solve(int r){if(r==N)return 1;for(int c=0;c<N;c++)if(safe(r,c)){board[r][c]=1;if(solve(r+1))return 1;board[r][c]=0;}return 0;}
int main(void){if(solve(0)){printf("One valid 4-Queens arrangement:\n");for(int i=0;i<N;i++){for(int j=0;j<N;j++)printf("%c ",board[i][j]?'Q':'.');printf("\n");}}else printf("No solution\n");return 0;}
