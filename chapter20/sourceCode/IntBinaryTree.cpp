#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

/**************************************
    Insertion-related functions
 **************************************/
/**
    The insert private function accepts a pointer to a subtree and a pointer
    to a new node. It searches for the appropriate location in the subtree
    to insert the node.
    @param nodePtr The pointer to the subtree
    @param newNode The new node to be inserted
 */
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
    
}

/**
    The insertNode operation accepts an integer value, creates a new node
    to hold the value, and inserts it to appropriate branch in the tree.
    This is the public interface.
    @param num The integer value
 */
void IntBinaryTree::insertNode(int num)
{
    // Allocate a new node and store num in it.
    TreeNode *newNode = new TreeNode;
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}



/**************************************
        Searching function.
 **************************************/
/**
    The searchNode function returns true if a value is found in the tree
    or false otherwise.
    @param num The search value
    @return True or False
 */
bool IntBinaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    while (nodePtr)
    {
        if (nodePtr->value == num)
            return true;
        else if (nodePtr->value > num)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}



/**************************************
    Traversal/Display functions
 **************************************/
/**
    The displayInOrder (public interface) function displays all values in
    the binary tree in inorder traversal.
 */
void IntBinaryTree::displayInOrder() const
{
    // If the tree is empty, then display a message indicating that the
    // tree is empty.
    if (root == nullptr)
    {
        cout << "No values to display: The tree is empty.\n";
    }
    // Otherwise, displays all values in the tree.
    else
    {
        displayInOrder(root);
    }
}

/**
    The displayInOrder (helper) function displays the values in the subtree
    pointed to by nodePtr, via inorder traversal
    @param nodePtr The pointer of the subtree
 */
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayInOrder(nodePtr->left);

        // Display the current node's data.
        cout << nodePtr->value << "  ";

        // Display the right subtree.
        displayInOrder(nodePtr->right);
    }
}

/**
    The displayPreOrder (public interface) function displays all values in 
    a binary tree in preorder traversal
 */
void IntBinaryTree::displayPreOrder() const
{
    // If the tree is empty, then display a message indicating that the
    // tree is empty.
    if (root == nullptr)
    {
        cout << "No values to display: The tree is empty.\n";
    }
    // Otherwise, displays all values in the tree.
    else
    {
        displayPreOrder(root);
    }
}

/**
    The displayPreOrder (helper) function displays the values in the subtree
    pointed to by nodePtr, via preorder traversal
    @param nodePtr The pointer to the subtree
 */
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the node's value.
        cout << nodePtr->value << "  ";

        // Display the left subtree.
        displayPreOrder(nodePtr->left);

        // Display the right subtree.
        displayPreOrder(nodePtr->right);
    }
}

/**
    The displayPostOrder (public interface) function displays all values in
    a binary tree via postorder traversal
 */
void IntBinaryTree::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating that the
    // tree is empty.
    if (root == nullptr)
    {
        cout << "No values to display: The tree is empty.\n";
    }
    // Otherwise, displays all values in the tree.
    else
    {
        displayPostOrder(root);
    }
}

/**
    The displayPostOrder function displays the values in the subtree
    pointed to by nodePtr, via postorder traversal
    @param nodePtr The pointer to the subtree
 */
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayPostOrder(nodePtr->left);

        // Display the right subtree.
        displayPostOrder(nodePtr->right);

        // Display the current node's value.
        cout << nodePtr->value << "  ";
    }
}



/**************************************
    Deletion-related functions.
 **************************************/
/**
    The remove function removes a node whose value is equal to num.
    This is the public interface.
    @param num The value to be deleted
 */
void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}


/**
    The deleteNode function deletes the node whose value member is
    the same as num
    @param num The value to be deleted
    @param nodePtr The pointer to the subtree
 */
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

/**
    The makeDeletion function takes a reference to a pointer to the node
    that is to be deleted. The node is replaced by the rightmost node in
    its left subtree if the node has two children.
    @param nodePtr The node to be deleted
 */
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    // Define a temporary pointer to use in reattaching the left node.
    TreeNode *tempNodePtr = nullptr;

    // If the node is empty, then display a message.
    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    // Else if the left subtree is a nullptr.
    else if (nodePtr->left == nullptr)
    {   
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    // Eles if the right subtree is a nullptr.
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    // If nodePtr has two children, then replace the rightmost node
    // in the target node's subtree into the target node.
    else
    {
        // Move one node to the left.
        tempNodePtr = nodePtr->left;
        // Find the rightmost node in the target node's left subtree.
        while (tempNodePtr->right) {
            tempNodePtr = tempNodePtr->right;
        }

        // Replace the value in the target node by the value in the
        // rightmost node (now pointed by tempNodePtr).
        nodePtr->value = tempNodePtr->value;

        // Delete the rightmost node (or tempNodePtr).
        deleteNode(tempNodePtr->value, nodePtr->left);
    }
}

/**
    The destroySubtree function deletes all nodes in a subtree from a
    particular node via post-order traversal
    @param nodePtr The root of a subtree
 */
void IntBinaryTree::destroySubtree(TreeNode *&nodePtr)
{
    if (nodePtr)
    {
        // Destroy the left subtree.
        destroySubtree(nodePtr->left);
        
        // Destroy the right subtree.
        destroySubtree(nodePtr->right);

        // Delete the current node.
        delete nodePtr;
        nodePtr = nullptr;
    }
}