#include <iostream>

void cube(int& r)
{
	r = r*r*r;
}

int main()
{
	int a = 5;
	cube(a);
	std::cout << a << std::endl;
}