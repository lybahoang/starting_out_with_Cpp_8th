/**
    The BinarySearchTree class is a template class for a binary search tree.
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
/***************************************************
            Private member variables
****************************************************/
private:
    // A structure for the tree node.
    struct TreeNode
    {
        T data;             // The data in the node.
        TreeNode *left;     // The left child of the node.
        TreeNode *right;    // The right child of the node.
    };

    TreeNode *root;     // The root of the tree.

/***************************************************
            Private member functions
****************************************************/
private:
    // Insertion helper functions.
    void insert(TreeNode *, TreeNode *&);

    // Deletion helper functions.
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void destroySubtree(TreeNode *&);

    // Traversal helper functions.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

/***************************************************
            Public member variables
****************************************************/
public:
    // Constructor.
    BinarySearchTree();

    // Destructor.
    ~BinarySearchTree();

    // Searching functions.
    bool searchNode(T) const;

    // Insertion functions (user interface).
    void insertNode(T);
    
    // Deletion functions (user interface).
    void remove(T);

    // Traversal/Display functions (user interface).
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
};

/***************************************************
            Constructor/Destructor
****************************************************/
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
    this->destroySubtree(root);
    root = nullptr;
}


/***************************************************
            Searching-related functions
****************************************************/
/**
    The searchNode function (user interface) returns true if a node holding
    a specified data is in the tree. Otherwise, it returns false
    @param value The data to search for
 */
template <class T>
bool BinarySearchTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.

    // Look for the value in the tree.
    while (nodePtr)
    {
        // If the value in the current node is the desired value, then
        // return true.
        if (nodePtr->data == value)
            return true;
        // Else if the value in the current node is less than the desired
        // value, then search for the right subtree.
        else if (nodePtr->data < value)
            nodePtr = nodePtr->right;
        // Otherwise, search for the left subtree.
        else
            nodePtr = nodePtr->left;
    }

    // If the desired value is not found in the tree, then return false.
    return false;
}


/***************************************************
            Insertion-related functions
****************************************************/
/**
    The insert function (helper) adds a new node to the tree
    @param newNode The new node added to the tree
    @param nodePtr The node that the new node is inserted into
 */
template <class T>
void BinarySearchTree<T>::insert(TreeNode *newNode, TreeNode *&nodePtr)
{
    // If nodePtr is nullPtr, insert newNode there.
    if (nodePtr == nullptr)
        nodePtr = newNode;
    // Else if the value in newNode is greater than that in newNode,
    // then call the function again for the nodePtr's right subtree.
    else if (newNode->data > nodePtr->data)
        insert(newNode, nodePtr->right);
    // Otherwise, call the function again for nodePtr's left subtree.
    else
        insert(newNode, nodePtr->left);
}

/**
    The insertNode function (user interface) creates a new node and calls
    the insert function to insert a new node into the tree
    @param value The data of the new node
 */
template <class T>
void BinarySearchTree<T>::insertNode(T value)
{
    // Allocate a new node and store value in it.
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Call the insert function to add newNode to the tree.
    insert(newNode, root);
}

/***************************************************
            Deletion-related functions
****************************************************/
/**
    The remove function (user interface) deletes a node containing a
    specified data in the tree
    @param value The value to be removed
 */
template <class T>
void BinarySearchTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating
    // that the tree is empty.
    if (root == nullptr)
        cout << "Cannot remove: Empty tree now" << endl;
    // Otherwise, call the deleteNode function.
    else
        deleteNode(value, root);
}

/**
    The deleteNode function (helper) finds the node containing the
    specified value and calls the function makeDeletion with the
    found node so that the node will be deleted
    @param value The value to be removed
    @param nodePtr The root of the subtree to search for the node
                   containing the value
 */
template <class T>
void BinarySearchTree<T>::deleteNode(T value, TreeNode *&nodePtr)
{
    // If the value in nodePtr is less than value, then call the
    // function again for the nodePtr's right subtree.
    if (nodePtr->data < value)
        deleteNode(value, nodePtr->right);
    // Otherwise, call the function again for the nodePtr's left subtree.
    else if (nodePtr->data > value)
        deleteNode(value, nodePtr->left);
    else
        deleteNode(value, nodePtr);
}

/**
    The makeDeletion function (helper) actually deletes a node from
    the tree
    @param nodePtr The node to be deleted
 */
