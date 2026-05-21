#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std::string_literals;

void func(const std::string& a, int b)
{
    std::cout << a << " " << b << std::endl;
}

template <typename Function, typename... Args>
void iterate(int n, Function f, Args... args)
{
    std::vector<std::thread> threads;
    for (int i = 0; i<n; i++)
    {
        threads.push_back(std::thread{func, args...});
    }
    for (auto& t : threads)
    {
        t.join();
    }
}

int main()
{
    iterate(5, func, "Hello"s, 12345);
}