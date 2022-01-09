#include <iostream>
#include <vector>
#include <climits>

struct Node
{
    char data;
    Node* prev;
    Node* next;

    Node(char data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void append(Node** head, Node** tail, char x)
{
    if (*head == NULL)
    {
        *head = new Node(x);
        *tail = *head;
    }
    else
    {
        Node* temp = new Node(x);
        (*tail)->next = temp;
        temp->prev = *tail;
        (*tail) = temp;
    }
}

void remove(Node** head, Node** tail, Node* temp)
{
    if (*head == NULL)
    {
        return;
    }

    if (*head == temp)
    {
        *head = (*head)->next;
    }
    if (*tail == temp)
    {
        *tail = (*tail)->prev;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}

auto findFirstNotRepeating(std::string& str)
{
    Node* head = NULL;
    Node* inDll[256];
    bool isRepeated[256];

    for (int i = 0; i < 256; i++)
    {
        inDll[i] = NULL;
        isRepeated[i] = false;
    }

    std::vector<char> ret;

    Node *tail = NULL;

    for (int i = 0; i < str.size(); i++)
    {
        if (!isRepeated[str[i]])
        {
            if (inDll[str[i]] == NULL)
            {
                append(&head, &tail, str[i]);
                inDll[str[i]] = tail;
            }
            else
            {
                remove(&head, &tail, inDll[str[i]]);
                isRepeated[str[i]] = true;
            }
        }

        ret.push_back(head->data);
    }

    return ret;
}

int main()
{
    std::string str;

    std::cout << "Enter string: ";
    std::cin >> str;

    auto ret = findFirstNotRepeating(str);

    std::cout << "All first non repeating characters:" << std::endl;

    for (int i = 0 ; i < ret.size(); i++)
    {
        std::cout << ret[i];
    }
    std::cout << std::endl;

    return 0;
}