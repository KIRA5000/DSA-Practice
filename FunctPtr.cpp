#include <iostream>

void display()
{
    std::cout << "This is display()" << std::endl;
}

void function(void (*func)())
{
    std::cout << "this is function()" << std::endl;

    func();
}

int main()
{
    void (*func)(void);

    func = display;

    function (display);
}