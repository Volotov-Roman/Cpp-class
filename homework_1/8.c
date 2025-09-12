#include <stdio.h>

int main()
{
	int a;
	scanf("%i", &a);
	int m[1000];
	for (int i = 0; i<a; i++)
	{
		int f;
		scanf("%i", &f);
		m[i] = f;
		printf("%i ", f);
	}
	for (int i = 0; i<a; i++)
		printf("%i ", m[i]);
}