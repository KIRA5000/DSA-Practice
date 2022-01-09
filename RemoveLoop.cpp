#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void removeLoop(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        return;
    }
    
    auto turtle = head->next;
    auto rabbit = head->next->next;
    
    Node* commonNode = NULL;
    
    while (true)
    {
        if ((!rabbit) || (!turtle) || (rabbit->next == NULL) || (turtle->next == NULL) || (rabbit->next->next == NULL))
        {
            break;
        }
        
        if (rabbit == turtle)
        {
            commonNode = rabbit;
            break;
        }
        
        rabbit = rabbit->next->next;
        turtle = turtle->next;
    }
    
    if (commonNode == NULL)
    {
        return;
    }
    else
    {
        turtle = turtle->next;
        int nEle = 1;

        while(turtle != commonNode)
        {
            turtle = turtle->next;
            nEle++;
        }

        nEle++;

        turtle = head;
        int count = 0;

        while (count != nEle)
        {
            turtle = turtle->next;
            count++;
        }

        rabbit = head;

        while(turtle->next != rabbit->next)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
        }

        rabbit->next = NULL;
    }
}