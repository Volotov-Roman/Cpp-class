#include <stdio.h>
void reverse(int arr[], int size)
{
	for (int i = 0; i<size/2; i++)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;
	}
}
int main()
{
	int a[1000];
	int n;
	scanf("%i", &n);
	for (int i=0; i<n; i++)
		scanf("%i", &a[i]);
	reverse(a,n);
	for (int i=0; i<n; i++)
		printf("%i ", a[i]);
}