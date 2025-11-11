#include <iostream>

void swap(int& x, int& y)
{
	int temp = y;
	y = x;
	x = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	std::cout << a << " " << b << std::endl;
	
	swap(a, b);
	std::cout << a << " " << b << std::endl;
}