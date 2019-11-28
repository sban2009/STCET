#include<stdio.h>
#include<stdlib.h>
struct items
{
	int id;
	float p,w,pwr;
};
void swap(struct items *i, struct items *j)
{
    struct items temp=*i;
    *i=*j;
    *j=temp;
}
main()
{
	int n,M,W=0;
	float profit;
	printf("enter knapsack capacity: ");
	scanf("%d",&M);
	printf("no. of items: ");
	scanf("%d",&n);
	struct items item[n];
	float f[n];
	printf("enter profit and weight of each item: ");
	for(int i=0;i<n;i++)
	{
		item[i].id=i+1;
		printf("\nitem %d:\n",item[i].id);
		printf("p%d= ",i+1);
		scanf("%f",&item[i].p);
		printf("w%d= ",i+1);
		scanf("%f",&item[i].w);
		item[i].pwr=item[i].p/item[i].w;
	}
	for(int i=0;i<n;i++) //sorting by pwr
		for(int j=0;j<n-i-1;j++)
			if(item[j+1].pwr>item[j].pwr)
				swap(&item[j+1],&item[j]);
	for(int i=0;i<n;i++)
	{
		if(W+item[i].w<=M)
		{
			f[i]=1;
			profit+=item[i].p;
			W+=item[i].w;
		}
		else
		{
			f[i]=(M-W)/item[i].w;
			profit+=f[i]*item[i].p;
			W=M;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%.2f of item %d\n",f[i],item[i].id);
	}
	printf("profit = %.2f",profit);
}
