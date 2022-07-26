struct StackNode
{
    int value;
    StackNode *next;
};

class DynIntStack
{
    private:
        StackNode * top; 
        // Instead of head, we're using top, last element points to NULL
        //  !- Because of the definition of stack.
        //   !- Whenever you pop something, you remove the head element.

    public:
        DynIntStack (void); 
        // Default constructor with no parameters, we don't define size.
        // It just creates an empty stack,
        //  Empty stack means having top equal to NULL.
        void push (int);
        // Adds a new node and makes it head, pointing to the old head.
        void pop (int &);
        bool isEmpty (void);
};