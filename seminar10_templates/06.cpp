#include <iostream>

template<typename T, int Base>
class Modular
{
public:
    T value;

    Modular(int a)
    {
        if (a >= 0 && a < Base)
            value = a;
        else if (a >= Base)
            value = a%Base;
        else if (a < 0)
            value = Base - (Base - a)%Base;
    }

    Modular(const Modular<T, Base>& other)
    {
        value = other.value;
    }

    template<typename U, int OtherBase>
    Modular(const Modular<U, OtherBase>& other)
    {
        value = other.value%Base;
    }

    Modular& operator=(const Modular<T, Base>& other)
    {
        value = other.value;
        return *this;
    }

    Modular operator+(const Modular& other)
    {
        return Modular{(value+other.value)%Base};
    }

    Modular operator-(const Modular& other)
    {
        return *this + (-other);
    }

    Modular operator*(const Modular& other)
    {
        return Modular{(value*other.value)%Base};
    }

    Modular operator*(const int& n)
    {
        return Modular{(value*n)%Base};
    }

    Modular operator-() const
    {
        return Modular{(Base-value)%Base};
    }

    Modular operator+(int n)
    {
        return Modular{(value+n)%Base};
    }
    
    template<typename U, int B>
    friend std::ostream& operator<<(std::ostream& out, const Modular<U, B>& a);
};

template<typename T, int Base>
std::ostream& operator<<(std::ostream& out, const Modular<T, Base>& a)
    {
        out << a.value;
        return out;
    }

int main()
{
    Modular<int, 7> a(10);
    std::cout << a << std::endl; //3
    a = (a + 8) * 4;
    std::cout << a << std::endl; //2

    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl; //5

    Modular<short, 3> c(a);
    std::cout << c << std::endl; //2
}