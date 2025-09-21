#include <stdio.h>
#include <math.h>

int main()
{
	float x1, y1, r1, x2, y2, r2;
	float eps = 1e-5;
	scanf("%f %f %f\n%f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	float dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	if (dist > r1+r2+eps | dist+eps < fabs(r2-r1))
		printf("Do not intersect\n");
	else if ((fabs(dist-r1-r2)<eps)|(fabs(dist - fabs(r2-r1))<eps))
		printf("Touch\n");
	else
		printf("Intersect\n");
}