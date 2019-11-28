//MaxMin Problem by sban2009
//Algorithm by tutorialspoint.com
#include<stdio.h>
#include<stdlib.h>
int *a;
struct MM
{
	int max,min;
}m;
struct MM MaxMin(int i,int j)
{
	if(i==j)
	{
		m.max=a[i],m.min=a[i];
	}
	else if(i==j-1)
	{
		if(a[i]>a[j])
			m.max=a[i],m.min=a[j];
		else
			m.max=a[j],m.min=a[i];
	}
	else
	{
		int mid=(i+j)/2;
		struct MM m1;
		m=MaxMin(i,mid);
		m1=MaxMin(mid+1,j);
		if(m.max<m1.max)
			m.max=m1.max;
		if(m.min>m1.min)
			m.min=m1.min;
	}
	return m;
}
main()
{
    int n,key;
    printf("enter number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
	struct MM m=MaxMin(0,n-1);
	printf("Max, Min: ");
    printf("\t%d, %d",m.max,m.min);
}
