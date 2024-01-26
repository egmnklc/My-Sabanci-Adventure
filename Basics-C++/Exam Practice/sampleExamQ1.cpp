#include <iostream>
#include <string>
#include "strutils.h"


int unique(int number)
{
    int count = 0;
    string sNum = itoa(number);

    for (int i = 0; i < sNum.length(); i++)
    {
        if (sNum.find(sNum[i]) == sNum.rfind(sNum[i]))
        {
            cout << sNum[i] << " ";
            count++;
        }
    }
    cout << endl;
    return count;
}

int main()
{   
    int number;
    cin >> number;
    cout << unique(number) << endl;
}

