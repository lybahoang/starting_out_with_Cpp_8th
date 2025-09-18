#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

/**************************************************
            Constructor/Destructor
***************************************************/

/**
    The constructor creates an empty tree
 */
IntBinaryTree::IntBinaryTree()
{
    root = nullptr;
}

/**
    The destructor deletes all nodes in the tree
 */
IntBinaryTree::~IntBinaryTree()
{
    destroySubtree(root);
    root = nullptr;
}


/**************************************************
        Insertion-related member functions
***************************************************/

/**
    The insert function (helper) inserts a new node into
    the tree
    @param nodePtr The root of a subtree
    @param newNode The new node
 */
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // If nodePtr is nullptr, then insert newNode there.
    if (nodePtr == nullptr)
        nodePtr = newNode;
    // Else if the value in nodePtr is less than that in newNode,
    // then insert newNode into nodePtr's right subtree.
    else if (nodePtr->value < newNode->value)
        insert(nodePtr->right, newNode);
    // Else if the value in nodePtr is greater than that in
    // newNode, then insert newNode into nodePtr's left subtree.
    else if (nodePtr->value > newNode->value)
        insert(nodePtr->left, newNode);
    // Otherwise, the value in nodePtr is equal to that in newNode,
    // do nothing
    else
        return;
}

/**
    The insertNode function (user interface) inserts a new node into
    the tree by calling its helper function
    @param num The value of new node
 */
void IntBinaryTree::insertNode(int num)
{
    // Allocate a new node and store num in it.
    TreeNode *newNode = new TreeNode;
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert newNode into the tree.
    insert(root, newNode);
}


/**************************************************
        Deletion-related member functions
***************************************************/

/**
    The remove function (user interface) deletes a node containing
    a specific value by calling its helper function
    @param num The value to be deleted
 */
void IntBinaryTree::remove(int num)
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "The tree is empty. Cannot remove" << endl;
    // Otherwise, delete the node.
    else
        deleteNode(num, root);
}

/**
    The deleteNode function (helper) searches for and delete a node
    whose value is specified
    @param num The value of the node
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    // If nodePtr is a null pointer, then do nothing.
    if (nodePtr == nullptr)
        return;

    // If value in nodePtr is less than num, then search for
    // the node in its right subtree.
    if (nodePtr->value < num)
        deleteNode(num, nodePtr->right);
    // If value in nodePtr is greater than num, then search for
    // the node in its left subtree.
    else if (nodePtr->value > num)
        deleteNode(num, nodePtr->left);
    // Otherwise, delete nodePtr.
    else
        makeDeletion(nodePtr);    
}

/**
    The makeDeletion function (helper) actually deletes a node in a tree
    @param nodePtr The node to be deleted
 */
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    // If nodePtr has only one child and the child is on its left.
    if (nodePtr->right == nullptr)
    {
        // Save the current node.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the same node.
        // Make nodePtr point to its left subtree.
        nodePtr = nodePtr->left;

        // Now, tempNode is pointing to the node to be deleted and nodePtr
        // is pointing to the left subtree of nodePtr.
        delete tempNode;
    }
    // If nodePtr has only one child and the child is on its right.
    else if (nodePtr->right == nullptr)
    {
        // Save the current node.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the same node.
        // Make nodePtr point to its right subtree.
        nodePtr = nodePtr->right;

        // Now, tempNode is pointing to the node to be deleted and nodePtr
        // is pointing to the right subtree of nodePtr.
        delete tempNode;
    }
    // If nodePtr has two children, the replace nodePtr by the rightmost node
    // in its left subtree.
    else
    {
        // Search for the rightmost node in nodePtr's left subtree.
        TreeNode *tempNode = nodePtr->left;
        while (tempNode->right)
            tempNode = tempNode->right;
        
        // Replace nodePtr by the rightmost node.
        nodePtr->value = tempNode->value;

        // Delete tempNode;
        deleteNode(nodePtr->value, nodePtr->left);
    }
}


