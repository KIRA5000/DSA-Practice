#include <iostream>
#include <queue>
#include <map>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void VerticalTraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    std::queue<std::pair<Node*, int>> que;
    que.push({root, 0});

    std::map<int, std::vector<int>> mp;

    while (!que.empty())
    {
        auto node = que.front();
        que.pop();

        mp[node.second].push_back(node.first->data);

        if (node.first->left)
        {
            que.push({node.first->left, node.second - 1});
        }

        if (node.first->right)
        {
            que.push({node.first->right, node.second + 1});
        }
    }

    for (auto it : mp)
    {
        for (int i = 0; i < it.second.size(); i++)
        {
            std::cout << it.second[i] << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    std::cout << "Vertical order traversal is n";

    VerticalTraversal(root);

    return 0;
}