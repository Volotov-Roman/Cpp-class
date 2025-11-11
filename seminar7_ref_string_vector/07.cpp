#include <iostream>
#include <string>

void addBrackets(std::string& s)
{
	s = "[" + s + "]";
}

int main()
{
	std::string a = "Cat";
	addBrackets(a);
	std::cout << a << std::endl;
	addBrackets(a);
	std::cout << a << std::endl;
}