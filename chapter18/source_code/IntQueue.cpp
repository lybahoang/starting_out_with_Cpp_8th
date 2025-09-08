// Implementation file for the IntQueue class.
#include "IntQueue.h"
#include <iostream>
using namespace std;

/***
 * Constructor.
 * The constructor creates an empty queue of a specified size.
 */
IntQueue::IntQueue(int size)
{
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

/***
 * Copy constructor.
 * The copy constructor copies values of another IntQueue object to this object.
 */
IntQueue::IntQueue(const IntQueue &other)
{
    // Allocate the queue array.
    queueArray = new int[other.queueSize];

    // Copy the other object's attributes.
    queueSize = other.queueSize;
    front = other.front;
    rear = other.rear;
    numItems = other.numItems;

    // Copy the other object's queue array.
    for (int count = 0; count < queueSize; count++)
        queueArray[count] = other.queueArray[count];
}

/***
 * Destructor.
 * The destructor deletes the queueArray.
 */
IntQueue::~IntQueue()
{
    if (queueArray != nullptr)
        delete [] queueArray;
}

/***
 * Member function - enqueue(int).
 * The function inserts a value at the rear of the queue.
 */
void IntQueue::enqueue(int value)
{
    // If the queue is full, displays a message.
    if (isFull())
        cout << "The queue is full.\n";
    // Otherwise, inserts the value.
    else
    {
        // Calculate the new rear position.
        rear = (rear + 1) % queueSize;

        // Insert new item.
        queueArray[rear] = value;

        // Update item count.
        numItems++;
    }
}

/***
 * Member function - dequeue(int &).
 * The function removes the value at the front of the queue
 * and copies it into num.
 */
void IntQueue::dequeue(int &num)
{
    // If the queue is empty, displays a message.
    if (isEmpty())
        cout << "The queue is empty.\n";
    // Otherwise, removes the value at the front of the queue
    // and copies it into num.
    else
    {
        // Move front.
        front = (front + 1) % queueSize;

        // Retrive the front item.
        num = queueArray[front];

        // Update item count.
        numItems--;
    }
}

/***
 * Member function - isFull().
 * The function returns true if the queue is full, otherwise false.
 */
bool IntQueue::isFull() const
{
    if (numItems == queueSize)
        return true;
    return false;
}

/***
 * Member function - isEmpty().
 * The function returns true if the queue is empty, otherwise false.
 */
bool IntQueue::isEmpty() const
{
    if (numItems)
        return false;
    return true;
}

/***
 * Member function - clear().
 * The funciton sets the front and rear indices, and sets numItems to 0.
 */
void IntQueue::clear()
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}