/* Radix Sort
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
void countSort(int a[],int n,long long exp){int out[1000],count[10]={0};for(int i=0;i<n;i++)count[(a[i]/exp)%10]++;for(int i=1;i<10;i++)count[i]+=count[i-1];for(int i=n-1;i>=0;i--){int d=(int)((a[i]/exp)%10);out[--count[d]]=a[i];}for(int i=0;i<n;i++)a[i]=out[i];}
int main(void){int n,a[1000],max=0;printf("Enter n and non-negative integers: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++){if(scanf("%d",&a[i])!=1||a[i]<0)return 1;if(a[i]>max)max=a[i];}for(long long exp=1;max/exp>0;exp*=10){countSort(a,n,exp);if(exp>max/10)break;}for(int i=0;i<n;i++)printf("%d ",a[i]);return 0;}
