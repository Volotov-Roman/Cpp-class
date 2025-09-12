#include <stdio.h>

int main()
{
	int a[1000];
	int b[1000];
	int c[1000];
	int n;
	scanf("%i", &n);
	for (int i=0; i<n*n; i++)
		scanf("%i", &a[i]);
	for (int i=0; i<n*n; i++)
		scanf("%i", &b[i]);

	for (int i=0; i<n*n; i++)
	{
		int entry = 0;
		for (int j = 0; j<n; j++)
		{
			entry += a[n*(i/n)+j]*b[i%n+n*j];
		}
		c[i] = entry;
	}

	for (int i = 0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			printf("%3i ", c[n*i+j]);
		printf("\n");
	}
}