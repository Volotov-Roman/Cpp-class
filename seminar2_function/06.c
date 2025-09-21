#include <stdio.h>
int trib(int n)
{
	int arr[1000];
	arr[0]=0;
	arr[1]=0;
	arr[2]=1;
	for (int i=3; i<=n; i++)
		arr[i] = arr[i-3] + arr[i-2] + arr[i-1];	
	return arr[n];
}
int main()
{
	int a;
	scanf("%i", &a);
	printf("%i\n", trib(a));
}