#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>
#include <string>


std::string str;
std::mutex m;
bool end = false;


void func1()
{
    std::ifstream file("invisible_man.txt");
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        while (true)
        {
            {
                std::lock_guard lk(m);
                if (str.empty())
                {
                    str = line;
                    break;
                }
            }
        }
        while (true)
        {
            {
                std::lock_guard lk(m);
                if (str.empty())
                    break;
            }
        }
    }
    
    while (true)
    {
        {
            std::lock_guard lk(m);
            if (str.empty())
            {
                end = true;
                break;
            }
        }
    }
}

void func2()
{
    while (true)
    {
        std::string current_line;
        {
            std::lock_guard lk(m);
            if (!str.empty())
            {
                current_line = str;
                str = "";
            }
        }
        
        if (!current_line.empty())
        {
            for (auto& c : current_line)
                c = std::toupper(c);
            std::cout << current_line << std::endl;
        }
        else
        {
            std::lock_guard lk(m);
            if (end && str.empty())
                break;
        }
    }
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();
}