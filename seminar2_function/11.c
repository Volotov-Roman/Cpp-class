	#include <stdio.h>
	#define MAX 50
	void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				float sum = 0;
				for (int k = 0; k<n; k++)
					sum += A[i][k]*B[k][j];
				C[i][j] = sum;
			}
		}
	}
	int main()
	{
		int n;
		float A[MAX][MAX];
		float B[MAX][MAX];
		float C[MAX][MAX];
		scanf("%i", &n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%f", &A[i][j]);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%f", &B[i][j]);
		multiply(A, B, C, n);
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
				printf("%g ", C[i][j]);
			printf("\n");
		}
	}