#include <iostream>
#include <queue>

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

    void bfs(Tree* root)
    {
        std::queue<Tree*> q;
        q.push(root);

        while (q.size() != 0)
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                Tree* node = q.front();
                q.pop();

                std::cout << node->value << "->";

                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
        }
    }
};

int main()
{
    Tree *root = NULL, bst;

    root = bst.insert(root, 5);
    root = bst.insert(root, 3);
    root = bst.insert(root, 1);
    root = bst.insert(root, 4);
    root = bst.insert(root, 7);

    bst.bfs(root);

    std::cout << std::endl;

    return 0;
}