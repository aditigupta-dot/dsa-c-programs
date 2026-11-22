/* Undirected Cycle Detection - standalone C program */
#include <stdio.h>
#define MAX 100
int g[MAX][MAX],seen[MAX],n;
int dfs(int v,int parent){seen[v]=1;for(int u=0;u<n;u++)if(g[v][u]){if(!seen[u]){if(dfs(u,v))return 1;}else if(u!=parent)return 1;}return 0;}
int main(void){int m,cycle=0;printf("Enter vertices and undirected edges: ");if(scanf("%d%d",&n,&m)!=2||n<1||n>MAX||m<0)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=g[v][u]=1;}for(int i=0;i<n;i++)if(!seen[i]&&dfs(i,-1)){cycle=1;break;}printf(cycle?"Cycle exists\n":"No cycle\n");return 0;}
