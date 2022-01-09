#include <iostream>

class C
{
    int a;

    public:

    C()
    {
        a = 5;
    }

    C operator++(int)
    {
        C temp;
        temp.a = a++;
        return temp;
    }

    C operator++()
    {
        C temp;
        temp.a = --a;
        return temp;
    }

    void display()
    {
        std::cout << "A: " << a << std::endl;
    }
};

int main()
{
    C c;

    C c2 = c++;
    C c3 = ++c;

    c2.display();
    c3.display();

    return 0;
}