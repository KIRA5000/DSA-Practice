#include <iostream>

class Tree
{
    public:

    int value;
    Tree *left, *right;

    Tree ()
    {
        left = NULL;
        right = NULL;
    }

    Tree* insert(Tree* root, int value)
    {
        if (root == NULL)
        {
            root = new Tree();
            root->value = value;
        }
        else
        {
            Tree* curr = root;

            if (value <= root->value)
            {
                root->left = insert(root->left, value);
            }
            else
            {
                root->right = insert(root->right, value);
            }
        }

        return root;
    }

    void inorder(Tree* root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        std::cout << root->value << "->";
        inorder(root->right);
    }
};

int main()
{
    Tree *root = NULL, bst;

    root = bst.insert(root, 1);
    root = bst.insert(root, 2);
    root = bst.insert(root, 3);
    root = bst.insert(root, 4);
    root = bst.insert(root, 5);

    bst.inorder(root);

    std::cout << std::endl;

    return 0;
}