#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* p = (char*)malloc(100 * sizeof(char));
	char* str = "Elephant";
	for (int i = 0; str[i]>0; i++)
		p[i] = str[i];
	printf("%s\n", p);
	free(p);
}