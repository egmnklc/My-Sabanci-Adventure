#include <iostream>
#include <string>

using namespace std;

string & f2 (string * p) 
// If this has const in front of it, we won't be able to modify 
// the returned value.
{
    *p = "CS204"; // Changes the content in memory location.
    return *p;  // and return it (memory allocated before calling)
}

// Same task above but for ints.
int & f2 (int * p)
{
    *p = 204;
    return *p;
}


int main()
{
    string * sp = new string();
    f2(sp)[2] = 'a'; // Works as intended only if f2 returns reference (non const)
    cout << *sp << endl;
    
    int * ip = new int;
    f2(ip) += 250;
    cout << *ip << endl;

    return 0;
}