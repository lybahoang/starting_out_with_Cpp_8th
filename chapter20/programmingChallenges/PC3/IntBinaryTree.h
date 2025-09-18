#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
/**************************************************
            Private member variables
***************************************************/
private:
    // A structure for the tree node.
    struct TreeNode
    {
        int value;          // The value in the node.
        TreeNode *left;     // The left child of the node.
        TreeNode *right;    // The right child of the node.
    };

    TreeNode *root;         // The root of the tree.

/**************************************************
            Private member functions
***************************************************/
private:
    // Insertion functions.
    void insert(TreeNode *&, TreeNode *&);

    // Deletion functions.
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void destroySubtree(TreeNode *&);

    // Display functions.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

    // Count functions
    int countLeaf(TreeNode *) const;
    int countNode(TreeNode *) const;

/**************************************************
            Public member variables
***************************************************/
public:
    // Constructor.
    IntBinaryTree();

    // Destructor.
    ~IntBinaryTree();

    // Insertion function.
    void insertNode(int);

    // Deletion functions.
    void remove(int);

    // Display functions.
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

    // Count functions.
    int countNode() const;
    int countLeaf() const;

    // Search functions.
    bool searchNode(int) const;
};
#endif