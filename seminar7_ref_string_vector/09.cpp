#include <iostream>
#include <string>

std::string repeat(int n)
{
	if (n<0)
		return "";
	else
	{
		std::string res = "";
		std::string n_str = std::to_string(n);
		for (int i = 0; i<n; ++i)
			res += n_str;
		return res;
	}
}

int main()
{
	std::cout << repeat(5) << std::endl;
	std::cout << repeat(10) << std::endl;
	std::cout << repeat(-1) << std::endl;
}