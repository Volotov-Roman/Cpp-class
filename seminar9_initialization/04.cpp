#include <iostream>
#include <string>
#include <vector>

int main()
{
    int* int_ptr = new int(123);
    std::string* string_ptr = new std::string("Cats and Dogs");
    int* int_array = new int[5]{10, 20, 30, 40, 50};
    std::vector<int>* vector_ptr = new std::vector<int>{10, 20, 30, 40, 50};
    std::string* string_array = new std::string[3]{"Cat", "Dog", "Mouse"};

    std::cout << "int: " << *int_ptr << std::endl;
    std::cout << "string: " << *string_ptr << std::endl;

    std::cout << "int array: ";
    for (int i = 0; i < 5; ++i) 
    {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "vector: ";
    for (int i = 0; i < 5; ++i) 
    {
        std::cout << (*vector_ptr)[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "string array: ";
    for (int i = 0; i < 3; ++i) 
    {
        std::cout << string_array[i] << " ";
    }
    std::cout << std::endl;

    delete int_ptr;
    delete string_ptr;
    delete[] int_array;
    delete vector_ptr;
    delete[] string_array;
}