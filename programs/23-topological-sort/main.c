/* Topological Sort - standalone C program */
#include <stdio.h>
#define MAX 100
int g[MAX][MAX],state[MAX],stack[MAX],top,n;
int dfs(int v){state[v]=1;for(int u=0;u<n;u++)if(g[v][u]){if(state[u]==1)return 0;if(state[u]==0&&!dfs(u))return 0;}state[v]=2;stack[top++]=v;return 1;}
int main(void){int m;printf("Enter vertices and directed edges: ");if(scanf("%d%d",&n,&m)!=2||n<1||n>MAX||m<0)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=1;}for(int i=0;i<n;i++)if(!state[i]&&!dfs(i)){printf("Cycle: topological order does not exist.\n");return 0;}printf("Topological order: ");while(top)printf("%d ",stack[--top]);return 0;}
