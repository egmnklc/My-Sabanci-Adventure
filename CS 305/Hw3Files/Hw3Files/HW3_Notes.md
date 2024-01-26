# CS 305 Tutorial 4
The first text file includes data to assign numbers to variables. Second text file has sum the numbers using the variable names such as x = y+z. In text3, we have a case where we have not defined the variable y and try to assign it to variable x. Variable y should be undefined for such a case. Additionally, integer assignment to a variable is not allowed. For example we cannot assign 5 to z, namely 5 = z, this action is not allowed.

### Now, about the scanner file:
- The `.tab` file is important for the token recognition. 
- The `.h` file is where we define our structs. It's called a header file. Structs help us to keep more than one attribute within a value.
- It has `=` and `+` operators and they're assigned to their actual functionalites. We are taking `[0-9]+` as a string.
  - There's a **built in function called strcpy()**, coming from CString library. It copies from yytext() pointer to a result pointer. 
- We accept upper/lower case letters as well.
- New lines are counted and tab spacings are ignored.
- **yylval()** is a global variable used for passing the semantic value associated with a token from the lexer (lexical analyzer) to the parser (semantic analyser). 

### About tutorial4.h
It has our structs defined. There are 3 struct types: Numbers, Identifiers, and Expressions. 

___Note:___ `tab.h` file is created by **Bison**.

## Attribute Grammar 
In tutorial4.y file, sumExpr is the actual function that makes the summation. Assign function is making the assignment. checkIdentifier checks the identifier if it has been defined previously. We have expressionSize and errorSize to keep track of them, because we want to list them.

Now, for text1.txt, we define a variable and then re-define it and assign it to another variable's value by value. That's why we are keeping track of expressions as a list, as it helps to remember what was the value of the variable we're making an assignment to, (x = y, y was 5). 

** Is a pointer of pointers, and that is how we keep a dynamic list in C. We have a pointer of pointers, namely a dynamic array for both expressions and the errors.

The %union keyword attaches structures to tokens.

The `%token` expressions are attaching themselves to the definitions given in the flex file.
- So when a token is returned to Bison, when the token is recognized by flex (the scanner) and returned, we already have these values defined in the flex's scanning process. 

We have `%type` keyword. It is used for non-terminals and used when we want to attach a data structure to a non-terminal.
