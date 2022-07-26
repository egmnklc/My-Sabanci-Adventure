#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/*
    * - Mutex is an abstract data structure that can be used to control the use of commonly shared variables when we have multithreading.
    * - If we have multiple threads working on the same data type or object, then we can use mutex to control and make sure that threads
    *   one of the threads is will wait until the one who is working, finished its task.
    * 
    * - We can lock or unlock it. 
    * 
    *  - If a thread locks the mutex, another thread cannot work on that particular value unless the mutex value is unlocked.
    * 
    * - When you create the mutex, initially it is in the uncloked form and you cannot unclock what is unlocked. 
    * - Only the thread that locked the mutex can unlock it.
    * 
*/

//! Before doing any check over the queue data structure, we need to lock the data structure because 

int value = 0; 
mutex myMutex; //* Initially, this is unlocked.

void increment(void)
{
    for (int i = 0; i < 1000000; i++)
    {
        //* Say we have two threads, first thread locks the mutex, increments its value. Since the mutex is locked, it isn't possible for another thread to increment it 
        //*     during a context swhitch.
        myMutex.lock();
        value++;
        myMutex.unlock();
        //* Thread locks value, increments, releases.
    }
}


int main()
{

    return 0;
}