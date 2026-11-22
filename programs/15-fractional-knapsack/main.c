/* Fractional Knapsack
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
typedef struct{double weight,profit,ratio;}Item;
int main(void){int n;Item a[100];double capacity,total=0;printf("Enter number of items: ");if(scanf("%d",&n)!=1||n<1||n>100)return 1;for(int i=0;i<n;i++){printf("Weight and profit of item %d: ",i+1);if(scanf("%lf%lf",&a[i].weight,&a[i].profit)!=2||a[i].weight<=0)return 1;a[i].ratio=a[i].profit/a[i].weight;}printf("Enter capacity: ");if(scanf("%lf",&capacity)!=1||capacity<0)return 1;for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[j].ratio>a[i].ratio){Item t=a[i];a[i]=a[j];a[j]=t;}for(int i=0;i<n&&capacity>0;i++){if(a[i].weight<=capacity){capacity-=a[i].weight;total+=a[i].profit;}else{total+=a[i].ratio*capacity;capacity=0;}}printf("Maximum profit = %.2f\n",total);return 0;}
