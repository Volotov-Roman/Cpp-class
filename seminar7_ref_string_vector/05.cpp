#include <iostream>

struct Book
{
	std::string title;
	int pages;
	float price;
};

bool isExpensive(const Book& b)
{
	return (b.price > 1000);
}

int main()
{
	Book d = {"title", 4000, 136.5};
	Book e = {"title2", 400, 1365};
	std::cout << isExpensive(d) << " " << isExpensive(e) << std::endl;
}