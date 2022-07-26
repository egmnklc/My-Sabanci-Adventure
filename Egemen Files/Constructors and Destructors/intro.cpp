/*

    ! Constructors
    *- Constructors have the same name as the class.
    *- Constructors do not return any values.
    *- Constructors are invoked first when an object is created.
    *Any memory allocations and initializations for the class 
    *data members done in the constructor.

    *- Constructors may or may not take parameters.
    *-     A constructor with no parameter is called default constructor

    Node::Node(int num = 0, Node * ptr = NULL) // These parameters are defined
    as default parameters.
    {
         code here
    }

    Node myNode; // This creates a node with int num = 0 and pointing to NULL.
    Node myOtherNode (10); // This creates a node with int num = 10 and pointing to NULL.
    Node * ptr = new Node(10, ptr) // This creates a node with int num = 10 and 
    pointing to ptr.
    Node * ptr2 = new Node(10, ptr); // This creates a node with int num=10, pointing to ptr.
    Node * ptr3 = new Node(100); // This creates a node with int num=100 and pointing to NULL.


    ! What if we don't write any constructor?
        * Compiler attempst to generate a default constructor.
        * Not visible to the programmer
        * When an object is created, this default constructor is invoked automatically.
        * This compiler-generated constructor allocates memory for the class private members
        *   and calls default constructor on them if applicable.
        *   - Dynamic memory allocations are not performed automatically.
    

    ! Initializer list Syntax in Constructors

    *- Syntax
    *    ConstructorHeader : privateData(value), privateData(value), ...
    *    {
    *       // Other constructor code comes here, executes afeter assigning
    *       // values in the initializer list
    *    }
    * 
    * //Default Constructor
    *   Point::Point() : x(0), y(0) {}
    * 
    * // Alternative default constructor implementation
    *   Point::Point() : x(0)
    * {
    *   y = 0
    * }
    * 
    * // Constructor with parameters
    * Point::Point(int xx, int yy) : x(xx), y(yy) {}
    

    ! Destructors
    * - Each  class should also have a destructor, which should take care of 
    * returning any remaining dynamically allocated memory back to heap.
    * 
    * The destructor has name ~classname
    *   - No parameters, no return value
    *   - This is in the class definition under public
    * 
    * class LinkedList
    * {
    *   private:
    *       node * head; 
    *       int size;
    *   public:
    *   LinkedList();
    *   ~LinkedList(); // This is the destructor
    *   void printList();
    *   .......
    * }
    * 
    *   - Destructor doesn't return anything and does not have any parameters.
    *   - You need a destructor when you dynamically allocate memory, 
    *   otherwise you don't need it.
    * 
    *  LinkedList::~LinkedList()
    * {
    *   node * ptr = head;
    *   while (ptr != NULL)
    *   {
    *       node * temp = ptr->next;
    *       delete ptr;
    *       ptr = temp;
    *   }
    * }
    * 
    ! The destrictor is called automatically when the object goes out of scope.
    ! What happens when you dont't write a destructor.
    ! - If you don't write it yourself, compiler implicitly provides a destructor to you,
    ! which is empty.

*/