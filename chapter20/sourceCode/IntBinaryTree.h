#ifndef INT_BINARY_TREE_H
#define INT_BINARY_TREE_H

class IntBinaryTree
{
/**************************************
    Private member variables
 **************************************/
private:
    struct TreeNode
    {
        int value;          // The value in the node.
        TreeNode *left;     // Pointer to left child node.
        TreeNode *right;    // Pointer to right child node.
    };

    TreeNode *root;         // Pointer to the root node.

/****************************************
    Private member functions
 ****************************************/
private:
    // Modification functions.
    void insert(TreeNode *&, TreeNode *&);
    void destroySubtree(TreeNode *&);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);

    // Traversal functions.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;


/****************************************
    Public member functions
 ****************************************/
public:
    // Constructor.
    IntBinaryTree()
        { root = nullptr; }

    // Destructor.
    ~IntBinaryTree()
        { destroySubtree(root);
          root = nullptr; }

    // Modification operations.
    void insertNode(int);
    void remove(int);

    // Searching function.
    bool searchNode(int);

    // Traversal functions
    void displayInOrder() const;

    void displayPreOrder() const;

    void displayPostOrder() const;
};
#endif