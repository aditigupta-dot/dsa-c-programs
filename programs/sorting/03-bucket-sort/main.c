/* Bucket Sort - standalone C program; accepts values in [0,1). */
#include <stdio.h>
#include <stdlib.h>
void insertion(double a[],int n){for(int i=1;i<n;i++){double key=a[i];int j=i-1;while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}a[j+1]=key;}}
int main(void){
 int n,count[1000]={0};double a[1000],*bucket[1000];
 printf("Enter n (values must be in [0,1)): ");
 if(scanf("%d",&n)!=1||n<1||n>1000)return 1;
 for(int i=0;i<n;i++)if(scanf("%lf",&a[i])!=1||a[i]<0||a[i]>=1){printf("Invalid value.\n");return 1;}
 for(int i=0;i<n;i++){bucket[i]=malloc((size_t)n*sizeof(double));if(!bucket[i]){for(int j=0;j<i;j++)free(bucket[j]);return 1;}}
 for(int i=0;i<n;i++){int k=(int)(n*a[i]);bucket[k][count[k]++]=a[i];}
 int p=0;for(int i=0;i<n;i++){insertion(bucket[i],count[i]);for(int j=0;j<count[i];j++)a[p++]=bucket[i][j];free(bucket[i]);}
 for(int i=0;i<n;i++)printf("%.3f ",a[i]);printf("\n");return 0;
}