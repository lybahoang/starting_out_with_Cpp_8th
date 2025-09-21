/**
    The BinaryTree class is a class template for a binary search tree.
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <queue>
#include <iostream>
#include <stack>
using namespace std;

/**********************************************************************
                        CLASS DEFINTINON
 **********************************************************************/
template <class T>
class BinaryTree
{
/************************************************************
                PRIVATE MEMBER VARIABLES
 ************************************************************/
private:
    // A structure for the node of the tree.
    struct TreeNode
    {
        T data;             // The data in the node.
        TreeNode *left;     // The left child of the node.
        TreeNode *right;    // The right child of the node.
    };

    // The root of the tree.
    TreeNode *root;

/************************************************************
                PRIVATE MEMBER FUNCTIONS
 ************************************************************/
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
    int width(TreeNode *) const;

/************************************************************
                PUBLIC MEMBER FUNCTIONS
 ************************************************************/
public:
    // Constructor and destructor.
    BinaryTree();
    ~BinaryTree();

    // Insertion functions.
    void insertNode(T);

    // Deletion function.
    void remove(T);

    // Display functions.
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

    // Counting function.
    int countNode() const;
    int countLeaf() const;

    // Accessor functions.
    int getHeight() const;
    int getWidth() const;

    // Searching function.
    bool searchNode(T) const;
};

/**********************************************************************
                    MEMBER FUNCTION DEFINTINON
 **********************************************************************/


/************************************************************
                CONSTRUCTOR/DESTRUCTOR
 ************************************************************/
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


/************************************************************
                INSERTION-RELATED FUNCTIONS
 ************************************************************/
/**
    The insert function (helper) actually inserts a new node
    into the tree.
    @param nodePtr The root of a subtree.
    @param newNode A new node.
 */
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // If nodePtr is nullPtr, insert newNode there.
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
    }
    // Else if the data in nodePtr is less than the data in newNode,
    // then insert newNode into the right subtree of nodePtr.
    else if (nodePtr->data < newNode->data)
    {
        insert(nodePtr->right, newNode);
    }
    // Else if the data in nodePtr is greater than the data in
    // newNode, then insert newNode into the left subtree of nodePtr.
    else if (nodePtr->data > newNode->data)
    {
        insert(nodePtr->left, newNode);
    }
    // Otherwise, the data in nodePtr is the same as that in newNode,
    // so, newNode is already in the tree, and so do nothing.
    else
    {
        return;
    }
}

/**
    The insertNode function (user interface) inserts a new node
    into the tree by calling its helper function.
    @param value The value of the new node.
 */
template <class T>
void BinaryTree<T>::insertNode(T value)
{
    // Allocate a new node and store value in it.
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert newNode into the tree.
    insert(root, newNode);
}

/************************************************************
                DELTION-RELATED FUNCTIONS
 ************************************************************/
