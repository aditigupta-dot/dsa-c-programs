/* Dijkstra's Shortest Path
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#define MAX 100
#define INF 1000000000
int main(void){int n,g[MAX][MAX],dist[MAX],done[MAX]={0},src;printf("Enter vertices: ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;printf("Enter adjacency matrix (0 means no edge; weights non-negative):\n");for(int i=0;i<n;i++)for(int j=0;j<n;j++){scanf("%d",&g[i][j]);if(i!=j&&g[i][j]==0)g[i][j]=INF;}printf("Enter source: ");if(scanf("%d",&src)!=1||src<0||src>=n)return 1;for(int i=0;i<n;i++)dist[i]=INF;dist[src]=0;for(int c=0;c<n;c++){int u=-1;for(int i=0;i<n;i++)if(!done[i]&&(u==-1||dist[i]<dist[u]))u=i;if(u==-1||dist[u]==INF)break;done[u]=1;for(int v=0;v<n;v++)if(!done[v]&&g[u][v]!=INF&&g[u][v]>=0&&dist[u]+g[u][v]<dist[v])dist[v]=dist[u]+g[u][v];}for(int i=0;i<n;i++)if(dist[i]==INF)printf("%d: INF\n",i);else printf("%d: %d\n",i,dist[i]);return 0;}
