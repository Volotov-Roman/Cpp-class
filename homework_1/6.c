#include <stdio.h>

int main()
{
	int n;
	int m;
	scanf("%i", &n);
	scanf("%i", &m);
	int sum = 0;
	for (int i = 1; i<=m; i++)
		for (int j=1; j<=n; j++)
			{
				if ((i+j)%2==0)
					sum += i*j;
				else
					sum -= i*j;
			}
	printf("%i\n", sum);
}