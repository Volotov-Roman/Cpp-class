#include <stdio.h>

int main()
{
	int a[1000];
	int n;
	scanf("%i", &n);
	for (int i=0; i<n; i++)
		scanf("%i", &a[i]);
	int current = 0;
	for (int i=0; i<n; i++)
	{
		if (a[i]>=0)
		{
			a[current] = a[i];
			current++;
		}
	}
	for (int i=0; i<current; i++)
		printf("%i ", a[i]);
}