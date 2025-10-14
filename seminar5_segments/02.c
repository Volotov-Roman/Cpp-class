#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float power(float r, int n)
{
	float result = 1;
	for (int i = 0; i<n; i++)
		result *= r;
	return result;
}
float* get_geometric_progression(float a, float r, int n)
{
	float* p = (float*)malloc(n * sizeof(float));
	for (int i = 0; i<n; i++)
		p[i] = a*power(r, i);
	return p;
}
int main()
{
	float* p = get_geometric_progression(3, 3, 10);
	for (int i = 0; i<10; i++)
		printf("%g ", p[i]);
	free(p);
}