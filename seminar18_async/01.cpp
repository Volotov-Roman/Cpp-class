#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include <string>

std::string str;
std::mutex m;
std::condition_variable cv_1;
std::condition_variable cv_2;
bool end = false;

void func1()
{
    std::ifstream file("invisible_man.txt");
    std::string line;
    
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        
        {
            std::unique_lock<std::mutex> lock(m);
            cv_1.wait(lock, []{ return str.empty(); });
            str = line;
        }
        cv_2.notify_one();
        {
            std::unique_lock<std::mutex> lock(m);
            cv_1.wait(lock, []{ return str.empty(); });
        }
    }

    {
        std::unique_lock<std::mutex> lock(m);
        cv_1.wait(lock, []{ return str.empty(); });
        end = true;
    }
    cv_2.notify_one();
}

void func2()
{
    while (true)
    {
        std::string current_line;
        {
            std::unique_lock<std::mutex> lock(m);
            cv_2.wait(lock, []{ return !str.empty() || end; });
            if (end && str.empty())
                break;   
            current_line = str;
            str = "";
        }

        for (auto& c : current_line)
            c = std::toupper(c);
        std::cout << current_line << std::endl;
        
        cv_1.notify_one();
    }
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func2);
    
    t1.join();
    t2.join();
}