/**
    The destroySubtree function (helper) deletes all nodes in a tree
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::destroySubtree(TreeNode *&nodePtr)
{
    if (nodePtr)
    {
        // Delete all nodes in nodePtr's left subtree.
        destroySubtree(nodePtr->left);

        // Delete all nodes in nodePtr's right subtree.
        destroySubtree(nodePtr->right);

        // Delete nodePtr.
        delete nodePtr;
        nodePtr = nullptr;
    }
}

/**************************************************
        Display-related member functions
***************************************************/

/**
    The displayInOrder function (helper) displays the contents
    in a tree via in-order traversal (left -> root -> right)
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayInOrder(nodePtr->left);

        // Display the root value.
        cout << nodePtr->value << "  ";

        // Display the right subtree.
        displayInOrder(nodePtr->right);
    }
}

/**
    The displayInOrder function (user interface) displays the contents
    of a tree via in-order traversal by calling its helper function
 */
void IntBinaryTree::displayInOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "Empty tree. No content to display" << endl;
    // Otherwise, display the tree.
    displayInOrder(root);
}

/**
    The displayPreOrder function (helper) displays the contents of a
    tree via pre-order traversal (root -> left -> right)
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the root content.
        cout << nodePtr->value << "  ";

        // Display the left subtree.
        displayPreOrder(nodePtr->left);

        // Display the right subtree.
        displayPreOrder(nodePtr->right);
    }
}

/**
    The displayPreOrder function (user interface) displays the contents
    of a tree via pre-order traversal by calling its helper function
 */
void IntBinaryTree::displayPreOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "Empty tree. No content to display" << endl;
    // Otherwise, display the tree.
    displayPreOrder(root);
}

/**
    The displayPostOrder function (helper) displays the contents of a
    tree via post-order traversal (left -> right -> root)
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayPostOrder(nodePtr->left);

        // Display the right subtree.
        displayPostOrder(nodePtr->right);

        // Display the root content.
        cout << nodePtr->value << "  ";
    }
}

/**
    The displayPostOrder function (user interface) displays the contents
    of a tree via post-order traversal by calling its helper function
 */
void IntBinaryTree::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "Empty tree. No content to display" << endl;
    // Otherwise, display the tree.
    displayPostOrder(root);
}



/**************************************************
        Count-related member functions
***************************************************/

/**
    The countNode function (helper) actually counts and returns the
    number of nodes in a tree
    @param nodePtr The root of a subtree
 */
int IntBinaryTree::countNode(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
        return 0;
    // Otherwise.
    return (1 + countNode(nodePtr->left) + countNode(nodePtr->right));
}

/**
    The countNode function (user interface) counts and returns the
    number of nodes in a tree by calling its helper function
 */
int IntBinaryTree::countNode() const
{
    return countNode(root);
}

/**
    The countLeaf function (helper) counts and returns the number of
    leaves in a tree
    @param nodePtr The root of a subtree
 */
int IntBinaryTree::countLeaf(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
        return 0;
    // If nodePtr is not a nullptr and has no children, return 1.
    if (!nodePtr->left && !nodePtr->right)
        return 1;
    // Otherwise.
    return (countLeaf(nodePtr->left) + countLeaf(nodePtr->right));
}

/**
    The countLeaf function (user interaface) counts and returns the
    number of leaves in a tree by calling its helper function
 */
int IntBinaryTree::countLeaf() const
{
    return countLeaf(root);
}

/**************************************************
        Search-related member functions
***************************************************/

/**
    The searchNode function (user interface) return true if a value
    is in the tree. Otherwise, it returns false
    @param num The desired value
 */
bool IntBinaryTree::searchNode(int num) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    // Traverse the tree.
    while (nodePtr)
    {
        // If num is equal to the value in nodePtr, then return true.
        if (num == nodePtr->value)
            return true;
        // Else if num is less than the value in nodePtr, then search
        // in nodePtr's left subtree.
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        // Otherwise, search for num in nodePtr's right subtree.
        else
            nodePtr = nodePtr->right;
    }

    // Return false, if num is not found.
    return false;
}