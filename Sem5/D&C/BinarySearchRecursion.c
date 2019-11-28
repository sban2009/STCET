#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int binsearch(int* a, int key, int start, int end)
{
    int mid=(start+end)/2;
    if(a[mid]==key)
        return true;
    if(start==end)
        return false;
    if(a[mid]>key)
        binsearch(a,key,start,mid-1);
    else
        binsearch(a,key,mid+1,end);
}
main()
{
    int n,key;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter key: ");
    scanf("%d",&key);
    if(binsearch(a,key,0,n))
		printf("Found");
	else
		printf("Not found");
    
}
