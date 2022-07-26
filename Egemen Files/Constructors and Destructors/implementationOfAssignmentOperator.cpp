// Prototype added to the class decleration (LinkedListExtraOper.h)

/* 
class LinkedList 
{
    private: 
        node*head;
        int size;
    public: 
        LinkedList ();
        LinkedList (const LinkedList &); // Copy constructor
        ~LinkedList (); // destructor
        void printList () const;
        void addToBeginning(int n);
        void deleteList ();
        const LinkedList &operator=(const LinkedList & rhs);
        node * createClone () const;
}; 

const LinkedList & LinkedList::operator=(const LinkedList & rhs)
{
    if (this != &rhs)
    {
        deleteList();
        head = rhs.createClone();
        size = rhs.size;
    }
    return *this;
}
*/

