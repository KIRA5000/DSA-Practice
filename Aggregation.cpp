#include <iostream>

class A
{
    int a;

    public:

    A(int x)
    {
        a = x;
    }

    void display()
    {
        std::cout << "This is class A" << std::endl;
    }
};

class B
{
    int b;
    A *obj;

    public:

    B(int x, A* obj)
    {
        b = x;
        this->obj = obj;
    }

    void display()
    {
        std::cout << "This is class B" << std::endl;
        obj->display();
    }
};

int main()
{
    A aObj(5);

    B obj(3, &aObj);

    obj.display();

    return 0;
}