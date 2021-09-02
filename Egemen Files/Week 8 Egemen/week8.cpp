#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string word, filename;
    int count = 0;
    ifstream input;

    cout << "Enter a filename with extension: "; cin >> filename;
    
    input.open(filename.c_str());
    
    if (input.fail())
    {
        cout << "File does not exist." << endl;
    }

    else
    {
        while (input >> word)
        {
            count++;
        }
    }
    
    cout << "There are " << count << " many words." << endl;
    input.close();

    return count;
}