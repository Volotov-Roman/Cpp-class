#include <stdio.h>
struct cat
{
	char x;
	size_t y;
};
struct dog
{
	size_t y;
	char x;
};
struct mouse
{
	char x;
	char y;
	size_t z;
};
struct rat
{
	char x;
	size_t z;
	char y;
};
struct fox
{
	char x;
	struct mouse y;
};
int main()
{
	char a1;
	int a2;
	size_t a3;
	int a4[10];
	int* a5;
	struct cat a6;
	struct dog a7;
	struct mouse a8;
	struct rat a9;
	struct fox a10;
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a1), alignof(a1));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a2), alignof(a2));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a3), alignof(a3));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a4), alignof(a4));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a5), alignof(a5));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a6), alignof(a6));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a7), alignof(a7));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a8), alignof(a8));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a9), alignof(a9));
	printf("Size: %i bits, Alignment: %zu bits\n", sizeof(a10), alignof(a10));
}