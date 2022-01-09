#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* insert(Node* head, int data)
{
    auto curr = head;

    if (head == NULL)
    {
        head = new Node(data, NULL);
        return head;
    }

    while (curr->next)
    {
        curr = curr->next;
    }

    Node* temp = new Node(data, NULL);
    curr->next = temp;

    return head;
}

Node* ReverseLinkedList(Node* head)
{
    if (head == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    auto curr = head;
    Node* n = NULL;

    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;

        prev = curr;
        curr = n;
    }

    return prev;
}

Node* ReverseInGroups(Node* head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    auto curr = head;
    Node* n = NULL;

    for (int i = 0; i < k; i++)
    {
        if (curr == NULL)
        {
            break;
        }

        n = curr->next;
        curr->next = prev;

        prev = curr;
        curr = n;
    }

    if (curr != NULL)
    {
        head->next = ReverseInGroups(curr, k);
    }

    return prev;
}

void display(Node* head)
{
    auto curr = head;

    while (curr)
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main()
{
    Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);

    std::cout << "Original Linked List: " << std::endl;
    display(head);
    
    std::cout << "Reversed in Group Linked List: " << std::endl;
    head = ReverseInGroups(head, 4);
    display(head);

    return 0;
}