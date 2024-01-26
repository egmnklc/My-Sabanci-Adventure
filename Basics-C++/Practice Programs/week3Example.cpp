#include <iostream>
using namespace std;
int number;
int main()
{
    cout << "Type in a number: ";
    cin >> number;
    if (0 <= number && number <= 100)
    {
        cout << number << " is in range [0,100]" << endl;
    }   
    else
    {
        cout << number << " is not in range [0,100]" << endl;
    }
    return 0;
}