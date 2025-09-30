#include <stdio.h>
#include <string.h>
int main()
{
	int x = 0;
	int y = 0;

	int n;
	scanf("%i", &n);

	char direction[10];
	int dist;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", direction);
		scanf("%i", &dist);
		if (strcmp(direction, "North") == 0) 
			y += dist;
		if (strcmp(direction, "South") == 0)
			y -= dist;
		if (strcmp(direction, "East") == 0)
			x += dist;
		if (strcmp(direction, "West") == 0)
			x -= dist;
	}
	printf("%i %i", x, y);
}