#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* rotate(Node* head, int k)
{
    Node* prevHead = head;
    Node* curr = head;
    int rotations = 0;
    
    while (rotations < (k - 1))
    {
        curr = curr->next;
        ++rotations;
    }
    
    if (curr->next == NULL)
    {
        return head;
    }
    
    Node* prev = curr;
    curr = curr->next;
    prev->next = NULL;
    
    head = curr;
    
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = prevHead;
    
    return head;
}
