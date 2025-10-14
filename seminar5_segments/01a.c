#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)malloc(sizeof(size_t));
	*p = 123;
	printf("%zu\n", *p);
	free(p);
}