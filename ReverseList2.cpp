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

    List* reverse(List* head, List* prev)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            auto out = reverse(head->next, head);

            if (out == NULL)
            {
                out = head;
                out->next = prev;
                prev->next = NULL;
                
                head = out;
            }
            else
            {
                auto curr = out;

                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                curr->next = head;
                head->next = NULL;
                
                head = out;
            }

            return head;
        }
    }

    void display(List* head)
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
    List *l = NULL;
    List call;

    l = call.insert(l, 1);
    l = call.insert(l, 2);
    l = call.insert(l, 3);
    l = call.insert(l, 4);
    l = call.insert(l, 5);
    
    std::cout << "Insert complete\n";

    call.display(l);
    
    std::cout << std::endl;

    auto r = call.reverse(l, NULL);

    call.display(r);

    return 0;
}