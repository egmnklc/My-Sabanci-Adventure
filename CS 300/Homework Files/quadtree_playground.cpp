#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *ne, *nw, *sw, *se;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->ne = nullptr;
    newNode->nw = nullptr;
    newNode->sw = nullptr;
    newNode->se = nullptr;
    return newNode;
}

void printTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << endl;

    printTree(root->ne);
    printTree(root->nw);
    printTree(root->sw);
    printTree(root->se);
}

int main()
{
    // Level 1
    Node *root = createNode(2);
    // Level 2

    printTree(root);
};

string AssignPosition(Node *root, Node *point)
{
    string direction = "null";
    if (point->cityInfo.xCords < root->cityInfo.xCords)
    {
        if (point->cityInfo.yCords < root->cityInfo.yCords)
        {
            direction = "SW";
        }
        else
        {
            direction = "NW";
        }
    }
    else if (point->cityInfo.yCords < root->cityInfo.yCords)
    {
        direction = "SE";
    }
    else
    {
        direction = "NE";
    }
    return direction;
}

City tmpCity;
Node *tmp = newNode(tmpCity);
Node *f = newNode(tmpCity);

for (int i = 0; i < cities.size(); i++)
{
    Node *p = newNode(tmpCity);
    string direction;

    p->cityInfo.name = cities[i].name;
    p->cityInfo.xCords = cities[i].xCords;
    p->cityInfo.yCords = cities[i].yCords;

    if (root == NULL)
    {
        root = p;
    }

    else
    {
        tmp = root;
        while (tmp != NULL)
        {
            f = tmp;
            direction = AssignPosition(f, p);

            if (direction == "SW")
            {
                tmp = f->SW;
            }
            else if (direction == "SE")
            {
                tmp = f->SE;
            }
            else if (direction == "NE")
            {
                tmp = f->NE;
            }
            else if (direction == "NW")
            {
                tmp = f->NW;
            }
        }