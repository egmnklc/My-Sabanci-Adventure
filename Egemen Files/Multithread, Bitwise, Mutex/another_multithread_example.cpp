#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        cout << "Hello thread  ";
    }

}


int main() //* The main thread starts here.
{
    thread aThread(&hello);
    int i;
    for (i = 0; i < 100; i++)
    {
        cout << "Hi main  ";
    }

    aThread.join();
    cout << "Bye main\n";

    return 0;
}