/**
    - The program demonstrates an iterative method to determine the height of a binary tree.
    - The height of a binary treeis defined as the number of levels in the tree.
    - The pseudocode of the algorithm:
        1. Create a queue to store nodes in the tree.
        2. Create two variables: levelSize (the number of nodes in the current level) and
           height (the height of the tree).
        3. Enqueue the root into the queue.
        4. While the queue is not empty, then
            4.1. Store the number of current nodes in the queue as levelSize.
            4.2. For each node in the current level (loop from front to rear):
                4.2.1. Dequeue the front node.
                4.2.2. Enqueue the node's left child and right child, if it has.
            4.3. Increment height.
        5. Return height.
 */

#include <iostream>
#include <queue>
using namespace std;

class TreeNode 
{
public:
    int value;          // The value of the node.
    TreeNode *left;     // The node's left child.
    TreeNode *right;    // The node's right child.

    // Constructor of the class.
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

int height(const TreeNode * nodePtr)
{
    // Variables declaration.
    int levelSize;      // The number of nodes in the current level.
    int height = 0;      // The depth of the tree.

    // Create a queue object to hold the tree nodes.
    queue<const TreeNode *> nodesArray;

    // Enqueue the root into the queue.
    nodesArray.push(nodePtr);

    // Enter a loop to process the queue and the tree.
    while (nodesArray.empty() == false)
    {
        // Store the current number of nodes in levelSize.
        levelSize = nodesArray.size();

        // Enqueue children of current nodes into the queue.
        for (int index = 0; index < levelSize; index++)
        {
            // Take a reference to the front node.
            const TreeNode *currentNode = nodesArray.front();

            // Pop the front node off the queue.
            nodesArray.pop();

            // Enqueue the front node's left and right children if exist.
            if (currentNode->left)
                nodesArray.push(currentNode->left);
            if (currentNode->right)
                nodesArray.push(currentNode->right);
        }

        // Increment depth variable.
        height++;
    }

    // Return the height of the tree.
    return height;
}

int main()
{
    /** Demo input:
                12
               /  \
              8    18
             / \
            5   11
     */

    // Declare a root of the tree.
    TreeNode *root = new TreeNode(12);

    // Declare children of the root.
    TreeNode *children1_L = new TreeNode(8);
    TreeNode *children1_R = new TreeNode(18);
    root->left = children1_L;
    root->right = children1_R;

    // Declare children for the left node.
    TreeNode *children2_L = new TreeNode(5);
    TreeNode *children2_R = new TreeNode(11);
    children1_L->left = children2_L;
    children1_L->right = children2_R;

    // Display the height of the tree.
    cout << "Height: " << height(root) << endl;

    // Delete dynamically allocated memomry.
    delete root;

    return 0;
}
