#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void BoundryPrint(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    std::vector<int> front, back;

    std::queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            auto node = que.front();
            que.pop();

            if (i == 0)
            {
                front.push_back(node->data);
            }
            else if ((i == (size - 1)) && (size != 1))
            {
                back.insert(back.begin(), node->data);
            }

            if (node->left)
            {
                que.push(node->left);
            }

            if (node->right)
            {
                que.push(node->right);
            }
        }
    }

    for (int i = 0; i < front.size(); i++)
    {
        std::cout << front[i] << "->";
    }

    for (int i = 0; i < back.size(); i++)
    {
        std::cout << back[i] << "->";
    }

    std::cout << std::endl;
}