#include <stdio.h>
float pi(int n)
{
	float result = 0;
	for (int i = 1; i <= n; i++)
	{
		switch ((i+1)%2)
		{
		case 1:
			result -= (float) 1/(2*i-1);
			break;
		case 0:
			result += (float) 1/(2*i-1);
			break;
		}
	}
	result *= 4;
	return result;
}
int main()
{
	int k;
	scanf("%i", &k);
	printf("%f\n", pi(k));
}