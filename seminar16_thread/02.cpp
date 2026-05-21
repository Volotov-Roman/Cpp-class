#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std::chrono_literals;

void func(int x, int n)
{
    std::cout << "Thread #" << x << " started" << std::endl;
    std::this_thread::sleep_for(200ms);
    if (x<n) 
    {
        std::thread t(func, x+1, n);
        t.join();
    }
    std::this_thread::sleep_for(200ms);
    std::cout << "Thread #" << x << " finished" << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::thread t(func, 1, n);
    t.join();
}