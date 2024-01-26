#include <iostream>

using namespace std;

struct Node
{
    int data, rcount, lcount;
    Node *right;
    Node *left;
    Node(int data = -1, Node *right = nullptr, Node *left = nullptr, int rvalue = -1, int lvalue = -1)
    {
        this->data = data;
        this->right = right;
        this->left = left;
        this->rcount = rvalue;
        this->lcount = lvalue;
    }
};

Node *createNode(int value)
{
    Node *newNode = new Node(value);
    return newNode;
}

bool isPBT(int count)
{
    count += 1;
    while (count % 2 == 0)
    {
        count = count / 2;
    }

    if (count == 1)
    {
        return true;
    }

    return false;
}

Node* insertNode(struct Node* root,
                       int data)
{
     
    // Condition when root is NULL
    if (root == NULL) {
        struct Node* n = new Node(data);
        return n;
    }
     
    // Condition when count of left sub-tree
    // nodes is equal to the count
    // of right sub-tree nodes
    if (root->rcount == root->lcount) {
        root->left = insertNode(root->left, data);
        root->lcount += 1;
    }
     
    // Condition when count of left sub-tree
    // nodes is greater than
    // the right sub-tree nodes
    else if (root->rcount < root->lcount) {
         
        // Condition when left Sub-tree is
        // Perfect Binary Tree then insertNode
        // in right sub-tree.
        if (isPBT(root->lcount)) {
            root->right = insertNode(root->right, data);
            root->rcount += 1;
        }
         
        // If Left Sub-tree is not Perfect
        // Binary Tree then insertNode in left sub-tree
        else {
            root->left = insertNode(root->left, data);
            root->lcount += 1;
        }
    }
    return root;
}
 

void printNode(Node *rootNode)
{
    if (rootNode != nullptr)
    {
        cout << rootNode->data << endl;
        printNode(rootNode->right);
        printNode(rootNode->left);
    }
    return;
}

void inOrder(Node* rootNode)
{
    if (rootNode != NULL) 
    {
        inOrder(rootNode->left);
        cout << rootNode->data << " ";
        inOrder(rootNode->right);
    }
}
 

int main()
{
    // Node *root = createNode(1);
    // Node *child1 = createNode(2);
    // Node *child2 = createNode(3);
    // Node *child3 = createNode(4);

    // root->right = child2;
    // root->left = child1;

    // root->left->left = child3;

    // printNode(root);

    // insertNode(7, root);
    // insertNode(4, root);
    // insertNode(3, root);

    // cout << "New Node is: " << endl;
    // printNode(root);

    int arr[] = {8, 6, 7, 12, 5, 1, 9};
    int size = sizeof(arr) / sizeof(int); // Size of the array is the size of an integer in memory times the number of elements in it.
    cout << size << endl;
    Node * rootNode = NULL;

    for (int i = 0; i < size; i++)
    {
        rootNode = insertNode(rootNode, arr[i]);
    }

    // printNode(rootNode);
    inOrder(rootNode);
    return 0;
}