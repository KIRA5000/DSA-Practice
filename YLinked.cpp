#include <iostream>
#include <set>

#include <bits/stdc++.h>

struct Node
{
    int data;
    Node* next;
};

//find comman intersection point in Y shaped linked list
int intersectPoint(Node* head1, Node* head2)
{
    std::unordered_set<Node*> allNodes;
    
    Node* curr = head1;
    
    while (curr)
    {
        allNodes.insert(curr);
        curr = curr->next;
    }
    
    curr = head2;
    int i = 0;
    
    while(curr)
    {
        if (i >= allNodes.size())
        {
            return -1;
        }
        else
        {
            if (allNodes.find(curr) != allNodes.end())
            {
                return curr->data;
            }
            
            curr = curr->next;
        }
    }
    
    return -1;
}