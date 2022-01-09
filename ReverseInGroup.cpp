#include <iostream>

struct node
{
    int data;
    node* next;
};

struct node *reverse(struct node *head, int k)
{ 
    if (!head)
    {
        return NULL;
    }
    
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* n = NULL;
    int i = 0;
    
    while ((curr != NULL) && (i < k))
    {
        n = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = n;
        
        i++;
    }
    
    if (n != NULL)
    {
        head->next = reverse(n, k);
    }
    
    return prev;
}