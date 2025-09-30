#include <stdio.h>
#include <string.h>
void encrypt(char* str, int k)
{
	size_t length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			;
		else if ((str[i] + k >= 'A' && str[i] + k <= 'Z' && str[i]>='A' && str[i]<='Z') | (str[i] + k >= 'a' && str[i] + k <= 'z' && str[i]>='a' && str[i]<='z'))
			str[i]+=k;
		else
			str[i] = str[i] + k - ('z' - 'a') - 1;
	}	
	printf("%s", str);
}
int main()
{
	char a[100];
	int shift;
	scanf("%i ", &shift);
	scanf("%[^\n]", a);
	encrypt(a, shift);
}