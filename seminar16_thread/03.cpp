/*
    Задача:

        В данном примере написана функция getMax, которая находит максимум из чисел в векторе.
        При этом вычисления проходят однопоточно.


        Вам нужно написать функцию     

            uint64_t getMaxPar(int n, const std::vector<uint64_t>& v)

        которая будет делать то же самое, но только использовать для этого n потоков.
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdint>
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

void func(uint64_t& storage, std::vector<uint64_t>::const_iterator start, std::vector<uint64_t>::const_iterator end)
{
    uint64_t result = *start;
    for (std::vector<uint64_t>::const_iterator iter = start; iter!=end; iter++)
    {
        if (*iter > result)
            result = *iter;
    }
    storage = result;
}

uint64_t getMaxPar(int n, const std::vector<uint64_t>& v)
{
    std::vector<uint64_t> results (n);
    std::vector<std::thread> threads;
    size_t s = v.size();

    for (int i = 0; i<n; i++)
    {
        auto begin = v.begin() + i * s / n;
        auto end = (i == n-1) ? v.end() : begin + s / n;
        threads.push_back(std::thread{func, std::ref(results[i]), begin, end});
    }

    for (auto& t : threads)
    {
        t.join();
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
    cout << "Single:" << endl;
    cout << "Maximum = " << m << endl;

    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;

    start = std::chrono::high_resolution_clock::now();

    uint64_t m2 = getMaxPar(n, numbers);
    cout << "Parallel:" << endl;
    cout << "Maximum = " << m << endl;

    end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}