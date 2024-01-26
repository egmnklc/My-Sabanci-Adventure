#include <iostream>

using namespace std;

// template <class Object>
// class ListNode 
// {
//     //* Object() calls the default constructor of the datatype, in other words the constructor of the class.
//     ListNode(const Object & theElement = Object(), ListNode * n = NULL) :element(theElement, next(n)); 

//     Object element;
//     ListNode *next;
    
//     friend class List <Object>;
//     friend class ListItr <Object>;
// };


template <class Object>

class List {
    public:
        List (); //* Default constructor
        List (const List & rhs);
        ~List(); //* Destructor

        bool isEmpty () const;  //* Return type is boolean, and function won't change anything, that's why const is at the end.
        void makeEmpty ();
        ListItr <Object> zeroth() const;
        ListItr <Object> first() const;
        ListItr <Object> find (const Object & x) const;
        ListItr <Object> findPrevious (const Object & x) const;

        void insert (const Object & x, const ListItr<Object> & p);
        void remove (const Object & x);

    private:
        ListNode<Object> * header;
};  



template <class Object>
List<Object>::List()
{
    header = new ListNode<Object>;
}

template <class Object>
bool List<Object>::isEmpty() const
{
    return header->next == NULL;
}

template <class Object>
//! Object is the template datatype of the element to be inserted
//! ListItr<Object> is the datatype of the linked list to be worked on (& is added to modify the linked list)
void List<Object>::insert(const Object & x, const ListItr<Object> & p) const
{
    if (p.current != NULL)
    {
        p.current->next = new ListNode<Object> (x, p.current->next);
    }
}

template <class Object>
ListItr<Object>::find(const Object & x) const 
{
    ListNode<Object> *itr = header->next;

    while (itr != NULL && itr->element != x)
    {
        itr = itr->next;
    }

    return ListNode<Object>(itr);
}

int main()
{

    return 0;
}