/**
    The program demonstrates an overloaded assignment operator and a copy
    constructor for a binary tree.
    1. Overloaded assigment operator:
        TreeNode &operator=(const TreeNode &rightObject)
    2. A copy constructor
        TreeNode(const TreeNode &other)
 */

#include <iostream>
using namespace std;

/**
    The TreeNode class represents a node in a tree.
 */
class TreeNode
{
private:
    int value;          // The value in the node.
    TreeNode *copyTree(const TreeNode *other)
    {
        // If the other tree is empty, then return a null
        // pointer.
        if (other == nullptr) return nullptr;

        // Allocate a new node and store the value of the
        // current node in other tree into the new node.
        TreeNode *newNode = new TreeNode(other->value);

        // Copy the left and right subtrees of the other 
        // tree into this tree.
        newNode->left = copyTree(other->left);
        newNode->right = copyTree(other->right);

        // Return the new tree.
        return newNode;
    }

    void clearTree()
    {
        // Clear the left subtree of the node.
        if (left)
        {
            left->clearTree();
            delete left;
            left = nullptr;
        }

        // Clear the right subtree of the node.
        if (right)
        {
            right->clearTree();
            delete right;
            right = nullptr;
        }
    }

public:
    TreeNode *left;     // The left child of the node.
    TreeNode *right;    // The right child of the node.

    // Constructor.
    TreeNode(int data = 0) {
        value = data;
        left = nullptr;
        right = nullptr;
    }

    // Destructor.
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }

    // Overloaded assignment operator.
    TreeNode &operator=(const TreeNode &other) {
        // If this tree and other tree is the same tree,
        // then do nothing (self-assignment).
        if (this != &other)
        {
            // Delete all nodes in the current tree.
            this->clearTree();

            // Copy the current node.
            this->value = other.value;

            // Copy the left subtree of the other node.
            this->left = copyTree(other.left);

            // Copy the right subtree of the other node.
            this->right = copyTree(other.right);
        }
        // Return this tree.
        return *this;
    }

    // Copy constructor.
    TreeNode(const TreeNode &other)
    {
        // Copy the current node.
        this->value = other.value;

        // Copy the left subtree.
        this->left = copyTree(other.left);

        // Copy the right subtree.
        this->right = copyTree(other.right);
    }

    // The getValue function.
    int getValue() const { return value; }
};

/**
    The displayTree function displays the values in the tree
    via the in-order traversal (left -> root -> right);
    @param root The root of the tree.
 */
void displayTree(const TreeNode *root)
{
    if (root)
    {
        // Display the left subtree.
        displayTree(root->left);

        // Display the root value.
        cout << root->getValue() << "  ";

        // Display the right subtree.
        displayTree(root->right);
    }
}

int main()
{
    /** Demo input:
            30
           /  \
         15    50
        /  \
       5    20
     */

    TreeNode *root1 = new TreeNode(30);
    root1->left = new TreeNode(15);
    root1->right = new TreeNode(50);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(20);

    // Display root1.
    cout << "Root 1: ";
    displayTree(root1);

    // Create another tree and intialize it with root1 (copy constructor).
    TreeNode root2 = *root1;
    // Display root2.
    cout << "\nRoot 2: ";
    displayTree(&root2);

    // Add new nodes to root1.
    root1->right->left = new TreeNode(40);
    root1->right->right = new TreeNode(100);

    // Display root1 again.
    cout << "\nNew root1: ";
    displayTree(root1);

    // Display root2 again.
    cout << "\nRoot2 unchanged: ";
    displayTree(&root2);

    // Create another root and assigns it to root1.
    TreeNode *root3 = new TreeNode();
    *root3 = *root1;      // Overloaded assignment operator.

    // Display root3.
    cout << "\nRoot3: ";
    displayTree(root3);

    delete root1;
    delete root3;
    
    return 0;
}
