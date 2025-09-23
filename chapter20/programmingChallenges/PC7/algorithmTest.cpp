/**
    The program demonstrates a recursive solution to return a queue
    containing values in binary tree in ascending order.
    The pseudocode of the queue <int> toQueue() function:
        @param outQueue The queue to hold values in the tree.
        1. If (root is not nullptr), then
            1.1. Enqueue the values in the left subtree recursively.
            1.2. Enqueue the value in the root.
            1.3. Enqueue the value in the right subtree recurseively.
 */
#include <iostream>
#include <queue>
using namespace std;

/**
    The TreeNode class represents a node in the tree.
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
        The toQueue function (helper) inserts values in the tree into
        a queue in ascending order.
        @param outQueue The queue containing values in the tree in ascending
                        order.
     */
    void toQueue(queue<int> outQueue) const
    {
        // Enqueue the left subtree.
        if (left)
        {
            left->toQueue(outQueue);
        }
        // Enqueue the current node.
        outQueue.push(value);

        // Enqueue the right subtree.
        if (right)
        {
            right->toQueue(outQueue);
        }
    }

public:
    /**
        The toQueue function (user interface) returns a queue containing
        values in the tree in ascending order.
        @return The queue that holds the values in the tree in ascending order.
     */
    queue<int> toQueue() const
    {
        // Create a queue to hold the output.
        queue<int> myQueue;

        // Enqueue values of the tree into the queue.
        toQueue(myQueue);

        // Return the queue.
        return myQueue;
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
}