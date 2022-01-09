#include <iostream>

class A
{
    public:

    void display()
    {
        std::cout << "This is A" << std::endl;
    }
};

class B : public A
{
    public:

    void display()
    {
        std::cout << "This is B" << std::endl;
    }
};

int main()
{
    B b;
    b.display();
    b.A::display();
    return 0;
}