#include <stdio.h>

int main()
{
	int n;
	int m;
	int a[1000];
	scanf("%i", &n);
	scanf("%i", &m);
	for (int i = 0; i<n*m; i++)
		scanf("%i", &a[i]);
	for (int i = 0; i<m; i++)
	{
		int sum = 0;
		for (int j=0; j<n; j++)
			sum += a[i+m*j];
		printf("%i ", sum);
	}
}