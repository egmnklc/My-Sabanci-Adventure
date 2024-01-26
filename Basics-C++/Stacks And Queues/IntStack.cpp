#include <iostream>
#include "IntStack.h"

using namespace std;

// A stack is a data structure that stores and
// retrieves items in a last-in-firs-out (LIFO)
// manner.

//  -------------------------------------------------------
//* Last in, first out. First element is the most
//* bottom one.
//  -------------------------------------------------------

//  -------------------------------------------------------
//* Stacks are used to store functions' return addresses,
//* local variables, etc.
//  -------------------------------------------------------

//  -------------------------------------------------------
//* Static Stacks: Fixed size, can be implemented via an array
//* Dynamic Stacks: Grows in size, implemented via linked list.
//  -------------------------------------------------------

//  -------------------------------------------------------
//* Two main stack operations.
//* - Push: adds element to the top of the stack
//* - Pop: Retrieves and removes from the top of the stack
// !We need to keep the index of the top element.
//  -------------------------------------------------------

//  -------------------------------------------------------
//* Useful stack functions:
//* - isFull: Returns true if the stack is full, else returns false
//* - isEmpty: Returns true if stack is empty, else returns false
//  -------------------------------------------------------

/*
    *Static Integer Stack: Stack with integer elements.
    
    *top: Stored as a private member, it is an integer value
    that stores the index of top stack.

    *stackSize: Max # of elements to be put in a stack, integer.
    
    *stackArray: A pointer to int, when consturctor is executed,
    it uses stackArray to dynamically allocate an array for storage.
    In the consturction, we'll use new in order to allocate memory.

    -------------------------------------------------------

    ! The IntStack Class

    * consturctor: Initializes top to -1, to create an empty stack.
    Class constructor accepts an integer as an argument, which
    specifies the size of the stack. An integer array of this size
    is dynamically allocated, and assigned to StackArray. Also the 
    top variable is initialized to -1.

    * push: explained

    * pop: explained

    ! In order to check for emptiness, top should be -1. If the value
    ! of isEmpty is = -1, then stack is empty.

    ! isFull returns true if stack is full, returns false otherwise.
    ! The stack is full when top is equal to stackSize-1.
*/

/*
    ! Dynamic Stacks 
    * A dynamic stack is built on a linked list instead of an array.
        *- No need to specify the size of the stack 
        *- A dynamic stack simply starts as an empty linked list,
        and then expands by one node each time a value is pushed.
            - When a value if popped, its memory is freed.
        *- A dynamic stack will never be full as long as the system
        has enough free memory.
*/
IntStack::IntStack (int size) // size is given as parameter
{
    stackArray = new int[size]; 
    // Allocate size integers dinamically and the returning pointer
    // will be stored in stackArray pointer, which is the private
    // data member. 
    stackSize = size; 
    // Private data member stackSize set to size
    top = -1;
    // Initialize top private class member to -1, meaning stack is empty.
}

void IntStack::push (int num)
{
    if (isFull()) 
    // If isFull true, display full message.
    {
        cout << "The stack is full.\n";
    }

    else
    // If stack is not full, increment top by 1,
    // set stackArray[top] to num, 
    // set top'th element of stackArray to num.
    {
        top++;
        stackArray[top] = num;
    }   
}

void IntStack::pop (int &num)
{
    // Pops the value at the top of the stack off,
    // copies it into the variable passed as an argument.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }

    else 
    // If stack is not full, we get the top'th element and
    // store it in the num element.
    // After that, we decrement top.
    {
        num = stackArray[top];
        top--;
    }

}

bool IntStack::isFull(void)
{
    bool status;

    if (top == stackSize - 1) 
    // Assume top is 5 and stackSize is 6,
    // then the top'th indexed element will be the 6th element.
    {
        status = true;
    }
    
    else
    {
        status = false;
    }

    return status;
}

bool IntStack::isEmpty(void)
{
    bool status;
    // If top value = -1, then it means the stack is empty.
    if (top == -1)
    {
        status = true;
    }
    
    else
    {
        status = false;
    }

    return status;
}