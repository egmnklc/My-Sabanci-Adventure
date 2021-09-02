#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;

int main()
{
	string name;

    cout << "Enter your name: "; cin >> name;
    ToUpper(name);
    StripWhite(name);
    cout << name << endl;
    return 0;
}