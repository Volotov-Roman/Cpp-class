#include <stdio.h>
int main()
{
	int n;
	scanf("%i", &n);
	int i = 1;
	int sum;
	while (i <= n)
	{
		sum += i;
		i += 1;
	}
	printf("%i\n", sum);
}