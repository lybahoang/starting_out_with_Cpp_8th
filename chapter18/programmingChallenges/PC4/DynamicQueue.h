// Specification file for the DynamicQueue class.
#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class DynamicQueue
{
private:
    // Structure for the queue nodes.
    struct QueueNode {
        T value;            // Value in the node.
        QueueNode *next;    // The next node.
    };

    QueueNode *front;       // The front of the queue.
    QueueNode *rear;        // The rear of the queue.
    int numItems;           // The number of items in the queue.

public:
    // Default constructor.
    DynamicQueue();

    // Destructor.
    ~DynamicQueue();

    // Queue opeartions.
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty() const;
    void clear();
};

/**
 * Default constructors: Creates an empty queue.
 */
template <class T>
DynamicQueue<T>::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

/**
 * Destructor: Deletes all nodes in the queue.
 */
template <class T>
DynamicQueue<T>::~DynamicQueue()
{
    clear();
}

/**
 * Function enqueue(T): Inserts an item at the rear of the queue.
 * @param item: The item to be inserted.
 * @return: void.
 */
template <class T>
void DynamicQueue<T>::enqueue(T item)
{
    QueueNode *newNode = new QueueNode;     // A new node.

    // Store item in newNode.
    newNode->value = item;
    newNode->next = nullptr;

    // If there are no nodes in the queue, then make newNode the
    // first node.
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    // Otherwise, insert newNode at the rear of the queue.
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    // Update the number of items.
    numItems++;
}

/**
 * Function dequeue(T &): Removes the value at the front of the queue,
 * and assigns it into the reference parameter.
 * @param catchVare: The reference parameter that holds the value.
 * @return: void.
 */
template <class T>
void DynamicQueue<T>::dequeue(T &catchVar)
{
    // If the queue is empty, displays a message.
    if (isEmpty())
    {
        cout << "The queue is empty\n";
    }
    // Otherwise, removes the value at the front of the queue.
    else
    {
        // Save the front node value in catchVar. 
        catchVar = front->value;

        // Save the node after the front node.
        QueueNode *tempNode = front->next;

        // Delete the front node.
        delete front;

        // Move front to the tempNode.
        front = tempNode;

        // Update the number of items.
        numItems--;
    }
}

/**
 * Function isEmpty(): Returns true if the queue is empty, or false otherwise.
 */
template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    // If the number of items is larger than 0, then returns false.
    if (numItems > 0)
        return false;
    // Otherwise, returns true.
    return true;
}

/**
 * Function clear(): Dequeues all elements in the queue.
 */
template <class T>
void DynamicQueue<T>::clear()
{
    T catchVar;     // Dummy variable for dequeue.

    // Clears the queue.
    while (!isEmpty())
        dequeue(catchVar);
}
#endif