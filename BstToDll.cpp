#include <iostream>
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
    }
};

Node* convert(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node* head = NULL;
    Node* curr = head;

    if (root->left != NULL)
    {
        head = convert(root->left);
        curr = head;
    }

    if (head == NULL)
    {
        head = new Node(root->data);
        curr = head;
    }
    else
    {
        curr = head;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }

        Node* nNode = new Node(root->data);
        curr->right = nNode;
        nNode->left = curr;

        curr = nNode;
    }

    if (root->right != NULL)
    {
        auto temp = convert(root->right);
        curr->right = temp;
        temp->left = curr;
    }

    return head;
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        std::cout << node->data << " ";
        node = node->right;
    }
}

int main()
{
    // Let us create the tree shown in above diagram
    Node *root        = new Node(10);
    root->left        = new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
 
    // Convert to DLL
    Node *head = convert(root);
 
    // Print the converted list
    printList(head);
 
 
    return 0;
}