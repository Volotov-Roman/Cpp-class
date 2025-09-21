#include <stdio.h>
void print_binary(int n)
{
	if (n<2)
	{
		printf("%i", n);
		return;
	}
	else
	{
		print_binary(n/2);
		printf("%i", n%2);
	}
}

int main()
{
	int a;
	scanf("%i", &a);
	print_binary(a);
}