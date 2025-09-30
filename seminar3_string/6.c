#include <stdio.h>
#include <string.h>
void is_palindrom(const char str[])
{
	size_t length = strlen(str);
	for (int i = 0; i <= length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			printf("No");
			return;
		}
	}
	printf("Yes");
	return;
}
int main()
{
	char a[100];
	scanf("%s", a);
	is_palindrom(a);
}