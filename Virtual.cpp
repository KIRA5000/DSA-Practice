#include <iostream>

class A
{
    public:
    void display()
    {
        std::cout << "This is class A" << std::endl;
    }
};

class B : public A
{
    public:

    void display()
    {
        std::cout << "This is class B" << std::endl;
    }
};

int main()
{
    A* obj = new B();

    obj->display();

    return 0;
}