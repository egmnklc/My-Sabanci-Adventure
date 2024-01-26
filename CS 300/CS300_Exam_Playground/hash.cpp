#include <iostream>

using namespace std;

int hash(const string & key, const int tableSize)
{
    int sum = 0;

    for (int i =0; i < key.length(); i++)
    {
        sum += key[i];  
    }

    return (sum % tableSize);
}


int main()
{

    return 0;
}