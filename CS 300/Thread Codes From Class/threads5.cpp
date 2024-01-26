#include <iostream>
#include <thread>
using namespace std;

void countmore(int firstValue) 
{
	int i;
	for (i=0; i<9000; i++)
		cout << firstValue++ << "   ";
}

void count(int firstValue) 
{
	int i;
	for (i=0; i<900; i++)
		cout << firstValue++ << "   ";
}

int main() 
{
	thread aThread;
	thread bThread;
	aThread = thread(&countmore,1);
	aThread.detach();
	bThread = thread(&count, 10001);

	int i;
	for (i=0; i<9; i++)
		cout << "Hi  main\n";

	bThread.join();

	cout << "Bye  main\n";
	return 0; 
}