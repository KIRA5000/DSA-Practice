#include <iostream>

class A
{
    int i;

    public:

    virtual void display() = 0;

    void setI()
    {
        i = 5;
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
    //A obj;
    A* obj = new B();

    obj->display();

    return 0;
}