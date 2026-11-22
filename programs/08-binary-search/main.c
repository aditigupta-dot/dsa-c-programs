/* Binary Search
 * Standalone C program. Compile with: gcc main.c -o program
 */
#include <stdio.h>
int main(void){int n,a[1000],key,low=0,high,mid,pos=-1;printf("Enter n and sorted array: ");if(scanf("%d",&n)!=1||n<1||n>1000)return 1;for(int i=0;i<n;i++)scanf("%d",&a[i]);printf("Enter key: ");scanf("%d",&key);high=n-1;while(low<=high){mid=low+(high-low)/2;if(a[mid]==key){pos=mid;break;}if(a[mid]<key)low=mid+1;else high=mid-1;}if(pos<0)printf("Not found");else printf("Found at index %d",pos);return 0;}
