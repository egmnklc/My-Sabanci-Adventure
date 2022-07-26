/*

    A constructor which has a parameter of same type.

    ! LinkedList3(list1);

    ! Date today;
    ! Date tomorrow(today);

    LinkedList::LinkedList ( const LinkedList  & copy)
    {
        * copy constructor code comes here
    }

    Date::date ( const Date & d )
    {
        * copy constructor code comes here
    }

    * You're writing a constructor but with a special parameter.
    * The special parameter is a constant referecance parameter.
    *   LinkedList( const LinkedList & ) // Copy constructor
    *       - It does not return anythings, constructors don't return anything. 


    *  class LinkedList
    * {
    *   private: node*head, int size;
    *   public:
    *       LinkedList ();
    *       LinkedList (const LinkedList & copy); // copy constructor
    *       ~ LinkedList (); // destructor
    *       void printList() const;
    *       void addToBeginning(int n);
    *       // more functions here
    * };


    * LinkedList::LinkedList (const LinkedList & copy)
    {
    *    head = copy.head;
    *    size = copy.size;
    }


    LinkedList list2(list1);
    ! We are creating a copy but we aren't copying the dynamic memories for the linked lists.
    ! This type of copy is called SHALLOW COPY. 
    ! Entire list is copied, will not be recreated.
    ! Shallow copy is problematic.

    For every class, there is a default copy constructor that is compiler provided.
    - Simply, copıes the value of each instance variable from one object to anohter.
    
    ! Deep Copy Constructors 

    *  class LinkedList
    * {
    *   private: node*head, int size;
    *   public:
    *       LinkedList ();
    *       LinkedList (const LinkedList & copy); // copy constructor
    *       ~ LinkedList (); // destructor
    *       void printList() const;
    *       void addToBeginning(int n);
    *       void deletList();
    *       node * createClone() const; // generates clone of list and returns clone's head
    *       // It is a helper function
    * };
    * 
    * 
    * Deep copy constructor copies info and assigns them to new memory locations.



*/