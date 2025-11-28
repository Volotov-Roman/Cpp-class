#include <iostream>
#include <string>
#include <new>

int main() 
{
    std::string stack_string = "Cat";

    std::string* heap_string = new std::string("Dog");
    std::cout << "Heap string: " << *heap_string << std::endl;
    delete heap_string;

    char x[sizeof(std::string)];
    std::string* placement_string = new (x) std::string("Elephant");
    std::cout << "Placement new string: " << *placement_string << std::endl;
    placement_string->~basic_string();
}