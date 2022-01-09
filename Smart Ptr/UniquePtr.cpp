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
    std::unique_ptr<node> ptr1(new node(5, NULL));

    std::cout << ptr1->data << std::endl;

    std::unique_ptr<node> ptr2;
    ptr2 = move(ptr1);

    std::cout << "ptr2 data: " << ptr2->data << std::endl;
    // std::cout << "ptr1 data: " << ptr1->data << std::endl;

    return 0;
}