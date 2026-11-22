/* Kadane's Algorithm
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int main(void){int n,a[1000];printf("Enter n: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++)scanf("%d",&a[i]);int current=a[0],best=a[0];for(int i=1;i<n;i++){current=(a[i]>current+a[i])?a[i]:current+a[i];if(current>best)best=current;}printf("Maximum subarray sum = %d\n",best);return 0;}
