/*

    * When you apply a member function to an object, 
    * - Say calling member function func object obj
    *    obj.func()
    * 
    * The program invisibly executes
    * this = & obj;
    * before the function starts
    * 
    * this is a pointer to the object on which the function
    * is being executed, in our example, obj.
    * 
    * Therefore, the function can use *this to refer to the 
    * current object on which the function is executing.
    * 
*/