	#include <stdio.h>
	#define MAX 50
	void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
				A[i][j] = B[i][j];
		}
	}
	int main()
	{
		int n;
		float A[MAX][MAX];
		float B[MAX][MAX];
		scanf("%i", &n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%f", &A[i][j]);
		assign(B, A, n);
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
				printf("%g ", B[i][j]);
			printf("\n");
		}
	}