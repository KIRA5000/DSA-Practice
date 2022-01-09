#include <iostream>

class Stack
{
    int val;
    Stack* next;

    public:

    Stack()
    {
        next = NULL;
    }
    Stack(int val)
    {
        this->val = val;
        next = NULL;
    }

    Stack* insert(Stack* head, int val)
    {
        if (head == NULL)
        {
            head = new Stack(val);
            return head;
        }
        else
        {
            Stack* nHead = new Stack(val);
            nHead->next = head;
            
            head = nHead;
            return head;
        }
    }

    void display(Stack* head)
    {
        auto curr = head;

        while(curr)
        {
            std::cout << curr->val << "->";
            curr = curr->next;
        }
    }
};

int main()
{
    Stack* head = NULL;
    Stack call;

    head = call.insert(head, 1);
    head = call.insert(head, 2);
    head = call.insert(head, 3);
    head = call.insert(head, 4);
    head = call.insert(head, 5);

    call.display(head);
    
    return 0;
}