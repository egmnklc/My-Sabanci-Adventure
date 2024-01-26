#include <iostream>
#include <string>
#include "strutils.h"

/*
    - Hangman hame for two players.
*/

using namespace std;

void startGame(string player_1, string player_2, string word, string secret, bool &continueGame);

void player_2Wins(string player_1, string player_2, string word, string secret, bool &continueGame)
{
    cout << "Congratulations " << player_2 << ", you won!" << endl;
    cout << player_2 << " won the game!" << endl;
    continueGame = false;
    startGame(player_1, player_2, word, secret, continueGame);
}

void player_2Win(string player_1, string player_2, string word, string secret, bool &continueGame)
{
    cout << "The word is: " << secret << endl;
    cout << "Congratulations " << player_2 << ", you won!" << endl;
    cout << player_2 << " won the game!" << endl;
    continueGame = false;
    startGame(player_1, player_2, word, secret, continueGame);
}

bool letterBefore(string guessedLetters, string letterGuess, string word)
{
    if (guessedLetters.rfind(letterGuess) != guessedLetters.find(letterGuess) && guessedLetters.find(letterGuess) != string::npos)
    {
        cout << "Guessed entered before! Try again." << endl;
        cout << "The word is: " << word << endl;
        return true;
    }
    return false;
    
}

bool wordBefore (string guessedWords, string wordGuess)
{  
    if (guessedWords.rfind(wordGuess) != guessedWords.find(wordGuess) && guessedWords.find(wordGuess) != string::npos)
    {
        cout << "Guess entered before! Try again." << endl;
        return true;
    }
    return false;
}

bool inputCheck(string secret)
{
    for (int i =0; i < secret.length(); i++)
    {
        if (secret[i] < 'a' || secret[i] > 'z')
        {
            return false;
        }
    }
    return true;
}

bool wordCheck(string wordGuess){
    for(int g = 0; g < wordGuess.length(); g++)
    {
        if(wordGuess[g] < 'a' || wordGuess[g] > 'z'){
            return false;
        }
    }
    return true;
}

bool secondCheck(string decision)
{
    if (decision.length() > 1 || atoi(decision) < 1 || atoi(decision) > 2)
    {
        return false;
    }
    return true;
}

void hangman(string word, string secret, string &parts, bool &continueGame, string player_2, int &mistake) //guessedLetters ve lettersGuessed ekle buraya
{
    int position = parts.find("-");
    if (parts == "head")
    {
        continueGame = false;
        cout << "You have lost a head! GAME OVER!" << endl;
        cout << player_2 << " lost the game :(" << endl;
    }
    else if (parts.substr(0, position) == "arm")
    {
        cout << "You have lost an " << parts.substr(0, position) << "!" << endl;
        parts = parts.substr(position+1);
        cout << "The word is: " << word << endl;
    }
    else
    {
        if (mistake != 1)
        {
            cout << "You have lost a " << parts.substr(0, position) << "!" << endl;
            parts = parts.substr(position+1);
            cout << "The word is: " << word << endl;
        }
        else if (mistake == 1)
        {
            mistake++;
            cout << "You have no free guess left." << endl;
            cout << "The word is: " << word << endl;
        }
    }
}

void startGame(string player_1, string player_2, string word, string secret, bool &continueGame)
{
    int lives = 6;
    int mistake = 1;
    string decision;
    string parts = "leg-leg-arm-arm-head";
    string guessedLetters;
    string guessedWords;


    while (continueGame == true && lives > 0)
    {
        bool firstMistake = false;
        cout << player_2 << " do you want to guess the word(1) or guess a letter(2)? "; cin >> decision;

        if (secondCheck(decision) == true)
        
        {
            if (atoi(decision) == 1) // Word guess
            {
               string wordGuess = "";
               ToLower(wordGuess);
               cout << "Your guess: "; cin >> wordGuess;
               ToLower(wordGuess);
               guessedWords += wordGuess;
               if (wordCheck(wordGuess) == true){
                   
                  if (wordBefore(guessedWords, wordGuess) != true)
                   {
                    if (wordGuess != secret)
                    {
                        hangman(word, secret, parts, continueGame, player_2, mistake);
                        lives--;
                    }
                    else if (wordGuess == secret)
                    {
                        player_2Win(player_1, player_2, word, secret, continueGame);
                    }
                   else if (wordBefore(guessedWords, wordGuess) == true)
                   {
                       wordBefore(guessedWords, wordGuess);
                   }
                }
                
               }
               else if (wordCheck(wordGuess) != true)
               {
                    cout << "Invalid entry! Try again." << endl;
                    cout << "The word is: " << word << endl;
               }
            }

            else if (atoi(decision) == 2) // Letter guess
            {
                string letterGuess = "";

                cout << "Your guess: "; cin >> letterGuess;
                ToLower(letterGuess);
                if (letterGuess.length() == 1 && letterGuess[0] >= 'a' && letterGuess[0] <= 'z')
                {
                    guessedLetters += letterGuess;
                }
                if (letterBefore(guessedLetters, letterGuess, word) == false)
                {
                    if (secret.find(letterGuess) != string::npos && letterGuess.length() == 1)
                    {
                        ToLower(letterGuess); 
                        for(int k = 0; k < secret.length(); k++)
                        {
                            if (secret[k] == letterGuess[0])
                            {
                                word[k] = secret[k];
                            }
                        }
                        cout << "The word is: " << word << endl;

                    }
                    else if(letterGuess.length() > 1 || letterGuess[0] < 'a' || letterGuess[0] > 'z')
                    {
                        cout << "Invalid entry! Try again." << endl;
                        cout << "The word is: " << word << endl;
                    }
                    else
                    {
                        hangman(word, secret, parts, continueGame, player_2, mistake);
                        lives--;
                    }
                }
            }
            if (word == secret)
            {
                player_2Wins(player_1, player_2, word, secret, continueGame);
            }
        }
        else if (secondCheck(decision) == false)
        {
            cout << "Invalid option!" << endl;
            cout << "The word is " << word << endl;
        }
    }
}

void displayWord(string player_1, string player_2, string word, string secret, bool continueGame)
{
    for (int j = 0; j < secret.length(); j++)
    {
        word += "-";
    }
    cout << "The word is: " << word << endl;
    startGame(player_1, player_2, word, secret, continueGame);
}



int main()
{
    string player_1, player_2, secret;
    bool continueGame = true;
    string word = "";
    

    cout << "Welcome to the HANGMAN GAME" << endl;
    cout << "---------------------------" << endl;
    cout << "Player one, please enter your name: "; cin >> player_1;
    cout << "Player two, please enter your name: "; cin >> player_2;
    cout << "OK " << player_1 << " and " << player_2 << ". Let's start the game!" << endl; 
    cout << player_1 << ", please input the word you want " << player_2 << " to guess: "; cin >> secret; 
    ToLower(secret);
    
    if (inputCheck(secret) == true)
    {
        cout << player_2 << ", you have one free guess, after that you will lose limbs!" << endl;
        displayWord(player_1, player_2, word, secret, continueGame);
    }

    else if (inputCheck(secret) == false)
    {

        while(inputCheck(secret) != true)
        {
            cout << "Invalid entry! Try again." << endl;
            cout << player_1 << ", please input the word you want " << player_2 << " to guess: "; cin >> secret;
            ToLower(secret);
            inputCheck(secret);
        }

        if (inputCheck(secret) == true)
        {
            cout << player_2 << ", you have one free guess, after that you will lose limbs!" << endl;

            displayWord(player_1, player_2, word, secret, continueGame);

        }
    }

    return 0;
}