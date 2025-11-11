#include <iostream>
#include <string>

bool isDomainName(std::string s)
{
	if(s.starts_with("www.") && s.ends_with(".com"))
		return 1;
	else return 0;
}

int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;
	std::cout << isDomainName("abc") << std::endl;
	std::cout << isDomainName("hello.com") << std::endl;
}