/* Floyd-Warshall Algorithm - standalone C program */
#include <stdio.h>
#define MAX 100
#define INF 1000000000
int main(void){int n,d[MAX][MAX];printf("Enter vertices: ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;printf("Enter adjacency matrix (0 means no edge; diagonal 0):\n");for(int i=0;i<n;i++)for(int j=0;j<n;j++){scanf("%d",&d[i][j]);if(i!=j&&d[i][j]==0)d[i][j]=INF;}for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(d[i][k]!=INF&&d[k][j]!=INF&&d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];for(int i=0;i<n;i++){for(int j=0;j<n;j++)if(d[i][j]==INF)printf("INF ");else printf("%d ",d[i][j]);printf("\n");}return 0;}
