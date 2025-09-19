/**
    The program demonstrates an iterative method to count the number of leaves
    in a tree.
    The pseudocode of the algorithm:
        1. Create a stack to hold the nodes in the tree.
        2. Declare a variable numLeaves to hold the number of leaves and initialize
           it to 0.
        3. Push the root onto the stack.
        4. While the stack is not empty, then
            4.1. Pop the top node off the stack.
            4.2. If the top node has no children, increment numLeaves.
            4.2. Else, push the top node's right and left children onto the stack.
 */

#include <iostream>
#include <stack>
using namespace std;

/**
    The TreeNode class represents a node in the tree.
 */
class TreeNode
{
public:
    int value;          // The value in the node.
    TreeNode *left;     // The left child of the tree.
    TreeNode *right;    // The right child of the tree.

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
    The countLeaves function counts and returns the number of leaves
    in a tree.
    @param nodePtr The root of a subtree.
    @return The number of leaves in the tree.
 */
int countLeaves(const TreeNode *nodePtr)
{
    // Create a stack object to hold nodes in the tree.
    stack<const TreeNode*> nodeStack;

    // Initialize a variable to hold the number of leaves.
    int numLeaves = 0;

    // Push the root onto the stack.
    nodeStack.push(nodePtr);

    // A loop to process the tree and count leaves.
    while (nodeStack.empty() == false)
    {
        // Pop the top node off the stack.
        const TreeNode *currentNode = nodeStack.top();
        nodeStack.pop();

        // If the current node is a leaf, then increment numLeaves.
        if (currentNode->left == nullptr && currentNode->right == nullptr)
        {
            numLeaves++;
        }
        // Otherwise, push its children onto the stack.
        else
        {
            if (currentNode->right) nodeStack.push(currentNode->right);
            if (currentNode->left) nodeStack.push(currentNode->left);
        }
    }

    return numLeaves;
}

int main()
{
    /** Demo input
            25
           /  \
          9    30
         / \     \
        5   20    49
     */

    // Create the root of the tree.
    TreeNode *root = new TreeNode(25);

    // Create the children of the root.
    TreeNode *rootLeftChild = new TreeNode(9);
    TreeNode *rootRightChild = new TreeNode(30);
    root->left = rootLeftChild;
    root->right = rootRightChild;

    // Create the children for the left root child.
    TreeNode *child2_1_L = new TreeNode(5);
    TreeNode *child2_1_R = new TreeNode(20);
    rootLeftChild->left = child2_1_L;
    rootLeftChild->right = child2_1_R;

    // Create the child for the right root child.
    TreeNode *child2_2_R = new TreeNode(49);
    rootRightChild->right = child2_2_R;

    // Display the number of leaves in the tree (3).
    cout << "Number of leaves: " << countLeaves(root) << endl;

    // Delete dynamically allocated memory.
    delete root;

    return 0;
}