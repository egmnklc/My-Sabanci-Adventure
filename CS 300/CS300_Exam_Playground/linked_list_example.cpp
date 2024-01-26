#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node(int d = -1, Node *n = nullptr)
        {
            data = d;
            next = n;
        }

        ~Node()
        {
            delete next;
        }
};

int main()
{
    Node *head = new Node();
    head->data = 0;

    Node *a = new Node(1, nullptr);
    head->next = a;
    cout << head->data << endl
         << a->data << endl
         << head->next->data << endl
         << head->next->next << endl;

    delete head, a;
    return 0;
}