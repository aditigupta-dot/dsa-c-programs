/* Geometric Series - Nested Loop
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int main(void){double x,sum=0;int n;printf("Enter x and n for 1+x+x^2+...+x^n: ");if(scanf("%lf%d",&x,&n)!=2||n<0)return 1;for(int i=0;i<=n;i++){double term=1;for(int j=1;j<=i;j++)term*=x;sum+=term;}printf("Sum = %.6f\n",sum);return 0;}
