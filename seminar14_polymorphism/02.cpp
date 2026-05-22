#include <iostream>
#include <vector>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
};


std::vector<Individual*> createIndividuals()
{
    std::vector<Individual*> list {};
    for (int i = 0; i<3; i++)
    {
        Individual* p = new Alice {};
        list.push_back(p);
    }
    for (int i = 0; i<2; i++)
    {
        Individual* p = new Bob {};
        list.push_back(p);
    }
    for (int i = 0; i<4; i++)
    {
        Individual* p = new Casper {};
        list.push_back(p);
    }
    return list;
}

void letThemSpeak(std::vector<Individual*>& people)
{
    for (auto iter = people.begin(); iter!=people.end(); iter++)
        (*iter)->speak();
}

void deleteIndividuals(std::vector<Individual*>& people)
{
    for (auto iter = people.begin(); iter!=people.end(); iter++)
        delete *iter;
}

int main()
{
    std::vector<Individual*> people = createIndividuals();
    letThemSpeak(people);
    deleteIndividuals(people);
}