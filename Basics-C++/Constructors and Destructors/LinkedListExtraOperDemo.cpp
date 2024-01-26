#include <iostream>
#include <string>
#include "LinkedListExtraOper.h"

using namespace std;



int main()
{
    LinkedList list1, list3;

    for (int k = 0; k < 4; k++)
    {
        list1.addToBeginning(k+1);
    }
    cout << "list1 contains:\n";
    list1.printList();

    LinkedList list2(list1); 
    cout << "list2 is created from list1 using copy constructor \n";

    list3 = list1;
    cout << "list1 is assigned to list3\n";

    cout << "\nlist2 contains:\n";
    list2.printList();

    cout << "\nlist3 contains:\n";
    list3.printList();

    list1.addToBeginning(100);
    list1.addToBeginning(50);
    list1.printList();

    list2 = list1; // Same as list2.operator = (list1)
    cout << "list1 is assigned to list2\nlist2 contains:\n";
    list2.printList();

    cout << "list2 is assigned to itself\n";
    cout << "list2 contains:\n";

    list2 = list2; // try this also after deleting (this != &rhs) at operator definition.
    list2.printList();

    return 0;
}

