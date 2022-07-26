#include <iostream>
#include "DynIntStack.h"

using namespace std;

DynIntStack::DynIntStack()
{
    top = NULL;
}

void DynIntStack::push (int num)
{
    StackNode * newNode;
    // Allocate a new node and store num in it.
    newNode = new StackNode;
    newNode->value = num;

    // Make newNode the first node
    // If there are no nodes in the list:
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }

    // If newNode is not the first node
    // Insert newNode before top
    else
    {
        newNode->next = top; // New node points to old head
        top = newNode; // Old head is set equal to new head
    }
}

void DynIntStack::pop (int & num)
{
    StackNode *temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    // Pops the value of at the top of the stack off,
    // and copies it into the variable passed as an argument.
    else
    {
        num = top->value; // Num is set to the integer value of top.
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool DynIntStack::isEmpty(void)
{
    return top == NULL;
}