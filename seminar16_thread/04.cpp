#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <cstdint>
#include <deque>
using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;



template <typename RandIt>
RandIt getMax(RandIt start, RandIt finish)
{
    RandIt maxIt = start;
    for (auto it = start; it != finish; ++it)
    {
        if (*it > *maxIt)
            maxIt = it;
    }
    return maxIt;
}

template <typename RandIt>
void func(RandIt& storage, RandIt begin, RandIt end)
{
    storage = getMax(begin, end);
}

template <typename RandIt>
RandIt getMax(int n, RandIt start, RandIt finish)
{
    std::vector<RandIt> results(n);
    std::vector<std::thread> threads;

    for (int i = 0; i<n; i++)
    {
        size_t s = finish-start;
        RandIt begin;
        RandIt end;
        begin = start + i * s / n;
        if (i == n-1)
            end = finish;
        else
            end = begin + s / n;
        threads.push_back(std::thread{func<RandIt>, std::ref(results[i]), begin, end});
    }

    for (auto& t : threads)
    {
        t.join();
    }

    RandIt maxIt = results[0];
    for (const auto& el : results)
    {
        if (*el > *maxIt)
            maxIt = el;
    }

    return maxIt;
}


int main()
{
    cout << "Generating numbers!" << endl;
    std::deque<double> numbers = std::deque<double> {1.2, 5.1, 8.2, 1.0, 0.2, 5.0, 7.8};
    /*numbers.push_back(1);
    for (size_t i = 0; i < 1e7; ++i)
    {
        numbers.push_back(numbers.back() * i + 1);
    }*/
    cout << "Numbers generated!" << endl;




    int n;
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();

    auto single_max_it = getMax(numbers.begin(), numbers.end());
    double m = *single_max_it;
    cout << "Single:" << endl;
    cout << "Maximum = " << m << endl;

    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;

    start = std::chrono::high_resolution_clock::now();

    auto parallel_max_it = getMax(n, numbers.begin(), numbers.end());
    double m2 = *parallel_max_it;
    cout << "Parallel:" << endl;
    cout << "Maximum = " << m2 << endl;

    end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}