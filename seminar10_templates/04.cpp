#include <iostream>
#include <vector>
#include <string>
#include <array>

bool hasMoreElements(auto a, auto b)
{
    return a.size() > b.size();
}

int main()
{
    std::vector<int> a {10, 20, 30, 40, 50};
    std::string b = "Cat";
    std::string c = "Elephant";
    std::array<int, 3> d {10, 20, 30};
    std::cout << hasMoreElements(a, b) << std::endl; // 1
    std::cout << hasMoreElements(a, c) << std::endl; // 0
    std::cout << hasMoreElements(a, d) << std::endl; // 1
}