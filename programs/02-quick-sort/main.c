/* Quick Sort
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int partition(int a[],int low,int high){int pivot=a[high],i=low-1;for(int j=low;j<high;j++)if(a[j]<=pivot){int t=a[++i];a[i]=a[j];a[j]=t;}int t=a[i+1];a[i+1]=a[high];a[high]=t;return i+1;}
void quickSort(int a[],int low,int high){if(low<high){int p=partition(a,low,high);quickSort(a,low,p-1);quickSort(a,p+1,high);}}
int main(void){int n,a[1000];printf("Enter n: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++)scanf("%d",&a[i]);quickSort(a,0,n-1);for(int i=0;i<n;i++)printf("%d ",a[i]);return 0;}
