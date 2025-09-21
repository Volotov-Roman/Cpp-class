#include <stdio.h>
unsigned long long n_k(int n, int k)
{
	unsigned long long result = 1;
	for (int i = n; i > n-k; i--)
	result *= i;
	return result;
}
int main()
{
	int n;
	int k;
	scanf("%i", &n);
	scanf("%i", &k);
	printf("%llu\n", n_k(n, k));
}