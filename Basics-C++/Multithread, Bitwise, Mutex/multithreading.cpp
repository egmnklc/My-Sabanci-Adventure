#include <iostream>
#include <thread>
#include <sstream>

using namespace std;


    /*
    *   Context Switching
    *   - Processes are switched in various time intervals so that the CPU can handle the load. Time intervals may vary.
    *   - Deciding how long a process will work is decided by the OS.
    * 
    *   Threads
    *   - CPU does not execute processes but threads.
    *   - Processes are composed of threads and each process has at least one thread.
    *   - Thread is the path of execution in a process. It's where the execution begins. Main function is named as main thread.
    *   - Threads are similar to processes and have their specific resources so that they could be executed independently. They have 
    *   their own runtime stack, memory space and progra counter to keep track of them during execution. Threads that are associated with
    *   the same process share the resources of the process. That's why it is easier to write a multithread program at the thread level.
    *   - Under a process, you can have several threads.
    *   
    *   Why do we need multithreading? 
    *   - Main reason is to achieve concurrency (es zamanlilik).
    *   - For example, while waiting for an input from user, you might need to do some calculations.
    * 
    *   - Every C++ program has at least one thread: A thread running main() started by the C++ runtime.
    *       - We call it the main thread.
    *   - Main thread can spawn additional threads that have another function as the entry point.
    *       - Entry point is the starting function of the thread.
    *   
    *   - All these threads run concurrently with each other:
    *       - Via a schedule organized by the OS; programmer cannot directly control this schedule.
    * 
    *   - If one thread handles all the work, it is called sequential execution.
    * 
    !   PARENT THREAD WAITS FOR THE CHILD THREAD   !
    */

void printHello(int num)
{
    for (int i = 0; i < 50; i++)
    {
        ostringstream os;
        os << "Hello World..." << num << endl;
        cout << os.str();
        num++;
    }
}

int main()
{
    //* At the beginning of our program, we will have two threads. The first one will be the main thread and second will be aThread.
    
    //! These threads will run concurrently and I cannot make sure whether i'll see helloWorld or hi first. Because they are going to be
    //! running concurrently and we have no control over the execution schedule.
    //! If you cout hi first, you will for sure see hi first and then helloWorld.
    //!

    //* Parameter to the constructor is the address of a funtion which is going to be the path of execution of this particular thread.
    /*
    *   When you provide the thread, the path of execution, it starts the execution right away.
    *   
    */

/*
    cout << "hi\n";
    
    thread aThread, bThread;

    aThread = thread (&printHello, 50);
    bThread = thread (&printHello, 50);
        

    //* Join means that we're making the thread to wait until the child thread is done. 
    //* Join maeans after the thread finishes its tasks, the main thread will display bye.
    //* Join blocks the execution of the parent thread.
    for (int i = 0; i < 50; i++)
    {
        cout << "hi\n";
    }
    
    for (int i = 0; i < 50; i++)
        cout << "bye\n";
    //* We don't use << endl here because it fucks the output.

    aThread.join();
    bThread.join();
*/
    thread myThreads[5];
    for (int i = 0; i < 5; i++)
    {
        myThreads[i] = thread(&printHello, i+1);
        //* Since we have join in the same for body, since the join blocks the execution of the main thread, before stalling the second thread,
        //* main thread will wait for the first thread to finish its job.
        //* Burdaki first thread 50'ye kadar cikan, ikinci thread de 51'e kadar olan, ucuncu de 52'ye kadar olan...
    }


    for (int i = 0; i< 5; i++)
    {
        myThreads[i].join();
    }

    /*
        * Ustteki sureci concurrent olarak yapmak icin farkli bir loopta joinlemek gerkiyor.
        * Sequential olmasi gereken sey sequential gorunmuyorsa, random gorunuyorsa biraz, o zaman concurrent olarak yapmayi basardik demektir.
        * If you don't join the spawned thread, the program will crash at the end becaus eof the fact that when the main thread terminates, it releases the resources it
        *     has been allocated. When you have a child thread spawned from the main thread, since the process has no longer access to the console, program crashes. 
        ! Don't forget to join, there are some rules on join(). 
        ! - Join causes the current thread in which it was called (in our case the main thread) to be blocked until the thread on which it was called (in our case aThread)
        ! completes and terminates. JOIN MAKES THE PARENT THREAD TO WAIT FOR CHILD THREAD.
        * Join helps us to block the parent thread until the child thread is done what it's performing and in that sense it is important to locate the join at the correct place.
        ! YOU SHOULD PLACE JOIN AT THE EXACT POINT WHERE YOU'D LIKE THE PARENT THREAD TO BE BLOCKED.
    */ 
    return 0;
}


/*
    ! THREAD SYNTAX 
    ? Thread objects can be created with or without initialization.
    !   -   Execution of thread starts once the thread object is initialized.
    ? Syntax for creating with initialization (using parametric constructor) :
    !   -   thread thread_object_name (&starting_function, argument_list);
    ? Syntax for creating without initialization - thread does not start:
    !   -   thread thread_object_name;
    ? Syntax for initializing an already created thread object - thread now starts:
    !   -   thread_object_name = thread(&starting_function, argument_list);
    * See threads3.cpp for another example with arguments.

    * If you detatch, you cannot join. The thread wont be joinable(), it will return false.
*/

/*
    ! Freedom of a thread
    * Sometimes we want the child threads to become independent of parent one.
    * - For example, when the child thread is performing a long task and the main does not need anything from the child.
    * 
    * The detatch() function of thread class detaches the thread on which it is called from the calling (parent) thread, allowing the thread to
    * them to execute independently from each other.
    * 
    * After calling detach():
    *   - Note that when either one ends execution, its resources are relased.
    * 
    * After a call to detach(), this thread becomes non-joinable.
    * 
    * After the main thread finishes, any incomplete detached threads continue their execution in the background.
    *   - So you may not see some of the outpus of the detached threads on the screen (the ones that would have been displayed after main ends)
    *   - Thus you may say detach() is not so useful, and hoca agrees.
    * 
    * See threads5.cpp for an example of detach() use.
*/