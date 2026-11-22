/* Job Scheduling with Deadlines
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
typedef struct{int id,deadline,profit;}Job;
int main(void){int n;Job jobs[100];printf("Enter number of jobs: ");if(scanf("%d",&n)!=1||n<1||n>100)return 1;for(int i=0;i<n;i++){jobs[i].id=i+1;printf("Deadline and profit for job %d: ",i+1);if(scanf("%d%d",&jobs[i].deadline,&jobs[i].profit)!=2||jobs[i].deadline<0)return 1;}for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(jobs[j].profit>jobs[i].profit){Job t=jobs[i];jobs[i]=jobs[j];jobs[j]=t;}int slots[101]={0},maxD=0,total=0;for(int i=0;i<n;i++)if(jobs[i].deadline>maxD)maxD=jobs[i].deadline;if(maxD>n)maxD=n;for(int i=0;i<n;i++)for(int t=(jobs[i].deadline<maxD?jobs[i].deadline:maxD);t>=1;t--)if(!slots[t]){slots[t]=jobs[i].id;total+=jobs[i].profit;break;}printf("Scheduled jobs: ");for(int t=1;t<=maxD;t++)if(slots[t])printf("J%d ",slots[t]);printf("\nMaximum profit = %d\n",total);return 0;}
