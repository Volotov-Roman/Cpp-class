#include <stdio.h>
#include <math.h>
size_t count_if(int* a, size_t n, int(*pred)(int))
{
	size_t count = 0;
	for (size_t i = 0; i<n; i++)
	{
		if (pred(a[i])) count += 1;
	}
	return count;
}
int is_negative(int x)
{
	return (x<0);
}
int is_even(int x)
{
	return (1 - abs(x%2));
}
int is_square(int x)
{
	float eps = 1e-5;
	return (fabs(sqrt(x) - (float)(int)(sqrt(x)))<eps);
}
int main()
{
	int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};
	printf("%zu\n", count_if(a, 10, is_negative));
	printf("%zu\n", count_if(a, 10, is_even));
	printf("%zu\n", count_if(a, 10, is_square));
}