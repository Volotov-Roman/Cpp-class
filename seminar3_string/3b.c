#include <stdio.h>
int main()
{
	char a;
	scanf("%c", &a);
	if (a>='0' && a<='9')
		printf("Digit");
	else if ((a>='A' && a<='Z') | (a>='a' && a<='z'))
		printf("Letter");
	else
		printf("Other");
}