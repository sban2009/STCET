#include<stdio.h>
#include<limits.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
void print_bracket(int i,int j,int s[][j+1])
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		print_bracket(i,s[i][j],s);
		print_bracket(s[i][j]+1,j,s);
		printf(")");
	}
}
int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n],s[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix

    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value

            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                    s[i][j]=k;
                }
            }
        }
    }
	printf("Optimal parenthesis: ");
	print_bracket(1,n-1,s);
    return m[1][n-1];   //returning the final answer which is M[1][n]

}

int main()
{
    int n,i;
    printf("Enter number of matrices\n");
    scanf("%d",&n);

    n++;

    int p[n];

    printf("Enter dimensions \n");

    for(i=0;i<n;i++)
    {
        printf("Enter p%d :: ",i);
        scanf("%d",&p[i]);
    }

    int size = sizeof(p)/sizeof(p[0]);

    printf("\nMinimum number of multiplications is %d ", MatrixChainMultiplication(p, size));
}
