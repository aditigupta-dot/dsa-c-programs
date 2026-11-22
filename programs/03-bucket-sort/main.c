/* Bucket Sort
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
void insertion(double a[],int n){for(int i=1;i<n;i++){double key=a[i];int j=i-1;while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}a[j+1]=key;}}
int main(void){int n;double a[1000],b[1000][1000];int count[1000]={0};printf("Enter n (values must be in [0,1)): ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++){if(scanf("%lf",&a[i])!=1||a[i]<0||a[i]>=1){printf("Invalid value.\n");return 1;}int k=(int)(n*a[i]);b[k][count[k]++]=a[i];}int p=0;for(int i=0;i<n;i++){insertion(b[i],count[i]);for(int j=0;j<count[i];j++)a[p++]=b[i][j];}for(int i=0;i<n;i++)printf("%.3f ",a[i]);return 0;}
