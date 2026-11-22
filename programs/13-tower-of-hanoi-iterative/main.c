/* Tower of Hanoi - Iterative
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
#define MAX 20
typedef struct{int disk[MAX+1],top;char name;}Peg;
void push(Peg*p,int d){p->disk[++p->top]=d;}int pop(Peg*p){return p->disk[p->top--];}
void moveLegal(Peg*a,Peg*b){int d;if(a->top==-1){d=pop(b);push(a,d);printf("Move disk %d from %c to %c\n",d,b->name,a->name);}else if(b->top==-1){d=pop(a);push(b,d);printf("Move disk %d from %c to %c\n",d,a->name,b->name);}else if(a->disk[a->top]<b->disk[b->top]){d=pop(a);push(b,d);printf("Move disk %d from %c to %c\n",d,a->name,b->name);}else{d=pop(b);push(a,d);printf("Move disk %d from %c to %c\n",d,b->name,a->name);}}
int main(void){int n;Peg s={{0},-1,'A'},a={{0},-1,'B'},d={{0},-1,'C'};printf("Enter number of disks (1-20): ");if(scanf("%d",&n)!=1||n<1||n>20)return 1;for(int i=n;i>=1;i--)push(&s,i);unsigned long long total=(1ULL<<n)-1;for(unsigned long long i=1;i<=total;i++){if(n%2){if(i%3==1)moveLegal(&s,&d);else if(i%3==2)moveLegal(&s,&a);else moveLegal(&a,&d);}else{if(i%3==1)moveLegal(&s,&a);else if(i%3==2)moveLegal(&s,&d);else moveLegal(&a,&d);}}return 0;}
