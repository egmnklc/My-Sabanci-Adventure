#include <iostream>
#include <thread>
using namespace std;

void hello() 
{
	int i;
	for (i=0; i<100; i++)
		cout << "Hello thread  ";
}

int main() 
{
	thread aThread(&hello);
	/*Alternative way is to create the thread object first without initializing
		and initialize it later. Thread starts execution once initialized*/
	//thread aThread;   //declaration with no initialization
	//aThread = thread(&hello);  //Initialization of aThread; execution starts now.

	int i;
	for (i=0; i<100; i++)
		cout << "Hi  main  ";
	aThread.join();
	cout << "Bye  main\n";
	return 0; 
}
