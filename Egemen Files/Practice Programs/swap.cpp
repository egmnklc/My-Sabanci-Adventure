#include <iostream>
using namespace std;

void Swap (int & a, int & b)
{
    int temp = b;
    b = a;
    a = temp;
}

void swapWTwo (int & c, int & d)
{
    c = c + d;
    d = c - d;
    c = c - d;
}

int main()
{

    int num1, num2;
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;
    cout << "Value before change for num1 " << num1 << " and num2: " << num2 << endl;
    Swap(num1, num2);
    cout << "Value after change for num1 " << num1 << " and num2: " << num2 << endl;
    cout << "Value before change for num1 " << num1 << " and num2: " << num2 << endl;
    swapWTwo(num1, num2);
    cout << "Swap With Two Parameters: " << num1 << " " << num2;
}

