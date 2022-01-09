#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* convert(Node* root)
{
    Node* curr = NULL;
    Node* head = NULL;

    if (root == NULL)
    {
        return NULL;
    }

    if (root->left)
    {
        head = convert(root->left);
    }

    if (head == NULL)
    {
        head = new Node(root->data, NULL, NULL);
    }
    else
    {
        curr = head;

        while (curr->right)
        {
            curr = curr->right;
        }

        Node* temp = new Node(root->data, curr, NULL);
        curr->right = temp;
    }

    if (root->right)
    {
        auto temp = convert(root->right);
        curr->right = temp;
        temp->left = curr;
    }

    return head;
}