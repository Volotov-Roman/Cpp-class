#include <stdio.h>
void mult2(int* p, size_t n)
{
	for (int i = 0; i<n; i++)
	{
		*p *= 2;
		p = p + 1;
	}
}
int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int* p = &a[0];
	mult2(p, 5);
	for (int i = 0; i<5; i++)
		printf("%i\n", a[i]);
}