template <class T>
void BinarySearchTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // If nodePtr is nullPtr, then do nothing
    if (nodePtr == nullptr)
        return;

    // If the left subtree is nullptr.
    if (nodePtr->left == nullptr)
    {
        // Remember the current node. The very next line will make tempNode 
        // and nodePtr both point to a TreeNode object. However, tempNode is
        // a local variable and nodePtr is actually the address of the object.
        TreeNode *tempNode = nodePtr;

        // Change the current node to hold the right node after nodePtr. The
        // very next line will actually change the address of nodePtr to the
        // right node after nodePtr because nodePtr is passed as a reference
        // to a pointer into the function (denoted by *&).
        nodePtr = nodePtr->right;

        // At this point, tempNode is pointing to the node that is going to 
        // be deleted, and nodePtr is pointing to the right node after nodePtr.
        // Now, just delete tempNode and make it point to nullptr to avoid
        // dangling pointer.
        delete tempNode;
        tempNode = nullptr;
    }
    // Else if the right subtree is nullptr, just similar to the case above.
    else if (nodePtr->right == nullptr)
    {
        // Remember the current node (or nodePtr).
        TreeNode *tempNode = nodePtr;

        // Make nodePtr to hold the address of the left child node of nodePtr.
        nodePtr = nodePtr->right;

        // Delete tempNode and make it point to nullptr.
        delete tempNode;
        tempNode = nullptr;
    }
    // Otherwise, if nodePtr has two children. This algorithm will delete the
    // node via a method, myself call, rightmost left subtree method. That is,
    // I will replace the data in the deleted node by the data of the rightmost
    // node in its left subtree.
    else
    {
        // Search for the rightmost node in nodePtr's left subtree.
        TreeNode *tempNode = nodePtr->left;
        while (tempNode->right)
            tempNode = tempNode->right;
        
        // Replace the data in nodePtr by the data in tempNode, which
        // is now the rightmost node in its left subtree.
        nodePtr->data = tempNode->data;

        // Delete tempNode (or the rightmost node)
        deleteNode(tempNode->data, nodePtr->left);
    }
}

/**
    The destroySubtree function (helper) deletes all nodes in a subtree
    via the postorder traversal
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

        // Delete the root node.
        delete nodePtr;
        nodePtr = nullptr;
    }

}


/***************************************************
            Display-related functions
****************************************************/
/**
    The displayInOrder function (user interface) calls the helper
    displayInOrder function to display the content of a tree
 */
template <class T>
void BinarySearchTree<T>::displayInOrder() const
{
    // If the tree is empty, display an message to indicate that 
    // the tree is empty.
    if (root == nullptr)
        cout << "No data to display: Empty tree now" << endl;
    // Otherwise, call the helper function.
    else
        displayInOrder(root);
}

/**
    The displayInOrder function (helper) dipslays the contents in
    a tree in the order: left -> root -> right via inorder traversal
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display nodePtr's left subtree.
        displayInOrder(nodePtr->left);

        // Display the root.
        cout << nodePtr->data << "  ";

        // Display nodePtr's right subtree.
        displayInOrder(nodePtr->right);
    }
}

/**
    The displayPreOrder function (user interface) calls the helper
    displayPreOrder function to display the content of a tree via
    root -> left -> right order
 */
template <class T>
void BinarySearchTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message showing that
    // the tree is empty.
    if (root == nullptr)
        cout << "No data to display: Empty tree now" << endl;
    // Otherwise, call the helper function.
    else
        displayPreOrder(root);
}

/**
    The displayPreOrder function (helper) displays the data of a tree
    via preorder traversal: root -> left -> right
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
        displayPostOrder(nodePtr->right);
    }
}

/**
    The displayPostOrder function (user interface) calls the helper
    displayPostOrder function to display the data of a tree via a
    postorder traversal (left -> right -> root)
 */
template <class T>
void BinarySearchTree<T>::displayPostOrder() const
{
    // If the tree is empty, then display a message indicating that
    // the tree is empty.
    if (root == nullptr)
        cout << "No data to display: Empty tree now" << endl;
    // Otherwise, calls the helper function.
    else
        displayPostOrder(root);
}

/**
    The displayPostOrder function (helper) displays the data in a
    tree via postorder traversal
    @param nodePtr The root of a subtree
 */
template <class T>
void BinarySearchTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Display left subtree.
        displayPostOrder(nodePtr->left);

        // Display right subtree.
        displayPostOrder(nodePtr->right);

        // Dislay the root data.
        cout << nodePtr->data << "  ";
    }
}
#endif