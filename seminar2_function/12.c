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
void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k)
{
	float B[MAX][MAX];
	if (k == 1)
		assign(C, A, n);
	else if (k==2)
		multiply(A, A, C, n);
	else if (k%2 == 0)
	{
		power(A, C, n, k/2);
		assign(B, C, n);
		multiply(B, B, C, n);
	}
	else
	{
		power(A, C, n, k-1);
		assign(B, C, n);
		multiply(A, B, C, n);
	}
}
int main()
{
	int n;
	int k;
	float A[MAX][MAX];
	float C[MAX][MAX];
	scanf("%i", &n);
	scanf("%i", &k);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%f", &A[i][j]);
	power(A, C, n, k);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			printf("%g ", C[i][j]);
		printf("\n");
	}
}