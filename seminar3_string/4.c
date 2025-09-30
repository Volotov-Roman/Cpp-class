#include <stdio.h>
int main()
{
	char a[100];
	char b[100];
	scanf("%s", a);
	scanf("%s", b);
	int i = 0;
	while (a[i] && b[i])
	{
		printf("%c", a[i]);
		printf("%c", b[i]);
		i++;
	}
	if (a[i] != 0)
	{
		while (a[i])
		{
			printf("%c", a[i]);
			i++;
		}
	}
	else if (b[i] != 0)
	{
		while (b[i])
		{
			printf("%c", b[i]);
			i++;
		}
	}
}