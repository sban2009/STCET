//Quicksort by sban2009
//Algorithm by mycodeschool
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int* a,int start,int end)
{
	int pivot=a[end];
	int q=start;
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[q]);
			q++;
		}
	}
	swap(&a[q],&a[end]);
	return q;
}
void quicksort(int* a,int start,int end)
{
	if(start<end)
	{
		int q=partition(a,start,end);	//partition position
		quicksort(a,start,q-1); 		//left subarray
		quicksort(a,q,end);     		//right subarray
	}
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
	quicksort(a,0,n-1);
	printf("sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
