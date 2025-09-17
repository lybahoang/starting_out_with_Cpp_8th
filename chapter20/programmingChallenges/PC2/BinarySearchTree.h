/**
    The BinarySearchTree class is a generic template class for a
    binary search tree
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
/**************************************************
            Private member variables
 **************************************************/
private:
    // A structure for the tree node.
    struct TreeNode
    {
        T data;             // The data in the node.
        TreeNode *left;     // The left child of the node.
        TreeNode *right;    // The right child of the node.
    };

    TreeNode *root;         // The root of the tree.

/**************************************************
         Private helper member functions
 **************************************************/
private:
    // Insertion helper functions.
    void insert(TreeNode *&, TreeNode *&);

    // Deletion helper functions.
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void destroySubtree(TreeNode *&);

    // Display helper functions.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

    // Counting helper functions.
    int count(TreeNode *) const;

/**************************************************
            Public member variables
 **************************************************/
public:
    // Constructor.
    BinarySearchTree();

    // Destructor.
    ~BinarySearchTree();

    // Insertion functions.
    void insertNode(T);

    // Deletion functions.
    void remove(T);

    // Display functions.
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

    // Counting functions.
    int countNode() const;

    // Searching functions.
    bool searchNode(T) const;
};

/**************************************************
            Constructor/Destructor
 **************************************************/

/**
    The constructor creates an empty binary search tree
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

/**
    The destructor deletes all nodes in the tree
 */
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    destroySubtree(root);
    root = nullptr;
}


/**************************************************
        Deletion-related helper functions
 **************************************************/

/**
    The destroySubtree function (helper) deletes all nodes in
    a subtree
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::destroySubtree(TreeNode *&nodePtr)
{
    if (nodePtr)
    {
        // Delete all nodes in the left subtree.
        destroySubtree(nodePtr->left);

        // Delete all nodes in the right subtree.
        destroySubtree(nodePtr->right);

        // Delete the current node.
        delete nodePtr;
        nodePtr = nullptr;
    }
}

#endif