/**
    The program demonstrates an iterative method to determine the width of a tree.
    The width of a tree is the largest number of nodes in the same level.
    The pseudocode of the algorithm:
        1. Create a queue to hold the nodes of the tree.
        2. Initialize the variable treeWidth to 0.
        3. Declare a variable to hold the size of the curren level: levelSize
        4. Push the root into the queue.
        5. While the queue is not empty, then
            5.1. Get the number of nodes in the queue, which is the width of the
                 current level.
            5.2. If the number of nodes is greater than treeWidth, set treeWidth to
                 the current number of nodes.
            5.3. For each node in current level (loop from top to rear)
                5.3.1. Dequeue the front node.
                5.3.2. Enqueue the front node's left and right children.
        6. Return treeWidth.
 */
#include <iostream>
#include <queue>
using namespace std;

/**
    The TreeNode class represents a node in a tree.
 */
class TreeNode
{
public:
    int value;          // The value in the node.
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
        delete left;
        delete right;
    }
};

/**
    The width function returns the width of a tree
    @param nodePtr The root of a subtree
    @return The largest number of nodes in the same level
 */
int width(const TreeNode *nodePtr)
{
    // Create a queue object to hold tree nodes.
    queue<const TreeNode *> nodeQueue;

    // Declare and initialize necessary variables.
    int treeWidth = 0;      // The width of the tree.
    int levelSize;          // The current level of the tree.

    // Enqueue the root into the queue.
    nodeQueue.push(nodePtr);

    // A loop to determine the width of the tree.
    while (nodeQueue.empty() == false)
    {
        // Get the current number of nodes in the level.
        levelSize = nodeQueue.size();

        // Update the width of the tree.
        if (levelSize > treeWidth) treeWidth = levelSize;

        // Pop all nodes of the current level off and enqueue their
        // children.
        for (int count = 0; count < levelSize; count++)
        {
            // Pop the front node.
            const TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node into the queue.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the width of the tree.
    return treeWidth;
}

int main()
{
    /** Demo input (Tree width = 4)
                30
              /    \
            18      40
           /  \    /  \
          5   25  35  60
     */

    // Create the root of the tree.
    TreeNode *root = new TreeNode(30);
    
    // Create children of the root.
    TreeNode *rootLeftChild = new TreeNode(18);
    TreeNode *rootRightChild = new TreeNode(40);
    root->left = rootLeftChild;
    root->right = rootRightChild;

    // Create children for the level 3.
    TreeNode *child3_1_L = new TreeNode(5);
    TreeNode *child3_1_R = new TreeNode(25);
    rootLeftChild->left = child3_1_L;
    rootLeftChild->right = child3_1_R;

    TreeNode *child3_2_L = new TreeNode(35);
    TreeNode *child3_2_R = new TreeNode(60);
    rootRightChild->left = child3_2_L;
    rootRightChild->right = child3_2_R;

    // Display the width of the tree.
    cout << "Tree width: " << width(root) << endl;

    // Delete dynamically allocated memory.
    delete root;

    return 0;
}