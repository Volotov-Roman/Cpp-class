#include <stdio.h>
#include <limits.h>
int main()
{
	int n;
	scanf("%i", &n);
	int count = 1;
	int max = INT_MIN;
	while (n>1)
	{
		printf("%i ", n);
		if (n>max)
			max = n;
		count++;
		if (n%2==0)
			n /= 2;
		else
			n = 3*n+1;
	}
	printf("1\n");
	printf("Length = %i, Max = %i", count, max);
}