#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& str)
{
	std::vector<std::string> v;
	std::string curr = "";
	for (size_t i = 0; str[i]!=0; ++i)
	{
		curr += str[i];
		v.push_back(curr);
	}
	return v;
}

int main()
{
	std::vector<std::string> v = prefixes("Mouse");
	print(v);
}