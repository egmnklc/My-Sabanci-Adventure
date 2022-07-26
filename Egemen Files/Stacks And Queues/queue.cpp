/*

    Like a sack, a queue is a data structure that holds a sequence of elements
    *- A queue provides access to its elements first-in-first-out (FIFO) order
    *- The elements in a queue are processed like customers standing in  a
    *- grocery line. First customer is the first one served.


    ! Static and Dynamic Queues
    *- Just as stacks, queues are implemented as arrays or linked lists.
    *- Dynamic queues offer the same advantages over static queues that dynamic stacks
    *  offer over static stacks.
    
    ! Queue Operations
    *- Think of queues as having a front and a rear.
        *- rear: Position where the elements are added.
        *- Front: Position from which the elements are removed. 
    *- The two primary queue operations are enqueing and dequeing.
    *- To enqueue: Insert an element at the rear (position of where elements are added)
    *  of a queue.
    *- To dequeue: Remove an element from the front of a queue.

    *- All the elements will be shifted towards front after a dequeing.

    ! To prevent inefficiencies

    *- Let front index move as elements are removed.
*/