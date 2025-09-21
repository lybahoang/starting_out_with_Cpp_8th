/**
    - The program demonstrates a recursive method to determine the height of a binary tree.
    - The height of a binary tree is the number of levels in the tree.
    - The ideas of the algorithm:
        1. Base case: If the tree is empty, then retun 0.
        2. Recursive step:
            2.1. Get the height of the left subtree recursively.
            2.2. Get the height of the right subtree recursively.
            2.3. Compute the maximum of the heights of the left and the right subtrees and
                 add 1 to it for the current node.
 */
#include <iostream>
#include <algorithm>
using namespace std;

/**
    The TreeNode class represents a node in the tree.
 */
class TreeNode
{
public:
    int value;          // The value of the node.
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
    The height function determines the height of the tree recursively and
    returns that value.
    @param nodePtr The root of a subtree.
    @return The height of the tree.
 */
int height(const TreeNode *nodePtr)
{
    // The base case: If the tree is empty, then return 0.
    if (nodePtr == nullptr)
        return 0;

    // The recursive step.
    // Get the height of the left subtree recursively.
    int leftHeight = height(nodePtr->left);

    // Get the height of the right subtree recursively.
    int rightHeight = height(nodePtr->right);

    // Return the height of the tree.
    return max(leftHeight, rightHeight) + 1;
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

    // Create the root of the tree.
    TreeNode *root = new TreeNode(12);

    // Create the children of the root.
    TreeNode *rootLeftChild = new TreeNode(8);
    TreeNode *rootRightChild = new TreeNode(18);
    root->left = rootLeftChild;
    root->right = rootRightChild;

    // Create the children of the left node.
    TreeNode *child2_1_L = new TreeNode(5);
    TreeNode *child2_1_R = new TreeNode(11);
    rootLeftChild->left = child2_1_L;
    rootLeftChild->right = child2_1_R;

    // Display the height of the tree.
    cout << "Height: " << height(root) << endl;

    // Delete dynamically allocated memomry.
    delete root;

    return 0;
}