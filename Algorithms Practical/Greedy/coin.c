#include<stdio.h>
#include<stdlib.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
main()
{
	int amt,*val,n,*res,count=0,sum=0;
	printf("Enter amount: ");
	scanf("%d",&amt);
	printf("Enter no. of types of currency: ");
	scanf("%d",&n);
	val=(int*)calloc(n,sizeof(int));
	res=(int*)calloc(n,sizeof(int));
	printf("Enter currency values: ");
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
	for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(val[j+1]>val[j])
				swap(&val[j+1],&val[j]);
	for(int i=0;i<n;i++)
	{
		while(amt>=val[i])
		{
			amt-=val[i];
			count++;
		}
		res[i]=count;
		sum+=res[i];
		count=0;
	}
	for(int i=0;i<n;i++)
		printf("\nRs. %d = %d coins",val[i],res[i]);
	printf("\ntotal = %d coins",sum);
}
