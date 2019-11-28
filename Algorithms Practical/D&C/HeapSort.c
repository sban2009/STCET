/*Heap Sort by sban2009
Algorithm by Wikipedia*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int iParent(int i)
{
	return ((i-1)/2);
}

int iLeftChild(int i)
{
	return (2*i + 1);
}

int iRightChild(int i)
{
	return (2*i + 2);
}

void percolateDown(int* a,int start,int end)
{
	int root = start;
    while(iLeftChild(root)<=end)
    {
        int child = iLeftChild(root);
        int selected=root;
        if (a[selected] < a[child])
            selected = child;
        if (child+1 <= end && a[selected] < a[child+1])
            selected = child + 1;
        if(selected == root)
            return;
        else
        {
			swap(&a[root], &a[selected]);
            root=selected;
		}
	}
}

void heapify(int *a,int n)
{
	int start = iParent(n-1);
    while(start >= 0)
    {
        percolateDown(a, start, n - 1);
        start--;
	}
}

void heapsort(int *a,int n)
{
	heapify(a, n);
	int end=n-1;
    while(end > 0)
    {
        swap(&a[end], &a[0]);
        end--;
        percolateDown(a, 0, end);
	}
}

main()
{
    int n;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
	heapsort(a,n);
	printf("sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
