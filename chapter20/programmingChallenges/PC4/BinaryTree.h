/**
    The BinaryTree class represents a template for binary search tree.
 */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BinaryTree
{
/**********************************************************************
            PRIVATE MEMBER VARIABLES
 **********************************************************************/
private:
    // A structure for the tree node.
    struct TreeNode
    {
       T data;          // The data of the node.
       TreeNode *left;  // The left child of the node.
       TreeNode *right; // The right child of the node. 
    };

    // The root of the tree.
    TreeNode *root;

/*********************************************************************
            PRIVATE MEMBER FUNCTIONS
 **********************************************************************/
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
    int countNode(TreeNode *) const;
    int countLeaf(TreeNode *) const;

    // Accessor helper functions.
    int height(TreeNode *) const;

/*********************************************************************
            PUBLIC MEMBER FUNCTIONS
 **********************************************************************/
public:
    // Constructor.
    BinaryTree();

    // Destructor.
    ~BinaryTree();

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
    int countLeaf() const;

    // Searching function.
    bool searchNode(T) const;

    // Accessor functions.
    int getHeight() const;
};

/*********************************************************************
                    CONSTRUCTOR/DESTRUCTOR
 **********************************************************************/

/**
    The constructor creates an empty tree.
 */
template <class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

/**
    The destructor deletes all nodes in the tree.
 */
template <class T>
BinaryTree<T>::~BinaryTree()
{
    destroySubtree(root);
    root = nullptr;
}


/*********************************************************************
                    INSERTION-RELATED FUNCTIONS
 **********************************************************************/

/**
    The insert function (helper) actually inserts a new node into the
    tree
    @param nodePtr The root of a subtree
    @param newNode A new node
 */
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // If nodePtr is nullptr, then insert newNode there.
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
    }
    // Else if the data in nodePtr is less than the data in newNode, then
    // insert newNode into the right subtree of nodePtr.
    else if (nodePtr->data < newNode->data)
    {
        insert(nodePtr->right, newNode);
    }
    // Else if the data in nodePtr is greater than the data in newNode,
    // then insert newNode into the left subtree of nodePtr.
    else if (nodePtr->data > newNode->data)
    {
        insert(nodePtr->left, newNode);
    }
    // Otherwise, the new node is already in the tree, so do nothing.
    else
    {
        return;
    }
}

/**
    The insertNode method (user interface) inserts a new node into the
    tree
    @param newData The data of the new node.
 */
template <class T>
void BinaryTree<T>::insertNode(T newData)
{
    // Allocate a new node and store data in it.
    TreeNode *newNode = new TreeNode;
    newNode->data = newData;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert newNode into the tree.
    insert(root, newNode);
}


/*********************************************************************
                    DELETION-RELATED FUNCTIONS
 **********************************************************************/

/**
    The makeDeletion function (helper) actually removes a node from the 
    tree.
    @param nodePtr The node to be deleted.
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // Because nodePtr may be a null pointer, I check for a null pointer
    // first. If nodePtr is nullptr, then do nothing.
    if (nodePtr == nullptr)
    {
        return;
    }
    // At this time, there are three case for me to consider: (i) nodePtr
    // has no children, (ii) nodePtr has only one child (left or right),
    // and (iii) nodePtr has two children.
    // If nodePtr has no children, then just delete nodePtr.
    if (nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // Else if nodePtr has only left child, then replace nodePtr by its
    // left child.
    else if (nodePtr->right == nullptr)
    {
        // Save nodePtr.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the node that is
        // going to be deleted.
        // Make nodePtr point to its left child.
        nodePtr = nodePtr->left;

        // Now, tempNode is pointing to the node that is going to be deleted,
        // while nodePtr is pointing to its left children.
        // Now, I just delete tempNode.
        delete tempNode;
    }
    // Else if nodePtr has only right child, then replace nodePtr by its
    // right child.
    else if (nodePtr->left == nullptr)
    {
        // Save nodePtr.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the node that is
        // going to be deleted.
        // Make nodePtr point to its right child.
        nodePtr = nodePtr->right;

        // Now, tempNode is pointing to the node that is going to be deleted,
        // while nodePtr is pointing to its right child.
        // Now, I just delete tempNode.
        delete tempNode; 
    }
    // Otherwise, nodePtr has two children. I replace nodePtr by the rightmost
    // node in its left subtree.
    else 
    {
        // Search for the rightmost node in the left subtree of nodePtr.
        TreeNode *rightmostNode = nodePtr->left;
        while (rightmostNode->right)
            rightmostNode = rightmostNode->right;
        
        // Replace the data in nodePtr by the data in rightmostNode.
        nodePtr->data = rightmostNode->data;

        // Delete rightmostNode.
        deleteNode(nodePtr->data, nodePtr->left);
        rightmostNode = nullptr;
    }
}

/**
    The deleteNode function (helper) deletes a node from a tree by calling
    the makeDeletion function
    @param value The value to be deleted.
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::deleteNode(T value, TreeNode *&nodePtr)
{
    // If the data in nodePtr is less than value, then delete node in the
    // right subtree of nodePtr.
    if (nodePtr->data < value)
    {
        deleteNode(value, nodePtr->right);
    }
    // Else if the data in nodePtr is greater than value, then delete node
    // in the left subtree of nodePtr.
    else if (nodePtr->data > value)
    {
        deleteNode(value, nodePtr->left);
    }
    // Else, delete current node (nodePtr can be a nullptr).
    // In this else case, if no node in the tree is the same as value
    // a null pointer is passed into makeDeletion. If the nodePtr is found
    // then it is passed into makeDeletion.
    else
    {
        makeDeletion(nodePtr);
    }
}

/**
    The remove method (user interface) removes a node from the tree.
    @param value The value of the node.
 */
