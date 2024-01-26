#include <iostream>
#include <string>
#include "strutils.h"

int main()
{
    string word, sentence, dups;   
    char most;  

    do
    {
        cout << "Please enter a word: "; cin >> word; ToLower(word);
        sentence += word + " ";

    }   while(word != "end");

    sentence = sentence.substr(0, sentence.length()-4);
    
    cout << "Sentence is: " << sentence << endl;

    int count, maxcount;
    
    for (int i = 0; i < sentence.length(); i++)
    {
        count = 0;
        for (int j = 0; j < sentence.length(); j++)
        {
            if (sentence.at(i) != ' ' && sentence.at(i) == sentence.at(j))
            {
                count++;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            most = sentence.at(i);
        }
    }
    cout << "Most ocurring character is: " << most << endl;

    return 0;
}