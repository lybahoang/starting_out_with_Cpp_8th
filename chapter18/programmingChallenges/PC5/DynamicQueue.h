#ifndef DYNAMIC_QUEUE_H
#define DYNMAIC_QUEUE_H
#include <iostream>
#include <new>
using namespace std;

template <class T>
class DynamicQueue
{
protected:
    // Structure for the queue stack.
    struct QueueNode
    {
        T value;            // The value node.
        QueueNode *next;    // The next node.
    };

    QueueNode *front;       // The front of the queue.
    QueueNode *rear;        // The rear of the queue.
    int numNodes;           // The number of nodes in the queue.

public:
    // Constructor.
    DynamicQueue();

    // Destructor.
    ~DynamicQueue();

    // Queue operations.
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty() const;
    void clear();

    // Other functions.
    int getNumNodes() const;
};

/**
 * Constructor: Creates an empty queue with defaut values.
 */
template <class T>
DynamicQueue<T>::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
    numNodes = 0;
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
 * Operation enqueue(T): Inserts an item at the rear of the queue.
 * @param item: The item to be inserted.
 * @return: void.
 */
template <class T>
void DynamicQueue<T>::enqueue(T item)
{
    // Create a new node and assign to it the item value.
    try
    {
        QueueNode *newNode = new QueueNode;
        newNode->value = item;
        newNode->next = nullptr;
        // If there are no nodes in the list, make the new node
        // the firt node.
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        // Otherwise, insert the new node at the rear of the queue.
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    
        // Update the number of nodes in the queue.
        numNodes++;
    }
    // Handle if the memory is not allocated succesfully.
    catch (bad_alloc)
    {
        cout << "Memory allocation errors.\n";
    }
}

/**
 * Operation dequeue(T &): Removes an item at the front of the queue,
 * and assign it to the reference parameter.
 * @param catchVar: The reference parameter the holds the value.
 * @return: void.
 */
template <class T>
void DynamicQueue<T>::dequeue(T &catchVar)
{
    // If the queue is empty, then display a message.
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        return;
    }

    // Assign the item at the front of the queue to the reference
    // variable.
    catchVar = front->value;

    // Save the node after the front of the queue.
    QueueNode *tempNode = front->next;

    // Delete the node at the front of the queue.
    delete front;

    // Update front to point to the temporary node.
    front = tempNode;

    // Update the number of nodes in the queue.
    numNodes--;
}

/**
 * Operation isEmpty(): Returns true if the queue is empty, or false otherwise.
 * @param: none.
 * @return: bool.
 */
template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    // If the number of nodes is equal to zero, then the queue is empty.
    if (numNodes == 0)
        return true;
    // Otherwise, returns false.
    return false;
}

/**
 * Operation clear(): Dequeues all nodes in the queue.
 * @param: none.
 * @return: void.
 */
template <class T>
void DynamicQueue<T>::clear()
{
    // A variable to dequeue the queue.
    T catchVar;

    // While the queue is not empty, dequeue it.
    while (!isEmpty())
        dequeue(catchVar);
}

#endif