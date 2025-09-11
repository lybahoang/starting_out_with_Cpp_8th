#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

/**
 * The insert private function accepts a pointer to a subtree and a pointer
 * to a new node. It searches for the appropriate location in the subtree
 * to insert the node
 * @param nodePtr The pointer to the subtree
 * @param newNode The new node to be inserted
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
 * The insertNode operation accepts an integer value, creates a new node
 * to hold the value, and inserts it to appropriate branch in the tree
 * @param num The integer value
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

/**
 * The searchNode function returns true if a value is found in the tree
 * or false otherwise.
 * @param num The search value
 * @return True or False
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

/**
 * The displayInOrder function displays the values in the subtree
 * pointed to by nodePtr, via inorder traversal
 * @param nodePtr The pointer of the subtree
 */
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the left subtree.
        displayInOrder(nodePtr->left);

        // Display the current node's data.
        cout << nodePtr->value << endl;

        // Display the right subtree.
        displayInOrder(nodePtr->right);
    }
}

/**
 * The displayPreOrder function displays the values in the subtree
 * pointed to by nodePtr, via preorder traversal
 * @param nodePtr The pointer to the subtree
 */
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display the node's value.
        cout << nodePtr->value << endl;

        // Display the left subtree.
        displayPreOrder(nodePtr->left);

        // Display the right subtree.
        displayPreOrder(nodePtr->right);
    }
}

/**
 * The displayPostOrder function displays the values in the subtree
 * pointed to by nodePtr, via postorder traversal
 * @param nodePtr The pointer to the subtree
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
        cout << nodePtr->value << endl;
    }
}

/**
 * The deleteNode function deletes the node whose value member is
 * the same as num
 * @param num The value to be deleted
 * @param nodePtr The pointer to the subtree
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
 * The makeDeletion function takes a reference to a pointer to the node
 * that is to be deleted. The node is removed and the branches of the
 * tree below the node are attached
 * @param nodePtr The node to be deleted
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
    // If nodePtr has two children.
    else
    {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}
/**
 * The remove function removes a node whose value is equal to num
 * @param num The value to be deleted
 */
void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}