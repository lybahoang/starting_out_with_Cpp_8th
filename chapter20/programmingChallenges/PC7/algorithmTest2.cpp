/**
    The program demonstrates an iterative method to insert values in
    a tree into a queue in ascending order.
    The pseudocode to traverse a tree in-order:
        1. Create a stack to hold the nodes.
        2. Intialize currentNode to the root.
        3. While (!currentNode or the stack is not empty), then
            3.1. While (currentNode is not nullptr), then
                3.1.1. Push currentNode onto the stack.
                3.1.2. Move to the left child of currentNode.
            3.2. Pop the top node off the stack and assign it to currentNode.
            3.3. Process the node (e.g. display, store,...)
            3.4. Set currentNode to its right child.
        
    The pseudocode of the algorithm: void toQueue(queue<int> &outQueue) cons
        1. Create a stack to hold the nodes.
        2. Initialize currentNode to the node calling the function.
        3. While (currentNode is not nullptr or the stack is not empty), then
            3.1. While (currentNode is not nullptr), then
                3.1.1. Push currentNode onto the stack.
                3.1.2. Move currentNode to its left child.
            3.2. Pop the top node off the stack and assign it to currentNode.
            3.3. Enqueue the value in currentNode into the queue.
            3.4. Set currentNode to its right child.
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
    The TreeNode class represents a node in a tree.
 */
class TreeNode
{
private:
    int value;          // The value in the node.
public:
    TreeNode *left;     // The left child of the node.
    TreeNode *right;    // The right child of the node.

    // Constructor.
    TreeNode(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }

    // Destructor.
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }

private:
    /**
        The toQueue function (helper) accepts a reference to a queue and
        inserts values in the tree into the queue in ascending order.
        @param outQueue The queue that holds the values in the tree in
                        ascending order.
     */
    void toQueue(queue<int> &outQueue) const
    {
        // Create a stack to hold nodes in the tree.
        stack<const TreeNode *> nodeStack;

        // Initialize currentNode to the current node.
        const TreeNode *currentNode = this;

        // A loop to process the tree.
        while (currentNode != nullptr || !nodeStack.empty())
        {
            // Push currentNode onto the stack.
            while (currentNode)
            {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }

            // Pop the top value off the stack.
            currentNode = nodeStack.top();
            nodeStack.pop();

            // Enqueue the value in currentNode into the queue.
            outQueue.push(currentNode->value);

            // Move currentNode to its right child.
            currentNode = currentNode->right;
        }
    }

public:
    /**
        The toQueue function (user interface) returns a queue containing the
        values in the tree in ascending order by calling its helper function.
        @return The queue that holds values in the tree in ascending order.
     */
    queue<int> toQueue() const
    {
        // Create a queue to hold the values in the tree in ascending order.
        queue<int> outputQueue;

        // Enqueue values of the tree into the queue.
        toQueue(outputQueue);

        // Return the queue.
        return outputQueue;
    }
};

int main()
{
    /** Demo input
            40
           /  \
         25    70
        /  \
       10  30
     */

    // Create a tree that looks like the demo input.
    TreeNode *root = new TreeNode(40);
    root->left = new TreeNode(25);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);

    // Get the queue.
    queue<int> myQueue = root->toQueue();

    // Display the values in the queue.
    while (!myQueue.empty())
    {
        cout << myQueue.front() << "  ";
        myQueue.pop();
    }

    // Delete allocated memory.
    delete root;

    return 0;
}