/**
 * This is a generic template class of a dynamic queue with some basic operations.
 * @author Ly Ba Hoang
 * @date 10 September 2025
 */

#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class DynamicQueue
{
private:
    // A structure for the queue node.
    struct QueueNode
    {
        T data;             // The data of the node.
        QueueNode *next;    // The pointer to the next node.
    };

    QueueNode *front;       // The front of the queue.
    QueueNode *rear;        // The rear of the queue.
    int numNodes;           // The number of nodes in the queue.

public:
    // Constructor.
    DynamicQueue();

    // Destructor.
    ~DynamicQueue();

    // Basic operations.
    void enqueue(const T &);
    void dequeue(T &);
    bool isEmpty() const;
    int getNumNodes() const;
};

/**
 * Constructor. The constructor creates an empty queue.
 */
template <class T>
DynamicQueue<T>::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
    numNodes = 0;
}

/**
 * Destructor. The destructor deletes all nodes in the queue.
 */
template <class T>
DynamicQueue<T>::~DynamicQueue()
{
    // Deletes all nodes in the queue.
    QueueNode *nodePtr = front;     // To traverse the queue from front.

    // While nodePtr is not nullptr, then deletes the node.
    while (nodePtr)
    {
        // Save the node after nodePtr.
        QueueNode *tempNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Move nodePtr to the next node.
        nodePtr = tempNode;
    }

    // Reset the front, rear, and the number of nodes.
    front = nullptr;
    rear = nullptr;
    numNodes = 0;
}

/**
 * Operation enqueue(const T &): The function accepts a constant reference argument and
 * pushes the item onto the rear of the queue.
 * @param value (const T &): The item to add to the queue.
 * @return void.
 */
template <class T>
void DynamicQueue<T>::enqueue(const T &value)
{
    // Allocate a new node and store value there.
    QueueNode *newNode = new QueueNode;
    newNode->data = value;
    newNode->next = nullptr;

    // If there are no nodes in the queue, make newNode the first node.
    if (this->isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    // Otherwise, add newNode to the rear of the queue.
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    // Update the number of nodes in the queue.
    numNodes++;
}

/**
 * Operation dequeue(T &): The function accepts a reference argument, pops the front 
 * value off the queue, and assigns it to the rerefence parameter.
 * @param catchVar (T &): The reference parameter to hold the popped-off value.
 * @return void. 
 */
template <class T>
void DynamicQueue<T>::dequeue(T &catchVar)
{
    // If the queue is empty, then display a message indicating that the queue
    // is empty.
    if (this->isEmpty())
    {
        cout << "The queue is empty.\n";
    }
    // Otherwise, pop the front value off the queue.
    else
    {
        // Store the front value to catchVar.
        catchVar = front->data;

        // Save the node after front.
        QueueNode *tempNode = front->next;

        // Delete front.
        delete front;

        // Make front point to tempNode.
        front = tempNode;

        // Update the number of nodes in the queue.
        numNodes--;
    }
}

/**
 * Operation isEmpty(): The function returns true if the queue is empty, otherwise
 * it returns false.
 * @param void.
 * @return true or false (boolean).
 */
template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    // If the number of nodes is 0, the queue is empty.
    if (numNodes == 0)
        return true;
    // Otherwise, returns false.
    return false;
}

/**
 * Operation getNumNodes(): The function returns the number of nodes in the queue.
 * @param void.
 * @return int - the number of nodes in the queue.
 */
template <class T>
int DynamicQueue<T>::getNumNodes() const
{ return numNodes; }
#endif