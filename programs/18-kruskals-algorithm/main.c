/* Kruskal's Minimum Spanning Tree
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define EMAX 5000
typedef struct{int u,v,w;}Edge;
int parent[MAX],rankSet[MAX];
int find(int x){if(parent[x]!=x)parent[x]=find(parent[x]);return parent[x];}
void unite(int a,int b){a=find(a);b=find(b);if(a==b)return;if(rankSet[a]<rankSet[b])parent[a]=b;else if(rankSet[a]>rankSet[b])parent[b]=a;else{parent[b]=a;rankSet[a]++;}}
int cmp(const void*a,const void*b){return ((Edge*)a)->w-((Edge*)b)->w;}
int main(void){int n,m,total=0,chosen=0;Edge e[EMAX];printf("Enter vertices and edges: ");if(scanf("%d%d",&n,&m)!=2||n<1||n>MAX||m<0||m>EMAX)return 1;for(int i=0;i<m;i++)if(scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w)!=3||e[i].u<0||e[i].u>=n||e[i].v<0||e[i].v>=n)return 1;for(int i=0;i<n;i++)parent[i]=i,rankSet[i]=0;qsort(e,m,sizeof(Edge),cmp);for(int i=0;i<m&&chosen<n-1;i++)if(find(e[i].u)!=find(e[i].v)){unite(e[i].u,e[i].v);printf("%d - %d : %d\n",e[i].u,e[i].v,e[i].w);total+=e[i].w;chosen++;}if(chosen<n-1)printf("Graph disconnected; minimum spanning forest shown.\n");printf("Total weight = %d\n",total);return 0;}
