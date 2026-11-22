/* 0/1 Knapsack - standalone C program */
#include <stdio.h>
#define N 100
#define W 1000
int main(void){int n,cap,wt[N],p[N],dp[N+1][W+1]={{0}};printf("Enter n and capacity: ");if(scanf("%d%d",&n,&cap)!=2||n<1||n>N||cap<0||cap>W)return 1;for(int i=0;i<n;i++)if(scanf("%d%d",&wt[i],&p[i])!=2||wt[i]<0)return 1;for(int i=1;i<=n;i++)for(int c=0;c<=cap;c++){dp[i][c]=dp[i-1][c];if(wt[i-1]<=c&&p[i-1]+dp[i-1][c-wt[i-1]]>dp[i][c])dp[i][c]=p[i-1]+dp[i-1][c-wt[i-1]];}printf("Maximum profit = %d\n",dp[n][cap]);return 0;}
