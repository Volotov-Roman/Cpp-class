#include <stdio.h>

int main()
{
	int n;
	int a[10002];
	int b[10002];
	scanf("%i", &n);
	for (int i=0; i<n; i++)
		scanf("%i", &a[i]);
	for (int i=0; i<n; i++)
	{
		int sum = 0;
		int temp = a[i];
		while (temp > 0)
		{
			sum+=temp%10;
			temp/=10;
		}
		b[i] = sum;
	}
	for (int j=0; j<n; j++)
	{
		for (int i=0; i<n-j-1; i++)
		{
			if (b[i] > b[i+1])
			{
				int temp = b[i];
				b[i] = b[i+1];
				b[i+1] = temp;
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	for (int i = 0; i<n; i++)
		printf("%i ", a[i]);
}