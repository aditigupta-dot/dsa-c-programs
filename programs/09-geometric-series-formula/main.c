/* Geometric Series - Formula
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#include <math.h>
int main(void){double x,sum;int n;printf("Enter x and n for 1+x+x^2+...+x^n: ");if(scanf("%lf%d",&x,&n)!=2||n<0)return 1;if(x==1.0)sum=n+1.0;else sum=(pow(x,n+1)-1.0)/(x-1.0);printf("Sum = %.6f\n",sum);return 0;}
