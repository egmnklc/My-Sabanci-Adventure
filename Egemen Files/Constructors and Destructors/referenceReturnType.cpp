/*

    * Sometimes we use reference return values such as
    *   const ClassName & FunctionName (parameters)
    *   ClassName & FunctionName (Parameters)
    * 
    * - Fpr example, operatpr += or ClockTime class and 
    * operator = LinkedList class, Operator << of ClockTime class
    * 
    * What is the difference between these and using just the 
    * ClassName as the return type (value return)?
    * 
    * ClassName FunctionName (Parameters)
    * Using just the class name (value return), generates a 
    * copy of the value when returning.
    *   - This invokes copy constructor (user defined or, if it
    * does not exist, default one.)
    *   - This is risky if not implemented (shallow copy problem).
    *   - And it may be inefficient to call the copy constructor
    *   for this purpose, if you are returning an existing object.
    * 
    * Sometimes the object to be returned has already been defined
    * outside of the function (or dynamically allocated within the function).
    *   - In such a case, we can directly return that object without
    *   a copy opearation.
    *       - This is called reference return 
    *       - The mechanisms with & does this.
    !   - Be careful, do not return a local variable using this method.
    *       - Local variable gets lost after the function
    *       - Probably your program crashes
    * 
    * What is the effect of using const here?
    *   - Not much; actually a very defensive programming technique.
    *   - If const is used, the compiler does now allow you to change 
    *   function's returning value in the caller function (after returning)
    *   - This is applied with examples in refreturn.cpp.
*/