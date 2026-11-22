/* Connected Components using DFS - standalone C program */
#include <stdio.h>
#define MAX 100
int g[MAX][MAX],seen[MAX],n;
void dfs(int v){seen[v]=1;printf("%d ",v);for(int u=0;u<n;u++)if(g[v][u]&&!seen[u])dfs(u);}
int main(void){int m,count=0;printf("Enter vertices and undirected edges: ");if(scanf("%d%d",&n,&m)!=2||n<1||n>MAX||m<0)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=g[v][u]=1;}for(int v=0;v<n;v++)if(!seen[v]){printf("Component %d: ",++count);dfs(v);printf("\n");}printf("Total components = %d\n",count);return 0;}
