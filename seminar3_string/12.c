#include <stdio.h>
#include <string.h>
int main(int argc, char** argv)
{
	int count;
	sscanf(argv[2], "%i", &count);
	for (int i=0; i<count; i++)
		printf("%s ", argv[1]);
}