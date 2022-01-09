#include <iostream>

struct node
{
    int data;
    node* next;

    node(int val, node* ptr)
    {
        data = val;
        next = ptr;
    }
};

int main()
{
    std::shared_ptr<node> ptr1(new node(5, NULL));

    std::cout << ptr1->data << std::endl;

    std::shared_ptr<node> ptr2 = ptr1;

    std::cout << "ptr2 data: " << ptr2->data << std::endl;
    std::cout << "ptr1 data: " << ptr1->data << std::endl;
    std::cout << "Shared pointer count: " << ptr1.use_count() << std::endl;

    ptr1.~shared_ptr();

    std::cout << "Shared pointer count: " << ptr2.use_count() << std::endl;

    return 0;
}