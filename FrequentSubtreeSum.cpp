#include <iostream>
#include <queue>
#include <map>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int postorderSum(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (postorderSum(root->left) + postorderSum(root->right) + root->data);
    }
}

auto MostFrequentSum(Node* root)
{
    std::unordered_map<int, int> m;

    std::queue<Node*> que;

    que.push(root);

    while (!que.empty())
    {
        auto node = que.front();
        que.pop();

        int sum = postorderSum(node);

        if (m.find(sum) != m.end())
        {
            m[sum] += 1;
        }
        else
        {
            m.insert({sum, 1});
        }

        if (node->left != NULL)
        {
            que.push(root->left);
        }

        if (root->right != NULL)
        {
            que.push(root->right);
        }
    }

    int max = INT_MIN;
    std::vector<int> ret;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > max)
        {
            ret.clear();
            max = it->second;
            ret.push_back(it->first);
        }
        else if (it->second == max)
        {
            ret.push_back(it->first);
        }
    }

    return ret;
}