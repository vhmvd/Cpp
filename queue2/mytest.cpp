// CMSC 341 - Fall 2020 - Project 0

// driver.cpp: a sample driver for the Queue class.
// This is NOT a test program; it just demonstrates basic usage of
// Queue.

// Assignment:
//   (1) Complete the copy constructor (in queue.h)
//   (2) Complete the assignment operator (in queue.h)
//   (3) Complete the destructor (in queue.h)
//   (4) Write a test program (mytest.cpp) to test copy and assignment
//   (5) Verify destructor by running the test program in Valgrind

#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue<int> intQueue;
    cout << "\nPush integers on queue and dump contents:\n";
    for (int i = 1; i <= 5; i++) {
        intQueue.enqueue(i);
    }

    cout << "\nAttempt assignment\n";
    Queue<int> intQueue1;
    Queue<int> intQueue2 = intQueue;
    intQueue1 = intQueue;

    intQueue.dump();

    cout << "\nRead contents using head() and dequeue():\n";
    while (!intQueue.empty()) {
        cout << intQueue.head() << endl;
        intQueue.dequeue();
    }

    return 0;
}
