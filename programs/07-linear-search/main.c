/* Linear Search
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int main(void){int n,a[1000],key,pos=-1;printf("Enter n: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++)scanf("%d",&a[i]);printf("Enter key: ");scanf("%d",&key);for(int i=0;i<n;i++)if(a[i]==key){pos=i;break;}if(pos==-1)printf("Not found");else printf("Found at index %d",pos);return 0;}
