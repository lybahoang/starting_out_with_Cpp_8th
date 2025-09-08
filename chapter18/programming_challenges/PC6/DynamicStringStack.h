#ifndef DYNAMIC_STRING_STACK_H
#define DYNAMIC_STRING_STACK_H
#include <string>
using namespace std;

class DynamicStringStack
{
private:
    // Structure for the stack node.
    struct StackNode
    {
        string value;       // The node value.
        StackNode *next;    // The next node.
    };

    StackNode *top;         // The top of the stack.
    int numNodes;           // The number of nodes.

    public:
    // Constructor.
    DynamicStringStack()
        { top = nullptr;
          numNodes = 0; }
    
    // Destructor.
    ~DynamicStringStack();

    // Stack operations.
    void push(string);
    void pop(string &);
    bool isEmpty() const;

    // Other functions.
    int getNumNodes() const;
};
#endif