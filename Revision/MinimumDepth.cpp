#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int minDepth(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int a = minDepth(root->left);
    int b = minDepth(root->right);

    if ((a == 0) || (b == 0))
    {
        return std::max(a + 1, b + 1);
    }
    else
    {
        return std::min(a + 1, b + 1);
    }
}