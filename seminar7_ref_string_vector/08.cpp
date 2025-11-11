#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
	int l = 0;
	int d = 0;
	for(int i = 0; str[i]!=0; ++i)
	{
		if (std::isalpha(str[i]))
			l += 1;
		else if (std::isdigit(str[i]))
			d += 1;
	}
	numLetters = l;
	numDigits = d;
}


int main()
{
	std::string a = "Cat";
	std::string b = "Cat05";
	std::string c = "C349f";
	int let = 0;
	int dig = 0;
	countLetters(a, let, dig);
	std::cout << let << " " << dig << std::endl;
	countLetters(b, let, dig);
	std::cout << let << " " << dig << std::endl;
	countLetters(c, let, dig);
	std::cout << let << " " << dig << std::endl;
}