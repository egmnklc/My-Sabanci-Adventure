#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

mutex coutMutex;

void hello(int order)
{
	//try with and without lock/unlock to see the difference in the output format
	coutMutex.lock();
	cout << order << " " << this_thread::get_id() << endl;
	coutMutex.unlock();
}

int main()
{
  int i;
  thread threads[20];
  for (i=0; i < 20; i++)
  {
      threads[i] = (thread(&hello, i));
  }

  for (i=0; i < 20; i++)
  {
      threads[i].join();
  }

  return 0;
}
