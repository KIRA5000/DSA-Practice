#include <iostream>

template<typename T1, typename T2>
class map
{
    T1 key;
    T2 value;
    map* left = NULL;
    map* right = NULL;

    auto getNextMin(map* root)
    {
        auto curr = root;

        while (curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }

    public:

    map(T1 key, T2 value)
    {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
    }

    map* insert(map* root, T1 key, T2 value)
    {
        if (root == NULL)
        {
            root = new map(key, value);

            return root;
        }
        else
        {
            if (root->key > key)
            {
                root->left = insert(root->left, key, value);
                return root;
            }
            else if (root->key < key)
            {
                root->right = insert(root->right, key, value);
                return root;
            }
            else
            {
                return root;
            }
        }
    }

    map* del(map* root, T1 key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            if (root->key > key)
            {
                root->left = del(root->left, key);
            }
            else if (root->key < key)
            {
                root->right = del(root->right, key);
            }

            if ((root->left != NULL) && (root->right != NULL))
            {
                delete root;
                return NULL;
            }
            else if (root->left != NULL)
            {
                auto temp = root->left;
                delete root;
                return temp;
            }
            else if(root->right != NULL)
            {
                auto temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                auto temp = getNextMin(root->right);

                root->key = temp->key;
                root->value = temp->value;

                root->right = del(root->right, temp->key);

                return root;
            }
        }
    }
};

int main()
{
    map<int, int> m1(0, 0);
    map<int, int>* root = NULL;

    root = m1.insert(root, 1, 1);
    root = m1.insert(root, 2, 1);
    root = m1.insert(root, 3, 1);

    
}