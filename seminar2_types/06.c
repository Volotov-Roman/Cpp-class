#include <stdio.h>
# include <math.h>
double integrand(double x, float t)
{
	return pow(t, x-1)*exp(-t);
}
double gamma (double x)
{
	double result = 0;
	const double eps = 1e-10;
	const float step = 1e-2;
	float t=0;
	do
	{
		result += (0.5 * (integrand(x, t)+integrand(x, t+step))*step);
		t += step;
	}
	while ((0.5 * (integrand(x, t)+integrand(x, t+step))*step) > eps);
	return result;
}
int main()
{
	float k;
	scanf("%f", &k);
	printf("%lf\n", gamma(k));
}