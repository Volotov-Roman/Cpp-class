#include <iostream>

template<typename T>
T cube(T x)
{
    return x * x * x;
}

int main()
{
    char x = 5;
    auto a = cube(x);
    std::cout << (int)a << " " << sizeof(a) << std::endl;
}