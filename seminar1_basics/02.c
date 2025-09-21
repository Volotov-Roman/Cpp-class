#include <stdio.h>
int main()
{
	int n;
	scanf("%i", &n);
	if ((n%2==0) * (((n>=0)*(n<=20)) + (n>100)*(n<200)))
		printf("Yes");
	else
		printf("No");
}