/**
    The makeDeletion function (helper) actually removes a node
    from the tree.
    @param nodePtr The node to be deleted.
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // There are three cases to consider when it comes to deleting
    // a node out of a tree: (i) nodePtr has no children, (ii) nodePtr
    // only one child (left or right), and (iii) nodePtr has
    // two children.
    // Case 1: If nodePtr has no children, then just delete nodePtr.
    if (!nodePtr->left && !nodePtr->right)
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // Case 2: Else if nodePtr has only left child, then replace nodePtr
    // by its left child.
    else if (!nodePtr->right && nodePtr->left)
    {
        // Remember nodePtr.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the node to be
        // deleted.
        // Replace nodePtr by its left children.
        nodePtr = nodePtr->left;

        // Because the pointer is passed as a reference to a pointer, the
        // right above statement actually changes the value of the pointer.
        // Now, nodePtr is actually its left children and tempNode is
        // pointing to the node to be deleted.
        delete tempNode;
    }
    // Case 3: Else if nodePtr has only right child, then replace nodePtr
    // by its right child.
    else if (!nodePtr->left && nodePtr->right)
    {
        // Remember nodePtr.
        TreeNode *tempNode = nodePtr;

        // Now, both tempNode and nodePtr are pointing to the node to be
        // deleted.
        // Replace nodePtr by its right children.
        nodePtr = nodePtr->right;

        // Because the pointer is passed as a reference to a pointer, the
        // right above statement actually changes the value of the pointer.
        // Now, nodePtr is actually its right children and tempNode is
        // pointing to the node to be deleted.
        delete tempNode;
    }
    // Case 3: nodePtr has two children, then replace nodePtr by the rightmost
    // node in its left subtree.
    else
    {
        // Search for the rightmost node in the left subtree of nodePtr and
        // remember its parent.
        TreeNode *parent = nullptr;
        TreeNode *tempNode = nodePtr->left;
        while (tempNode->right)
        {
            parent = tempNode;
            tempNode = tempNode->right;
        }
        
        // Replace the data in nodePtr by the data in tempNode.
        nodePtr->data = tempNode->data;

        // Delete tempNode.
        if (parent)
        {
            parent->right = tempNode->left;
        }
        else
        {
            nodePtr->left = tempNode->left;
        }
        delete tempNode;
    }
}

/**
    The deleteNode function (helper) searches for a node and
    then deletes it by calling the makeDeletion function.
    @param value The value of the node to be deleted.
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::deleteNode(T value, TreeNode *&nodePtr)
{
    // If nodePtr is nullPtr, then do nothing.
    if (nodePtr == nullptr)
    {
        return;
    }
    // If the data in nodePtr is less than value, then searches
    // the target node in its right subtree.
    if (nodePtr->data < value)
    {
        deleteNode(value, nodePtr->right);
    }
    // Else if the data in nodePtr is greater than value, then
    // searches for the target node in its left subtree.
    else if (nodePtr->data > value)
    {
        deleteNode(value, nodePtr->left);
    }
    // Else if the data in nodePtr is equal to value, then
    // make deletion to nodeptr.
    else if (nodePtr->data == value)
    {
        makeDeletion(nodePtr);
    }
    // Else the node is not found, do nothing.
    else
    {
        return;
    }
}

/**
    The destroySubtree function (helper) deletes all nodes in
    a tree. The function deletes nodes using an iterative method.
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::destroySubtree(TreeNode *&nodePtr)
{
    // Create a stack to hold nodes in the tree.
    stack<TreeNode *> nodeStack;

    // Push the root onto the stack.
    if (nodePtr) nodeStack.push(nodePtr);

    // A loop to deletes all nodes in the tree.
    while (!nodeStack.empty())
    {
        // Pop the top node off the stack.
        TreeNode *currentNode = nodeStack.top();
        nodeStack.pop();

        // Push the children of the current node onto the stack
        // if any exist.
        if (currentNode->left) nodeStack.push(currentNode->left);
        if (currentNode->right) nodeStack.push(currentNode->right);
        
        // Delete the current node.
        delete currentNode;
    }
    
    // Mark the subtree root as nullptr.
    nodePtr = nullptr;
}

/**
    The remove function (user interface) deletes a node in 
    the tree.
    @param value The value of the node to be deleted.
 */
template <class T>
void BinaryTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating
    // that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot remove: The tree is empty.\n" << endl;
        return;
    }

    // If the value is not in the tree, then display a message
    // indicating that the value is not found.
    if (!this->searchNode(value))
    {
        cout << "Cannot remove: Value " << value << " not found." << endl;
        return;
    }

    // Otherwise, deletes the node.
    deleteNode(value, root);
}


/************************************************************
                DISPLAY-RELATED FUNCTIONS
 ************************************************************/
/**
    The displayInOrder function (helper) displays the tree via
    the in-order traversal (left -> root -> right).
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
    The displayInOrder function (user interface) displays the
    tree via in-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message indicating
    // that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty" << endl;
    }
    // Otherwise, displays the tree.
    else
    {
        displayInOrder(root);
    }
}

/**
    The displayPreOrder function (helper) displays the tree via
    the pre-order traversal (root -> left -> right).
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
    The displayPreOrder function (user interface) displays a tree
    via the pre-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message indicating
    // that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty" << endl;
    }
    // Otherwise, display the tree.
    else
    {
        displayPreOrder(root);
    }
}

/**
    The displayPostOrder function (helper) displays the tree via
    the post-order traversal (left -> right -> root).
    @param nodePtr The root of a subtree.
 */
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
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
    The displayPostOrder function (user interface) displays a tree
    via the post-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating
    // that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty" << endl;
    }
    // Otherwise, display the tree.
    else
    {
        displayPostOrder(root);
    }
}


