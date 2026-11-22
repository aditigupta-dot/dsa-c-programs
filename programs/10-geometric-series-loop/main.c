/* Geometric Series - Single Loop
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int main(void){double x,term=1,sum=0;int n;printf("Enter x and n for 1+x+x^2+...+x^n: ");if(scanf("%lf%d",&x,&n)!=2||n<0)return 1;for(int i=0;i<=n;i++){sum+=term;term*=x;}printf("Sum = %.6f\n",sum);return 0;}
