#include <stdio.h>
void safe_strcpy(char res[], size_t length, const char str[])
{
	for (int i = 0; i<length-1; i++)
		res[i] = str[i];
	res[length-1] = 0;
	return;
}
int main()
{
	char a[10] = "Mouse";
	char b[50] = "LargeElephant";
	safe_strcpy(a, 10, b);
	printf("%s", a);
}