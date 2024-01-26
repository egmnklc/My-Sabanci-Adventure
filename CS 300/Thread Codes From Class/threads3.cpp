#include <iostream>
#include <thread>
using namespace std;

void count(int firstValue) 
{
	int i;
	for (i=0; i<90; i++)
		cout << firstValue++ <<		"\n";
}

int main() 
{
	thread aThread;
	thread bThread;
	aThread = thread(&count, 1);
	bThread = thread(&count, 1001);

	int i;
	for (i=0; i<90; i++)
		cout << "Hi  main\n";

	aThread.join();
	bThread.join();

	cout << "Bye  main\n";
	return 0; 
}