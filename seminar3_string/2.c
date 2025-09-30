#include <stdio.h>
int main()
{
	char a = 32;
	while (a>=32 && a<=126)
	{
		printf("Symbol = %c, Code = %i\n", a, a);
		a++;
	}

}