/************************************************************
                COUNTING-RELATED FUNCTIONS
 ************************************************************/
/**
    The countNode function (helper) counts and returns the
    number of nodes in a tree.
    @param nodePtr The root of a subtree.
    @return The number of nodes in the subtree.
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
    return (countNode(nodePtr->left) + countNode(nodePtr->right) + 1);
}

/**
    The countNode function (user interface) returns the number
    of nodes in a tree by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode() const
{
    return countNode(root);
}

/**
    The countLeaf function (helper) counts and returns the number
    of leaves in the tree.
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
    // Otherwise.
    return countLeaf(nodePtr->left) + countLeaf(nodePtr->right);
}

/**
    The countLeaf function (user interface) returns the number
    of leaves in a tree.
    @return The number of leaves in a tree.
 */
template <class T>
int BinaryTree<T>::countLeaf() const
{
    return countLeaf(root);
}

/************************************************************
                ACCESSOR-RELATED FUNCTIONS
 ************************************************************/
/**
    The height function (helper) returns the number of levels
    in the tree.
    @param nodePtr The root of a subtree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::height(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == 0) return 0;

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int height = 0;     // The height of the tree.
    int levelSize = 0;  // The size of the current level.

    // Enqueue the nodePtr into the queuen.
    nodeQueue.push(nodePtr);

    // A loop to determine the height of the tree.
    while (!nodeQueue.empty())
    {
        // Take the size of the current level.
        levelSize = nodeQueue.size();

        // Take the front node.
        for (int count = 0; count < levelSize; count++)
        {
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }

        // Increment height.
        height++;
    }

    // Return the height of the tree.
    return height;
}

/**
    The getHeight function (user interface) returns the height
    of the tree by calling its helper function.
    @return The height of the tree.
 */
template <class T>
int BinaryTree<T>::getHeight() const
{
    return height(root);
}

/**
    The width function (helper) returns the width of the
    tree.
    @param nodePtr The root of a subtree.
    @return The width of the tree.
 */
template <class T>
int BinaryTree<T>::width(TreeNode *nodePtr) const
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr) return 0;

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue nodePtr into the queue.
    nodeQueue.push(nodePtr);

    // Declare some necessary variables.
    int width = 0;      // The width of the tree.
    int levelSize = 0;  // The size of the current level.
    
    // A loop to determine the width of the tree.
    while (!nodeQueue.empty())
    {
        // Get the size of the current level.
        levelSize = nodeQueue.size();

        // Update the width if needed.
        if (levelSize > width) width = levelSize;

        // For each node in the queue, dequeue front node and
        // enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Take the front node.
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the width of the tree.
    return width;
}

/**
    The getWidth function (user interface) retursn the number
    of levels in the tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::getWidth() const
{
    return width(root);
}


/************************************************************
                SEARCHING-RELATED FUNCTIONS
 ************************************************************/
/**
    The searchNode function (user interface) returns true if
    a value is in the tree. Otherwise, returns false.
    @param value The value to search.
    @return true if value is in the tree.
            false if value is not in the tree.
 */
template <class T>
bool BinaryTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    // A loop to search for the value.
    while (nodePtr)
    {
        // If the data in nodePtr is equal to value, then return
        // true.
        if (nodePtr->data == value) return true;
        // If the data in nodePtr is less than value, then
        // search for value in its right subtree.
        if (nodePtr->data < value) nodePtr = nodePtr->right;
        // Else if the data in nodePtr is greater than value,
        // then search for value in its left subtree.
        else if (nodePtr->data > value) nodePtr = nodePtr->left;
    }

    // Otherwise, return false.
    return false;
}
#endif