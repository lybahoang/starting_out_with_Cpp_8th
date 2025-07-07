#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include <new>
#include <iostream>
using namespace std;
template <class T>
class DynamicStack
{
private:
    // Structure for the stack node.
    struct StackNode
    {
        T value;            // The node value.
        StackNode *next;    // The next node.
    };

    // The stack top.
    StackNode *top;

public:
    // Constructor.
    DynamicStack();

    // Destructor.
    ~DynamicStack();

    // Stack operations.
    void push(T);
    void pop(T &);
    bool isEmpty() const;
};
#endif

/**
 * Constructor: Makes top point to nullptr in order to indicate that
 * the stack is empty.
 */
template <class T>
DynamicStack<T>::DynamicStack()
{
    top = nullptr;
}

/**
 * Destructor: Deletes all nodes in the stack.
 */
template <class T>
DynamicStack<T>::~DynamicStack()
{
    // Create a stack node to traverse the stack.
    StackNode *nodePtr = nullptr;

    // Position nodePtr at the top of the stack.
    nodePtr = top;

    // While nodePtr is not a null pointer, save the node after
    // nodePtr and then delete nodePtr.
    while (nodePtr != nullptr)
    {
        // Save the node after nodePtr.
        StackNode *tempNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Move nodePtr to the next node.
        nodePtr = tempNode;
    }
}

/**
 * Operation push(T): Pushes an item onto the stack.
 * @param item: The item to be pushed.
 * @return: void.
 */
template <class T>
void DynamicStack<T>::push(T item)
{
    try
    {
        // Create a StackNode and assign it the item value.
        StackNode *newNode = new StackNode;
        newNode->value = item;
    
        // Link the new node to the current stack top.
        newNode->next = top;
    
        // Update top to point to the new node.
        top = newNode;
    }
    // Handle if new node cannot be created.
    catch (bad_alloc)
    {
        cout << "Memory allocation errors.\n";
    }
}

/**
 * Opeartion pop(T &): Pops the top item off the stack and assigns the
 * item value into the reference parameter.
 * @param catchVar: The reference parameter to receive the item.
 * @return: void.
 */
template <class T>
void DynamicStack<T>::pop(T &catchVar)
{
    // Assigns the top item value to the reference paramter.
    catchVar = top->value;

    // Remember the node after the top.
    StackNode *tempNode = top->next;

    // Delete the top node.
    delete top;

    // Update top to point to the temporary node.
    top = tempNode;
}