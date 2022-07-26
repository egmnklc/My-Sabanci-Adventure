#include <iostream>
#include "linkedlistextra.h"

void Print(const LinkedList & list)
{
    list.printList();
}


int main()
{
    // The lastly created object is destructed first.
    LinkedList list1;

    for (int k=0; k < 4; k++)
    {
        list1.addToBeginning(k+1);
    }

    list1.printList();
    LinkedList list2(list1);
    list1.deleteList();
    list2.printList();  // Program crashes here.
    // We create the original values and copy tries to reach to them
    // therefore the program crashes.

}