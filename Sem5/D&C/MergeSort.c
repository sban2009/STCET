//Merge Sort by sban2009
//Algorithm by mycodeschool
#include<stdio.h>
#include<stdlib.h>
int merge(int* L,int* R,int* A,int nL,int nR)
{
	int i=0,j=0,k=0;
	while(i<nL && j<nR)
		if(L[i]<=R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
			
	while(i<nL)
		A[k++]=L[i++];
	while(j<nR)
		A[k++]=R[j++];
}
void mergesort(int* a,int n)
{
	if(n<2)
		return;
	int mid=n/2;    //middle
	int nL=mid,nR=n-mid;    //size of left and right subproblems
	int *L=(int*)malloc(sizeof(int)*nL);
	int *R=(int*)malloc(sizeof(int)*nR);
	for(int i=0;i<mid;i++)
		L[i]=a[i];
	for(int i=mid;i<n;i++)
		R[i-mid]=a[i];
	mergesort(L,nL);
	mergesort(R,nR);
	merge(L,R,a,nL,nR);
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
	mergesort(a,n);
	printf("sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
