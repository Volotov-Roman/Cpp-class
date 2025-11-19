/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в массиве в сегменте куча.
    В самом объекте будем хранить указатель на данные в куче.
    Также, в самом объекте будут храниться размер и вместимость массива.

        data - указатель, на элементы, хранящиеся в куче.
        capacity - размер массива data.
        size - сколько ячеек занимет число в массиве data, size <= capacity.

    По условию задачи класс Number должен поддерживать только положительные числа.
    Это сделано для того, чтобы задача не была слишком сложной.

    Каждый элемент массива должен содержать разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент массива должен хранить две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа, размером 1 байт),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами). 
    Например, число 12345678 соответствует массиву:
    
        {78, 56, 34, 12}
    
    Для выделения/освобождения памяти в куче были использованы операторы new[] и delete[].
    Хотя можно было бы и использовать функции malloc и free из библиотеки cstdlib.

    Выделение/освобождения с использованием malloc/free:

        data = static_cast<char*>(std::malloc(capacity * sizeof(char)));
        ...
        std::free(data);

    То же самое с использованием new[]/delete[]:

        data = new char[capacity];
        ...
        delete[] data;

*/
#pragma once

#include <iostream>
#include <iomanip>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память в куче и записывем число a в массив data
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number()
    {
        capacity = 1;
        data = new char[capacity];
        data[0] = 0;
        size = 1;
    }

    Number(const Number& n)
    {
        capacity = n.capacity;
        data = new char[capacity];
        for (size_t i = 0; i < capacity; i++)
            data[i] = n.data[i];
        size = n.size;
    }

    Number(const std::string& str)
    {
        size_t len = str.size();
        std::string str2;
        if (len%2!=0)
            str2 = "0" + str;
        len = str2.size();
        capacity = len/2;
        data = new char[capacity];

        for (size_t i = 0; i < capacity; i++)
        {
            char res = (str2[len-1-2*i]-'0') + 10*(str2[len-2-2*i]-'0');
            data[i] = res;
        }
        size = capacity;
    }


    ~Number() 
    {
        // Освобождаем память в куче
        delete [] data;
    }

    Number& operator=(const Number& n)
    {
        capacity = n.capacity;
        size = n.size;
        data = new char[capacity];
        for (std::size_t i = 0; i < size; i++) 
        {
            data[i] = n.data[i];
        }
        return *this;
    }

    bool isEven() const
    {
        return data[0]%2 == 0;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
    friend Number operator+(const Number& a, const Number& b);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}

Number operator+(const Number& a, const Number& b)
{
    Number res;
    res.capacity = a.capacity;
    if (b.capacity > res.capacity)
        res.capacity = b.capacity;
    res.capacity += 1;

    res.size = res.capacity;

    res.data = new char[res.capacity];
    for (size_t i = 0; i < res.capacity; i++)
        res.data[i] = 0;

    for (size_t i = 0; i < res.capacity; i++)
    {
        if ((i < a.capacity) && (i<b.capacity))
        {
            char sum = a.data[i] + b.data[i];
            if (sum>100)
            {
                res.data[i+1] += 1;
                sum -= 100;
            }
            res.data[i] = sum;
        }

        else if ((i < a.capacity) && !(i<b.capacity))
        {
            char sum = a.data[i];
            res.data[i] = sum;
        }

        else if (!(i < a.capacity) && (i<b.capacity))
        {
            char sum = b.data[i];
            res.data[i] = sum;
        }

        else
        {
            if (res.data[i] == 0)
                res.size -= 1;
        }
    }
    return res;
}

Number& operator+=(Number& a, const Number& b)
{
    a = a + b;
    return a;
}