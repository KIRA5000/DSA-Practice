#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    char data;
    Node* prev;
    Node* next;

    Node(char ch)
    {
        data = ch;
    }
};

class DLL
{
    Node* head;
    Node* tail;
    map<char, Node*> mp;

    public:

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(char ch)
    {
        if (head == NULL)
        {
            head = new Node(ch);
            tail = head;
        }
        else
        {
            Node* temp = new Node(ch);
            temp->prev = tail;
            tail->next = temp;

            tail = temp;
        }

        mp.insert({ch, tail});
    }

    void del(char ch)
    {
        if (mp[ch] == head)
        {
            auto temp = head;
            head = head->next;
            
            delete temp;
        }
        else if (mp[ch] == tail)
        {
            auto temp = tail;
            tail = tail->prev;
            
            delete temp;
        }
        else
        {
            mp[ch]->prev->next = mp[ch]->next;
            mp[ch]->next->prev = mp[ch]->prev;
            
            delete mp[ch];
        }

        mp.erase(ch);
    }

    Node* getHead()
    {
        return head;
    }

    bool doesExists(char ch)
    {
        return (mp.find(ch) != mp.end());
    }
};

int main()
{
    DLL obj;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    vector<bool> repeated(256, false);

    string out;

    for (int i = 0; i < str.size(); i++)
    {
        if (!repeated[str[i]])
        {
            if (obj.doesExists(str[i]))
            {
                repeated[str[i]] = true;
                obj.del(str[i]);
            }
            else
            {
                obj.insert(str[i]);
            }
        }

        auto head = obj.getHead();

        if (head == NULL)
        {
            out += "#";
        }
        else
        {
            out += head->data;
        }
    }

    cout << "Your output string is: " << out << endl;

    return 0;
}