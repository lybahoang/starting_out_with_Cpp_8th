#ifndef DYNAMIC_INT_STACK_H
#define DYNAMIC_INT_STACK_H

class DynamicIntStack
{
private:
    // Structure for the stack node.
    struct StackNode
    {
        int value;          // The node value.
        StackNode *next;    // The next node.
    };

    StackNode *top;         // The top of the stack.
    int numNodes;           // The number of nodes in the stack.

public:
    // Constructor.
    DynamicIntStack();

    // Destructor.
    ~DynamicIntStack();

    // Stack operations.
    void push(int);
    void pop(int &);
    bool isEmpty() const;

    // Other functions.
    int getNumNodes() const;
};
#endif