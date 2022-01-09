#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int FindDiameter(Node* root, int& diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = FindDiameter(root->left, diameter);
    int r = FindDiameter(root->right, diameter);

    diameter = std::max(diameter, 1 + l + r);

    return (1 + std::max(l, r));
}

int diameter(Node* root)
{
    int diameter = 0;

    FindDiameter(root, diameter);

    std::cout << diameter - 1 << std::endl;
}