#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

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

