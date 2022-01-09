#include <iostream>

// how to solve ambiguity
class A
{
    public:

    void display()
    {
        std::cout << "This is A" << std::endl;
    }
};

class B
{
    public:

    void display()
    {
        std::cout << "This is B" << std::endl;
    }
};

class C : public A, public B
{
    public:

    // void display()
    // {
    //     std::cout << "This is C" << std::endl;
    // }
};

int main ()
{
    C obj;

    obj.A::display();

    return 0;
}