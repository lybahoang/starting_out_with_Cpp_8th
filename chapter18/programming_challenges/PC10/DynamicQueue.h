/**
 * This is a generic template class for a queue with some basic operations.
 * @author Ly Ba Hoang.
 * @date 09 September 2025.
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
        QueueNode *next;    // The point to the next node.
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
    // While front is not nullptr, then delete front node.
    while (front)
    {
        // Save the node after the front node.
        QueueNode *tempNode = front->next;

        // Delete front.
        delete front;

        // Make front point to tempNode.
        front = tempNode;

    }
    
    // Update rear to point to a null pointer.
    rear = nullptr;

    // Update the number of nodes in the queue.
    numNodes = 0;
}

/**
 * Operation enqueue(const T &): The function accepts a constant reference argument and
 * then adds the argument to the rear of the queue.
 * @param value (const T &): The data that is added to the rear of the queue.
 * @return void.
 */
template <class T>
void DynamicQueue<T>::enqueue(const T &value)
{
    // Allocate a new node and store value there.
    QueueNode *newNode = new QueueNode;
    newNode->data = value;
    newNode->next = nullptr;

    // If the queue is empty, then make newNode the first node.
    if (this->isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    // Otherwise, adds newNode at the rear of the queue.
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    // Update the number of nodes.
    numNodes++;
}

/**
 * Operation dequeue(T &): The function pops the front value off the queue and stores
 * it into the referece parameter.
 * @param catchVar (T &): The reference paramter to hold the popped-off value.
 * @return void.
 */
template <class T>
void DynamicQueue<T>::dequeue(T &catchVar)
{
    // If the queue is empty, then display a message saying the queue is empty.
    if (this->isEmpty())
    {
        cout << "Cannot dequeue anymore. The queue is empty.\n";
    }
    // Otherwise, dequeue the front node.
    else
    {
        // Store the front value to the reference variable.
        catchVar = front->data;

        // Save the node after front.
        QueueNode *tempNode = front->next;

        // Delete front.
        delete front;

        // Make front point to tempNode.
        front = tempNode;

        // Update the number of nodes.
        numNodes--;
    }
}

/**
 * Operation isEmpty(): The function returns true if the queue is empty. Otherwise, it
 * returns false.
 * @param void.
 * @return boolean value: true or false.
 */
template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    // If the number of nodes in the queue is greater than 0, then the queue is not empty.
    if (numNodes > 0)
        return false;
    // Otherwise, returns true.
    return true;
}

#endif