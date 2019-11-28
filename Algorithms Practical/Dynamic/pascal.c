#include<stdio.h>
void binomialCoeff(int n)
{
    int C[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
			printf("%d",C[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
	printf("enter rows of triangle (n): ");
	scanf("%d",&n);
	binomialCoeff(n);
    return 0;
}
