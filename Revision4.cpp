#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* reverseInGroups(Node* head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    auto curr = head;
    Node* prev = NULL, *n = NULL;

    for (int i = 0; i < k; i++)
    {
        if (curr == NULL)
        {
            break;
        }

        n = curr->next;
        curr->next = prev;

        prev = curr;
        curr = n;
    }

    if (n != NULL)
    {
        head->next = reverseInGroups(n, k);
    }

    return prev;
}