#include <stdio.h>
int main()
{
	long int sum = 0;
	char str[100000000];
	scanf("%s", str);
	int i = 0;
	while (str[i])
	{
		sum += (str[i] - '0');
		i++;
	}
	printf("%li", sum);
}