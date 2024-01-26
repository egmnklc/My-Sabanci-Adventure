//! Strings code from pptx

#include <iostream>

using namespace std;

char * my_strcpy ( char * destination, char * source)
{
    //! '\0' is the null terminator.

    char *p = destination;
    
    while (*source != '\0')
    {
        *p++ = *source++; //* destination[i] = source[i]
    }

    *p = '\0'; //* insert the final marker
    return destination;
}

int main()
{
    char Name[6] = "Hello"; //* It auto-initialises all values of Name to '\000', which is the null terminator.
    char *p = Name;

    char newName[8];
    char *q;
    q = my_strcpy(newName, p); //* q now has the same value with Name. Since there's no operation on it, it points to the first index of it.
    
    cout << *q << endl;
    return 0;
}