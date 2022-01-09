#include <iostream>
#include <vector>
#include <climits>

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
    }
};

Node* mergeKLists(Node* head[], int n)
{
    Node* newHead = NULL;
    Node* curr = NULL;

    while (true)
    {
        int index = -1;
        int min = INT_MAX;
        Node* smallestNode = NULL;

        for (int i = 0; i < n; i++)
        {
            if ((head[i]) && (head[i]->data < min))
            {
                index = i;
                min = head[i]->data;
                smallestNode = head[i];
            }
        }

        if (smallestNode == NULL)
        {
            break;
        }

        head[index] = head[index]->next;

        if (newHead == NULL)
        {
            std::cout << "NewHead = " << smallestNode->data << std::endl;
            newHead = smallestNode;
            smallestNode->next = NULL;
            curr = newHead;
        }
        else
        {
            std::cout << "NewHead = " << smallestNode->data << std::endl;
            curr->next = smallestNode;
            smallestNode->next = NULL;
            curr = smallestNode;
        }
    }

    return newHead;
}

void printList(Node* head)
{
    auto curr = head;

    while(curr)
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main()
{
    // Number of linked lists
    int k = 3;
 
    // Number of elements in each list
    int n = 4;
 
    // an array of pointers storing the
    // head nodes of the linked lists
    Node* arr[3];
 
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);
 
    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);
 
    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k);
 
    printList(head);
 
    return 0;
}