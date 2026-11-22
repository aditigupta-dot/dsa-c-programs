/* Prim's Minimum Spanning Tree
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#define MAX 100
#define INF 1000000000
int main(void){int n,g[MAX][MAX],key[MAX],parent[MAX],used[MAX]={0};printf("Enter vertices: ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;printf("Enter adjacency matrix (0 means no edge; use positive weights):\n");for(int i=0;i<n;i++)for(int j=0;j<n;j++){scanf("%d",&g[i][j]);if(i!=j&&g[i][j]==0)g[i][j]=INF;}for(int i=0;i<n;i++){key[i]=INF;parent[i]=-1;}key[0]=0;for(int c=0;c<n;c++){int u=-1;for(int v=0;v<n;v++)if(!used[v]&&(u==-1||key[v]<key[u]))u=v;if(u==-1||key[u]==INF)break;used[u]=1;for(int v=0;v<n;v++)if(!used[v]&&g[u][v]<key[v]){key[v]=g[u][v];parent[v]=u;}}int total=0,edges=0;for(int v=1;v<n;v++)if(parent[v]!=-1){printf("%d - %d : %d\n",parent[v],v,g[parent[v]][v]);total+=g[parent[v]][v];edges++;}if(edges!=n-1)printf("Graph disconnected; no MST.\n");else printf("MST weight = %d\n",total);return 0;}
