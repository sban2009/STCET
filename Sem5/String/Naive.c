#include<stdio.h>
#include<string.h>
main()
{
	char T[255],P[255],nT,nP,found=0;
	printf("enter text: ");
	scanf("%s",&T);
	nT=strlen(T);
	printf("enter pattern: ");
	scanf("%s",&P);
	nP=strlen(P);
	//naive
	for(int i=0;i<=nT-nP;i++)
	{
		for(int j=0;j<nP;j++)
			if(T[i+j]!=P[j])
				break;
		if(j==nP)
		{
			printf("found at shift %d\n",i);
			found=1;
		}
	}
	if(!found)
		printf("not found);
}
