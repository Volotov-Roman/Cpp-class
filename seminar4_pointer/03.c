#include <stdio.h>
void cube(float* px)
{
	*px = *px * *px * *px;
}
int main()
{
	float a = 1.2;
	float* p = &a;
	cube(p);
	printf("%f\n", a);
}