#include <iostream>

using namespace std;

int f (int n)
{
    int b;
    if (n == 6)
    {
        return 3;
    }
    b = f(n/6);
    return (b * b * b * b);
}

int main()
{
    cout << f(6) << endl;
    cout << f(6*6) << endl;
    cout << f(6*6*6) << endl;
    return 0;   
}