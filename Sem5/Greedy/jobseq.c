#include<stdio.h>
#include<stdlib.h>
int max=0,cur;
struct Job
{
	int id,p,d; //deadline
};
void swap(struct Job *j1, struct Job *j2)
{
    struct Job temp=*j1;
    *j1=*j2;
    *j2=temp;
}
int space(struct Job j,int* S)
{
	if(j.d<=max)
		for(int i=j.d;i>=1;i--)
			if(S[i]==0)
			{
				cur=i;
				S[0]++;
				return 1;
			}
	return 0;
}
main()
{
	int n,profit=0;
	printf("enter no. of Jobs: ");
	scanf("%d",&n);
	struct Job J[n];
	int* S=(int*)calloc(max+1,sizeof(int));
	printf("enter profit and deadline for each Job:\n");
	for(int i=0;i<n;i++) //input
	{
		J[i].id=i+1;
		printf("p%d: ",J[i].id);
		scanf("%d",&J[i].p);
		printf("d%d: ",J[i].id);
		scanf("%d",&J[i].d);
		if(J[i].d>max)
			max=J[i].d;
		printf("\n");
	}
    for(int i=0;i<n;i++) //bubble sort according to profit
        for(int j=0;j<n-i-1;j++)
        {
            if(J[j+1].p>J[j].p)
                swap(&J[j+1],&J[j]);
        }
	printf("Job\tProfit\tDeadline\n");
	for(int i=0;i<n;i++) //print sorted
		printf("%d\t%d\t%d\n",J[i].id,J[i].p,J[i].d);
	for(int i=0;i<n;i++)    //job sequencing
	{
		if(space(J[i],S))
		{
			S[cur]=J[i].id;
			profit+=J[i].p;
		}
	}
	printf("Jobs selected: ");
	for(int i=1;i<=S[0];i++)
		printf("\t%d",S[i]);
	printf("\n%d jobs selected with profit = %d",S[0],profit);
}
