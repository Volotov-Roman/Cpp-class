#include <stdio.h>
int sum_of_digits(int n)
{
	int sum = 0;
	while (n>0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int sum_rec = 0;
int sum_of_digits_rec(int n)
{
	if (n == 0)
		return sum_rec;
	sum_rec += n%10;
	sum_of_digits_rec(n/10);
}
int main()
{
	int a;
	scanf("%i", &a);
	printf("%i\n", sum_of_digits(a));
	printf("%i\n", sum_of_digits_rec(a));
}