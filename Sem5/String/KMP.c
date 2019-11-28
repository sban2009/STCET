#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to implement KMP algorithm
//next=prefix table
void KMP(const char* T, const char* P, int nT, int nP)
{
	// Base Case 1: P is NULL or empty
	if (*P == '\0' || nP == 0)
		printf("Pattern occurs with shift 0");

	// Base Case 2: T is NULL or T's length is less than that of P's
	if (*T == '\0' || nP > nT)
		printf("Pattern not found");

	// next[i] stores the index of next best partial match
	int next[nP + 1];

	for (int i = 0; i < nP + 1; i++)
		next[i] = 0;

	for (int i = 1; i < nP; i++)
	{
		int j = next[i + 1];

		while (j > 0 && P[j] != P[i])
			j = next[j];

		if (j > 0 || P[j] == P[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < nT; i++)
	{
		if (*(T + i) == *(P + j))
		{
			if (++j == nP)
				printf("Pattern occurs with shift %d\n", i - j + 1);
		}
		else if (j > 0) {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}
}

// Program to implement KMP Algorithm in C
int main(void)
{
	char T[255],P[255];
	printf("enter text: ");
	scanf("%s",&T);
	printf("enter pattern: ");
	scanf("%s",&P);
	int nT = strlen(T);
	int nP = strlen(P);

	KMP(T, P, nT, nP);

	return 0;
}
