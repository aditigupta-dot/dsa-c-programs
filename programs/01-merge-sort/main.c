/* Merge Sort
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
void merge(int a[],int l,int m,int r){int n1=m-l+1,n2=r-m,L[1000],R[1000];for(int i=0;i<n1;i++)L[i]=a[l+i];for(int j=0;j<n2;j++)R[j]=a[m+1+j];int i=0,j=0,k=l;while(i<n1&&j<n2)a[k++]=(L[i]<=R[j])?L[i++]:R[j++];while(i<n1)a[k++]=L[i++];while(j<n2)a[k++]=R[j++];}
void mergeSort(int a[],int l,int r){if(l<r){int m=l+(r-l)/2;mergeSort(a,l,m);mergeSort(a,m+1,r);merge(a,l,m,r);}}
int main(void){int n,a[1000];printf("Enter number of elements: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++)scanf("%d",&a[i]);mergeSort(a,0,n-1);printf("Sorted: ");for(int i=0;i<n;i++)printf("%d ",a[i]);return 0;}
