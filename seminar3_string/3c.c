#include <stdio.h>
#include <ctype.h>
int main()
{
	char a;
	scanf("%c", &a);
	if (isdigit(a))
		printf("Digit");
	else if (isalpha(a))
		printf("Letter");
	else
		printf("Other");
}