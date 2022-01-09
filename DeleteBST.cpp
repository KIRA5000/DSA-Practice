#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val)
{
    if (root == NULL)
    {
        root = new Node();

        root->data = val;
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    else
    {
        if (val > root->data)
        {
            root->right = insert(root->right, val);
        }
        else if (val < root->data)
        {
            root->left = insert(root->left, val);
        }

        return root;
    }
}

int getNextMin(Node* root)
{
    auto curr = root;

    while (curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr->data;
}

Node* deleteNode(Node* root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
    else if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        if ((root->left == NULL) && (root->right == NULL))
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            auto temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            auto temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            auto temp = getNextMin(root->right);

            root->data = temp;

            root->right = deleteNode(root->right, temp);

            return root;
        }
    }
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        std::cout << root->data << "->";
        inorder(root->right);
    }
    else
    {
        return;
    }
}

int main ()
{
    int size;

    std::cout << "Size of you tree: ";
    std::cin >> size;

    Node* root = NULL;

    std::cout << "Let's insert few value: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        int val;
        std::cin >> val;

        root = insert(root, val);
    }

    std::cout << "Inorder: " << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "Let's delete those values:" << std::endl;

    int val;

    std::cout << "Value you wanna delete: ";
    std::cin >> val;

    root = deleteNode(root, val);

    std::cout << "Inorder: " << std::endl;
    inorder(root);
    std::cout << std::endl;

    return 0;
}