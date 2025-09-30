#include <stdio.h>
int main()
{
	char a;
	scanf("%c", &a);
	if (a>=48 && a<=57)
		printf("Digit");
	else if ((a>=65 && a<=90) | (a>=97 && a<=122))
		printf("Letter");
	else
		printf("Other");
}