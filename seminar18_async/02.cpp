#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdint>
#include <future>
using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;




uint64_t getMax(const std::vector<uint64_t>& v)
{
    uint64_t result = v.at(0);
    for (auto el : v)
    {
        if (el > result)
            result = el;
    }
    return result;
}

uint64_t func(std::vector<uint64_t>::const_iterator start, std::vector<uint64_t>::const_iterator finish)
{
    uint64_t result = *start;
    for (auto iter = start; iter != finish; iter++)
    {
        if (*iter > result)
            result = *iter;
    }
    return result;
}

uint64_t getMax(int n, const std::vector<uint64_t>& v)
{
    std::vector<std::future<uint64_t>> futures (n);
    size_t s = v.size();

    for (int i = 0; i<n; i++)
    {
        auto begin = v.begin() + i * s / n;
        auto end = (i == n-1) ? v.end() : begin + s / n;
        futures[i] = std::async(func, begin, end);
    }

    std::vector<uint64_t> results;
    for (auto& el : futures)
    {
        results.push_back(el.get());
    }
    results.push_back(v[v.size()-1]);
    return getMax(results);
}

int main()
{
    cout << "Generating numbers!" << endl;
    std::vector<uint64_t> numbers(5e8);
    numbers[0] = 123456789;
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        numbers[i] = numbers[i - 1] * i + 1;
    }
    cout << "Numbers generated!" << endl;


    int n;
    std::cin >> n;


    auto start = std::chrono::high_resolution_clock::now();


    uint64_t m = getMax(numbers);
    cout << "Maximum = " << m << endl;


    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;


    start = std::chrono::high_resolution_clock::now();

    uint64_t m2 = getMax(n, numbers);
    cout << "Maximum = " << m2 << endl;


    end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}