#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << "Hello thread\n";
}


int main() //* The main thread starts here.
{
    thread aThread(&hello); //* aThread starts (is spawned) here 
    //* Parent thread is "main" 
    //* Child thread is "aThread"

    aThread.join();
    cout << "Bye main\n";

    return 0;
}