#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game
{
	float rating;
	char title[50];
};
typedef struct game Game;
int cmp(const void*  a, const void* b)
{
	return (((Game*)a)->rating < ((Game*)b)->rating);
}
int main()
{
	int n;
	scanf("%i", &n);
	Game array[100];
	for (int i = 0; i<n; i++)
	{
		char title[50];
		char temp;
		char numbers[50];
		scanf("%[^:]", title);
		scanf("%c", &temp);
		scanf("%[^\n]", numbers);
		int sum = 0;
		int count = 0;
		for (int i = 0; numbers[i]>0; i++)
		{
			if (numbers[i] != ' ')
			{
				if (numbers[i] == '1')
				{
					sum += 1;
					count++;
					if (numbers[i+1] == '0')
						sum += 9;
				}
				else if (numbers[i] > '1')
				{
					sum += numbers[i] - '0';
					count++;
				}
			}
		}
		strcpy(array[i].title, title);
		array[i].rating = (float)sum / (float)count;
		scanf("%c", &temp);
	}
	qsort(array, n, sizeof(Game), cmp);
	for (int i = 0; i<n; i++)
		printf("%s, %.3f\n", array[i].title, array[i].rating);
}
