#include <stdio.h>
void alice(int n);
void bob(int n);
void alice(int n)
{
	n = 3*n + 1;
	printf("Alice: %i\n", n);
	if (n%2 == 0)
		bob(n);
	else
		alice(n);
}
void bob(int n)
{
	n = n/2;
	printf("Bob:   %i\n", n);
	if (n%2 == 0)
		bob(n);
	else if (n!=1)
		alice(n);
}
int main()
{
	int a;
	scanf("%i", &a);
	alice(a);
}