#include <iostream>
#include <string>
using namespace std::string_literals;

template<typename T>
class Manager
{
public:
    T* p;

    Manager() {p = NULL;}

    void allocate()
    {
        p = (T*)std::malloc(sizeof(T));
    }

    void construct(const T& t)
    {
        new(p) T(t);
    }

    void destruct()
    {
        p->~T();
    }

    void deallocate()
    {
        std::free(p);
    }

    T& get()
    {
        return *p;
    }
};

int main()
{
    Manager<std::string> a;
    a.allocate();

    a.construct("Cats and dogs"s);
    a.get() += " and elephant";
    std::cout << a.get() << std::endl; // Cats and dogs and elephant
    a.destruct();

    a.construct("Sapere Aude"s);
    std::cout << a.get() << std::endl; // Sapere Aude
    a.destruct();

    a.deallocate();
}