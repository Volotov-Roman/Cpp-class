#include <stdio.h>
#include <stdint.h>
int main()
{
	printf("%zu\n", sizeof(char));
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(size_t));
	printf("%zu\n", sizeof(int8_t));
	printf("%zu\n", sizeof(int32_t));
	printf("%zu\n", sizeof(uint32_t));
	printf("%zu\n", sizeof(float));
	printf("%zu\n", sizeof(double));
	printf("%zu\n", sizeof(int[100]));
	printf("%zu\n", sizeof(char[100]));

}