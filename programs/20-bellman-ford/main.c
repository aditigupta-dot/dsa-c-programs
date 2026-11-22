/* Bellman-Ford Algorithm
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#define MAX 100
#define EMAX 5000
#define INF 1000000000
typedef struct{int u,v,w;}Edge;
int main(void){int n,m,src,dist[MAX];Edge e[EMAX];printf("Enter vertices and directed edges: ");if(scanf("%d%d",&n,&m)!=2||n<1||n>MAX||m<0||m>EMAX)return 1;for(int i=0;i<m;i++)if(scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w)!=3||e[i].u<0||e[i].u>=n||e[i].v<0||e[i].v>=n)return 1;printf("Enter source: ");if(scanf("%d",&src)!=1||src<0||src>=n)return 1;for(int i=0;i<n;i++)dist[i]=INF;dist[src]=0;for(int i=1;i<n;i++){int changed=0;for(int j=0;j<m;j++)if(dist[e[j].u]!=INF&&dist[e[j].u]+e[j].w<dist[e[j].v]){dist[e[j].v]=dist[e[j].u]+e[j].w;changed=1;}if(!changed)break;}for(int j=0;j<m;j++)if(dist[e[j].u]!=INF&&dist[e[j].u]+e[j].w<dist[e[j].v]){printf("Reachable negative cycle exists.\n");return 0;}for(int i=0;i<n;i++)if(dist[i]==INF)printf("%d: INF\n",i);else printf("%d: %d\n",i,dist[i]);return 0;}
