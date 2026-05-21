#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std::chrono_literals;

void func(int x)
{
    std::cout << "Thread #" << x << " started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(x));
    std::cout << "Thread #" << x << " finished" << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::thread> threads;
    for (int i = 0; i < n; i++)
    {
        threads.push_back(std::thread{func, i+1});
    }
    
    for (auto& t : threads)
    {
        t.join();
    }
}