#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class StaticQueue
{
private:
    T *queueArray;      // The queue array.
    int queueSize;      // The size of the queue.
    int front;          // Subscript of the queue front.
    int rear;           // Subscript of the queue rear.
    int numItems;       // Number of items in the queue.

public:
    // Constructor.
    StaticQueue(int);

    // Destructor.
    ~StaticQueue();

    // Queue operations.
    void enqueue(T);
    void dequeue(T &);
    bool isFull() const;
    bool isEmpty() const;
};

/**
 * Constructor: Allocates the queue array of a specific size.
 * @param size: The size of the queue.
 */
template <class T>
StaticQueue<T>::StaticQueue(int size)
{
    // Allocate the queue array.
    queueArray = new T[size];

    // Set the queue size.
    queueSize = size;

    // Set the front subscript.
    front = -1;

    // Set the rear subscript.
    rear = -1;

    // Set the number of items in the queue.
    numItems = 0;
}

/**
 * Destructor: Deletes the queue array.
 */
template <class T>
StaticQueue<T>::~StaticQueue()
{
    if (queueArray)
        delete [] queueArray;
}

/**
 * Queue operation - enqueue(T): pushes an item at the rear
 * of the queue.
 * @param item: The item pushed at the rear of the rear.
 * @return void.
 */
template <class T>
void StaticQueue<T>::enqueue(T item)
{
    // If the queue is full, then display a message.
    if (isFull())
    {
        cout << "The queue is full.\n";
    }
    // Otherwise, inserts the item at the rear of the queue.
    else
    {
        // Calculate the rear position.
        rear = (rear + 1) % queueSize;

        // Insert the new item.
        queueArray[rear] = item;

        // Update the number of items.
        numItems++;
    }
}

/**
 * Queue operation - dequeue(T &): removes the value at the 
 * front of the queue and copies it into the reference parameter.
 * @param catchVar: The reference parameter.
 * @return void. 
 */
template <class T>
void StaticQueue<T>::dequeue(T &catchVar)
{
    // If the queue is empty, then displays a message.
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
    }
    // Otherwise, dequeues the item at the front of the queue.
    else
    {
        // Calculate the front subscript.
        front = (front + 1) % queueSize;

        // Assign the value into catchVar.
        catchVar = queueArray[front];

        // Update the number of items.
        numItems--;
    }
}

/**
 * Queue operation - isEmpty(): returns true if the queue is empty,
 * or false otherwise.
 */
template <class T>
bool StaticQueue<T>::isEmpty() const
{
    // If the number of items is zero, then the queue is empty
    // and so return true.
    if (numItems == 0)
        return true;
    // Otherwise, return false.
    return false;
}

/**
 * Queue operation - isFull(): returns true if the queue is full, or
 * false otherwise.
 */
template <class T>
bool StaticQueue<T>::isFull() const
{
    // If the number of items is equal to (queueSize - 1), then the
    // queue is full.
    if (numItems == queueSize)
        return true;
    // Otherwise, return false.
    return false;
}
#endif