#include <iostream>

template <typename T>
class SmartPtr
{
    T* ptr;

    public:

    explicit SmartPtr(T* p = NULL)
    {
        ptr = p;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    ~SmartPtr()
    {
        delete ptr;
    }
};

int main()
{
    SmartPtr<int> ptr(new int());

    *ptr = 5;

    std::cout << *ptr << std::endl;

    return 0;
}