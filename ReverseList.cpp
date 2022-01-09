#include <iostream>

class List
{
    int val;
    List* next;

    public:

    List()
    {
        next = NULL;
    }

    List(int val)
    {
        this->val = val;
        next = NULL;
    }

    List(int val, List* next)
    {
        this->val = val;
        this->next = next;
    }

    List* insert(List* head, int val)
    {
        if (head == NULL)
        {
            head = new List(val);
            return head;
        }
        else
        {
            auto curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            List* n = new List(val);
            curr->next = n;

            return head;
        }
    }

    List* reverse(List* head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        List* prev = NULL;
        auto curr = head;
        List* n = NULL;

        while (curr)
        {
            n = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = n;
        }

        return prev;
    }

    void display(List* head)
    {
        if (head == NULL)
        {
            return;
        }
        
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
    List *l = NULL;
    List call;

    l = call.insert(l, 1);
    l = call.insert(l, 2);
    l = call.insert(l, 3);
    l = call.insert(l, 4);
    l = call.insert(l, 5);
    
    std::cout << "Insert complete\n";

    call.display(l);

    auto r = call.reverse(l, NULL);

    call.display(r);

    return 0;
}