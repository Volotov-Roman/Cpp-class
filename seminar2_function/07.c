#include <stdio.h>
int count_even(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i<size; i++)
	{
		if (arr[i]%2==0)
			count += 1;
	}
	return count;
}
int main()
{
	int a[1000];
	int n;
	scanf("%i", &n);
	for (int i=0; i<n; i++)
		scanf("%i", &a[i]);
	printf("%i\n", count_even(a, n));
}