template <class T>
void BinaryTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "Cannot remove: The tree is empty." << endl;
    // Otherwise, delete node.
    else deleteNode(value, root);
}

/**
    The destroySubtree function (helper) deletes all nodes in a subtree.
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::destroySubtree(TreeNode *&nodePtr)
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

/*********************************************************************
                    DISPLAY-RELATED FUNCTIONS
 **********************************************************************/

/**
    The displayInOrder function (helper) displays the tree via the
    in-order traversal (left -> root -> right).
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
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
    via the in-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message indicating that the
    // tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, call the helper function.
    else
    {
        displayInOrder(root);
    }
}

/**
    The displayPreOrder function (helper) displays the tree via the
    pre-order traversal (root -> left -> right).
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
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
    The displayPreOrder function (user interface) displays the tree via
    the pre-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message indicating that the tree
    // is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, call its helper function.
    else
    {
        displayPreOrder(root);
    }
}

/**
    The displayPostOrder function (helper) displays the tree via the
    post-order traversal (left -> right -> root).
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        
        // Display the left subtree.
        displayPreOrder(nodePtr->left);
        
        // Display the right subtree.
        displayPreOrder(nodePtr->right);
        
        // Display the root data.
        cout << nodePtr->data << "  ";
    }
}

/**
    The displayPostOrder function (user interface) displays the tree via
    the post-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating that the tree
    // is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, call its helper function.
    else
    {
        displayPostOrder(root);
    }
}


/*********************************************************************
                    COUNTING-RELATED FUNCTIONS
 **********************************************************************/

/**
    The countNode function (helper) counts and returns the number of nodes
    in the tree.
    @param nodePtr The root of a subtree.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
    {
        return 0;
    }
    // Otherwise.
    return countNode(nodePtr->left) + countNode(nodePtr->right) + 1;
}

/**
    The countNode function (user interface) returns the number of nodes
    in the tree by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode() const
{
    return countNode(root);
}

/**
    The countLeaf function (helper) counts and returns the number of leaves
    in the tree.
    @param nodePtr The root of a subtree.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
    {
        return 0;
    }
    // If nodePtr has no children, then return 1.
    if (!nodePtr->left && !nodePtr->right)
    {
        return 1;
    }
    // Otherwise, return the sum of leaves in the left subtree and the right
    // subtree.
    return countLeaf(nodePtr->left) + countLeaf(nodePtr->right);
}

/**
    The countLeaf function (user interface) returns the number of leaves in
    the tree by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf() const
{
    return countLeaf(root);
}


/*********************************************************************
                    ACCESSOR-RELATED FUNCTIONS
 **********************************************************************/

/**
    The height function (helper) returns the height of the tree (or the
    maximum number of edges from the root to the deepest node).
    @param nodePtr The root of a subtree.
    @return The height of the tree.
 */
template <class T>
int BinaryTree<T>::height(TreeNode *nodePtr) const
{
    // Create a queue to store the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Create some necessary variables.
    int levelSize;      // The size of the current level.
    int height = 0;     // The height of the tree.

    // Enqueue the root into the queue.
    nodeQueue.push(nodePtr);

    // The loop to determine the height of the tree.
    while (!nodeQueue.empty())
    {
        // Take the size of the current level (or the number of nodes
        // in the current level).
        levelSize = nodeQueue.size();

        // For each node in the queue, dequeue it and enqueue its children.
        for (int nodeCount = 0; nodeCount < levelSize; nodeCount++)
        {
            // Take the front node.
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }

        // Increment the height variable.
        height++;
    }

    // Return the height of the tree.
    return (height - 1);
}

/**
    The getHeight function (user interface) returns the height of the tree.
    @return The height of the tree.
 */
template <class T>
int BinaryTree<T>::getHeight() const
{
    return height(root);
}


/*********************************************************************
                    SEARCHING-RELATED FUNCTIONS
 **********************************************************************/

/**
    The searchNode function (user interface) returns true if a node exists
    in the tree. Otherwise, it returns false.
    @param value The value to be deleted.
 */
template <class T>
bool BinaryTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    // The loop to search for the node.
    while (nodePtr)
    {
        // If the data of the current node is equal to value, then
        // return true.
        if (nodePtr->data == value)
            return true;
        // If the data of the current node is less than value, then
        // search in the right subtree of nodePtr.
        if (nodePtr->data < value)
            nodePtr = nodePtr->right;
        // Otherwise, search in the left subtree of nodePtr.
        else
            nodePtr = nodePtr->left;
    }

    // Return false if the node is not found.
    return false;
}
#endif