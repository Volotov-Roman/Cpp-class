#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* concat(const char* a, const char* b)
{
	size_t n = strlen(a)+strlen(b);
	char* p = (char*)malloc(n * sizeof(char));
	int i = 0;
	while (a[i]>0)
	{
		p[i] = a[i];
		i++;
	}
	int j = 0;
	while (b[j]>0)
	{
		p[i] = b[j];
		i++;
		j++;
	}
	return p;
}
int main()
{
	char* a = "Cat";
	char* b = "Dog";
	char* q = concat(a, b);
	printf("%s", q);
	free(q);
}