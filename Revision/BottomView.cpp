#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void printBottom(Node* root)
{
    std::map<int, std::vector<Node*>> level;
    std::queue<std::pair<Node*, int>> que;

    que.push({root, 0});
    level[0].push_back(root);

    while (!que.empty())
    {
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            auto node = que.front();
            que.pop();

            if (node.first->left != NULL)
            {
                que.push({node.first->left, node.second - 1});
                level[node.second].push_back(node.first->left);
            }
            if (node.first->right != NULL)
            {
                que.push({node.first->right, node.second + 1});
                level[node.second].push_back(node.first->right);
            }
        }
    }
}