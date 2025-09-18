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
            Deletion-related functions
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

/**
    The remove function (user interface) calls the deleteNode
    function to delete a node
    @param value The value to be deleted
 */
template <class T>
void BinarySearchTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating
    // that the is empty.
    if (root == nullptr)
        cout << "Cannot remove: Empty tree now.\n";
    // Otherwise, delete node.
    else
        deleteNode(value, root);
}

/**
    The deleteNode function (helper) searches for the node to be
    deleted and call the makeDeletion function to remove the node
    from the tree
    @param value The value to be deleted
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::deleteNode(T value, TreeNode *&nodePtr)
{
    // If the data in nodePtr is less than value, then search
    // for the right subtree.
    if (nodePtr->data < value)
        deleteNode(value, nodePtr->right);
    // If the data in nodePtr is greater than value, the search
    // for the left subtree.
    else if (nodePtr->data > value)
        deleteNode(value, nodePtr->left);
    // Otherwise, delete node.
    else
        makeDeletion(nodePtr);
}

/**
    The makeDeletion function (helper) actually deletes a node
    from a tree
    @param nodePtr The node to be deleted
 */
template <class T>
void BinarySearchTree<T>::makeDeletion(TreeNode *&nodePtr)
{   
    // If nodePtr is nullptr, then do nothing.
    if (nodePtr == nullptr)
        return;

    // If nodePtr has only right child.
    if (nodePtr->left == nullptr)
    {
        // Save the current node.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the same node.
        // Make nodePtr point to its right subtree.
        nodePtr = nodePtr->right;

        // Now, nodePtr is pointing to its right subtree and tempNode is
        // pointing to the node that is going to be deleted.
        delete tempNode;
        tempNode = nullptr;
    }
    // If nodePtr has only left child.
    else if (nodePtr->right == nullptr)
    {
        // Save the current node.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the same node.
        // Make nodePtr point to its left subtree.
        nodePtr = nodePtr->left;

        // Now, nodePtr is pointing to its left subtree and tempNode is
        // pointing to the node that is going to be deleted.
        delete tempNode;
        tempNode = nullptr;
    }
    // If nodePtr has two children, then replace nodePtr by the rightmost 
    // leaf in its left subtree.
    else
    {
        // Search for the rightmost leaf in nodePtr's left subtree.
        TreeNode *tempNode = nodePtr->left;
        while (tempNode->right)
            tempNode = tempNode->right;

        // Replace nodePtr by tempNode.
        nodePtr->data = tempNode->data;

        // Delete tempNode.
        deleteNode(nodePtr->data, nodePtr->left);
    }
}



/**************************************************
            Display-related functions
 **************************************************/

/**
    The displayInOrder function (helper) displays the tree via
    the inorder traversal (left -> root -> right).
    @param nodePtr The root of a subtree
*/
template <class T>
void BinarySearchTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayInOrder(nodePtr->left);

        // Display the root data.
        cout << nodePtr->data << "  ";

        // Display the right subtree.
        displayInOrder(nodePtr->right);
    }
}

/**
    The displayInOrder function (user interface) displays the tree
    via the inorder traversal by calling the helper function
 */
template <class T>
void BinarySearchTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is currently empty.
    if (root == nullptr)
        cout << "The tree is empty. No content to display" << endl;
    // Otherwise, display the tree.
    else
        displayInOrder(root);
}

/**
    The displayPreOrder function (helper) displays the tree via the
    preorder traversal (root -> left -> right)
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the root data.
        cout << nodePtr->data << "  ";
        
        // Display the left subtree.
        displayPreOrder(nodePtr->left);

        // Display the right subtree.
        displayPreOrder(nodePtr->right);
    }
}

/**
    The displayPreOrder function (user interface) displays the tree
    via the preorder traversal by calling its helper function
 */
template <class T>
void BinarySearchTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is currently empty.
    if (root == nullptr)
        cout << "The tree is empty. No content to display" << endl;
    // Otherwise, display the tree.
    else
        displayPreOrder(root);
}

/**
    The displayPostOrder function (helper) displays the tree via the
    postorder traversal (left -> right -> root)
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayPostOrder(nodePtr->left);

        // Display the right subtree.
        displayPostOrder(nodePtr->right);

        // Display the root data.
        cout << nodePtr->data << "  ";
    }
}

/**
    The displayPostOrder function (user interface) displays the tree via
    the postorder traversal by calling its helper function
 */
template <class T>
void BinarySearchTree<T>::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is currently empty.
    if (root == nullptr)
        cout << "The tree is empty. No content to display" << endl;
    // Otherwise, display the tree.
    else
        displayPostOrder(root);
}


/**************************************************
          Insertion-related functions
 **************************************************/

/**
    The insert method (helper) inserts a node into a tree
    @param nodePtr The root of a subtree
    @param newNode The new node.
 */
template <class T>
void BinarySearchTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // If nodePtr is nullptr, then insert newNode there.
    if (nodePtr == nullptr)
        nodePtr = newNode;
    // Else if the data in nodePtr is less than that in newNode, then
    // insert newNode in its right subtree.
    else if (nodePtr->data < newNode->data)
        insert(nodePtr->right, newNode);
    // Else if the data in nodePtr is greater than that in newNode,
    // then insert newNode in nodePtr's left subtree.
    else if (nodePtr->data > newNode->data)
        insert(nodePtr->left, newNode);
    // Otherwise, do nothing.
    else
        return;
}

/**
    The insertNode function (user interface) creates a new node and
    adds it to the tree
    @param value The data of new node
 */
template <class T>
void BinarySearchTree<T>::insertNode(T value)
{
    // Allocate a new node and store value in it.
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert newNode.
    insert(root, newNode);
}


/**************************************************
            Count-related functions
 **************************************************/

/**
    The count function (helper) counts the number of nodes in a tree
    @param nodePtr The root of a subtree
    @return The number of nodes in the tree
 */
template <class T>
int BinarySearchTree<T>::count(TreeNode *nodePtr) const
{
    // Base case: If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
        return 0;
    // Otherwise, return the total of nodes in nodePtr's left subtree,
    // right subtree, and the root.
    return (1 + count(nodePtr->left) + count(nodePtr->right));
}

/**
    The countNode function (user interface) counts and returns the number
    of nodes in a tree by calling its helper function
    @return The number of nodes in the tree
 */
template <class T>
int BinarySearchTree<T>::countNode() const
{
    return count(root);
}


/**************************************************
                Other functions
 **************************************************/
template <class T>
bool BinarySearchTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    // Traverse the tree.
    while (nodePtr)
    {
        // If the data in the current node is equal to the desired
        // value, then return true.
        if (nodePtr->data == value)
            return true;
        // Else if the data in the current node is less than the desired
        // value, then search for the right subtree.
        else if (nodePtr->data < value)
            nodePtr = nodePtr->right;
        // Otherwise, move the nodePtr's left subtree.
        else
            nodePtr = nodePtr->left;
    }

    // If the desired value is not found, then return false.
    return false;
}
#endif