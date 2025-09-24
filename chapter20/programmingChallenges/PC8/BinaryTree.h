/**
    This is a template class for a binary search tree.
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class BinaryTree
{
/*****************************************************************************
                        PRIVATE MEMBER VARIABLES
 *****************************************************************************/
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


/*****************************************************************************
                        PRIVATE MEMBER FUNCTIONS
 *****************************************************************************/
private:
    // Insertion helper function.
    void insert(TreeNode *&, TreeNode *&);
    
    // Deletion helper functions.
    void clearTree(TreeNode *&);
    void deleteNode(const T &, TreeNode *&);
    void makeDeletion(TreeNode *&);

    // Counting helper functions.
    int countNode(const TreeNode *) const;
    int countLeaf(const TreeNode *) const;

    // Searching function.
    const T *search(const TreeNode *, const T &) const;

    // Accessor helper functions.
    int height(const TreeNode *) const;
    int width(const TreeNode *) const;

    // Copying tree helper function.
    TreeNode *copyTree(const TreeNode *) const;


/*****************************************************************************
                        PUBLIC MEMBER FUNCTION
 *****************************************************************************/
public:
    // Constructor and destructor.
    BinaryTree();
    ~BinaryTree();

    // Copy constructor.
    BinaryTree(const BinaryTree &);

    // Insertion function.
    void insertNode(const T &);

    // Deletion function.
    void remove(const T &);

    // Display functions.
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

    // Counting functions.
    int countNode() const;
    int countLeaf() const;

    // Accessor functions.
    int getHeight() const;
    int getWidth() const;

    // Searching functions.
    const T *search(const T &) const;

    // Overloaded assignment operator.
    BinaryTree &operator=(const BinaryTree &);
};


/*****************************************************************************
                        CONSTRUCTORS AND DESTRUCTOR
 *****************************************************************************/
/**
    The constructor creates an empty tree.
 */
template <class T>
BinaryTree<T>::BinaryTree() { root = nullptr; }

/**
    The destructor deletes all nodes in the tree.
 */
template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clearTree(root);
    root = nullptr;
}

/**
    The copy constructor makes a copy of another tree.
    @param otherTree The other tree.
 */
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &otherTree)
{
    this->root = this->copyTree(otherTree.root);
}


/*****************************************************************************
                        INSERTION-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The insert function (helper) actually inserts a new node into the tree.
    @param newNode The new node.
    @param root The root of the tree.
 */
template <class T>
void BinaryTree<T>::insert(TreeNode *&newNode, TreeNode *&root)
{
    // If the root is nullptr, then insert newNode there.
    if (root == nullptr)
    {
        root = newNode;
    }
    // Else if the data in the root is greater than the data in newNode, then
    // insert newNode into the left subtree.
    else if (root->data > newNode->data)
    {
        insert(newNode, root->left);
    }
    // Else if the data in the root is less than the data in newNode, then
    // insert newNode into the right subtree.
    else if (root->data < newNode->data)
    {
        insert(newNode, root->right);
    }
    // Otherwise, newNode is already in the tree, so doing nothing.
    else
    {
        return;
    }
}

/**
    The insertNode function (user interface) inserts a new node into the tree
    whose value is specified by the argument.
    @param value The value of the new node.
 */
template <class T>
void BinaryTree<T>::insertNode(const T &value)
{
    // Allocate a new node and store value in it.
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert newNode into the tree.
    insert(newNode, root);
}


/*****************************************************************************
                        DELETION-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The clearTree function (helper) actually deletes all nodes in the tree.
    @param root The root of the tree.
 */
template <class T>
void BinaryTree<T>::clearTree(TreeNode *&root)
{
    // If the tree is empty, then do nothing.
    if (root == nullptr) return;

    // Deletes all nodes in the left subtree.
    clearTree(root->left);

    // Deletes all nodes in the right subtree.
    clearTree(root->right);

    // Delete the root.
    delete root;
    root = nullptr;
}

/**
    The deleteNode function (helper) searches for the target node and calls the
    makeDeletion function to remove a node from the tree.
    @param value The value of the node to be deleted.
    @param root The root of the tree to search for the target node.
 */
template <class T>
void BinaryTree<T>::deleteNode(const T &value, TreeNode *&root)
{
    // If the data in the root is equal to value, then delete root.
    if (value == root->data)
    {
        makeDeletion(root);
    }
    // Else if the data in the root is less than value, then search for the
    // target node in the right subtree.
    else if (value > root->data)
    {
        deleteNode(value, root->right);
    }
    // Else if the data in the root is greater than value, then search for the
    // target node in the left subtree.
    else if (value < root->data)
    {
        deleteNode(value, root->left);
    }
    // Otherwise, the value is not found, then display a message indicating
    // that the value is not found.
    else
    {
        cout << "Cannot remove: The value is not found." << endl;
    }
}

/**
    The makeDeletion function (helper) actually deletes a node in the tree.
    @param targetNode The node to be deleted.
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&targetNode)
{
    // If the targetNode is nulltpr, then do nothing.
    if (targetNode == nullptr) return;

    // If targetNode has no children, then just simply delete it.
    if (!targetNode->left && !targetNode->right)
    {
        delete targetNode;
        targetNode = nullptr;
    }
    // Else if targetNode has only left child, then replace targetNode by its
    // left child.
    else if (targetNode->left && !targetNode->right)
    {
        // Save the target node.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its left child.
        targetNode = targetNode->left;

        // Delete the old version of targetNode.
        delete tempNode;
    }
    // Else if targetNode has only right child, then replace targetNode by its
    // right child.
    else if (targetNode->right && !targetNode->left)
    {
        // Save the target node.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its right child.
        targetNode = targetNode->right;

        // Delete the old version of targetNode.
        delete tempNode;
    }
    // Otherwise, targetNode will have two children. In this case, replace
    // targetNode by the rightmost node in its left subtree.
    else
    {
        // Search for the rightmost node in the left subtree of the target
        // node and remember its parenet simultaneously.
        TreeNode *parent = targetNode;
        TreeNode *rightmost = targetNode->left;

        while (rightmost->right)
        {
            parent = rightmost;
            rightmost = rightmost->right;
        }

        // Replace the data in targetNode by the rightmost node.
        targetNode->data = rightmost->data;

        // Delete rightmost node.
        if (parent == targetNode)
        {
            parent->left = rightmost->left;
            delete rightmost;
        }
        else
        {
            parent->right = rightmost->left;
            delete rightmost;
        }
    }
}

/**
    The remove function (user interface) deletes a node whose value is
    specified in a tree.
    @param value The value of the node to be deleted.
 */
template <class T>
void BinaryTree<T>::remove(const T &value)
{
    // If the tree is empty, then display a message says that the tree
    // is empty.
    if (root == nullptr)
    {
        cout << "Cannot remove: The tree is empty." << endl;
    }
    // Otherwise, deletes the node.
    else
    {
        deleteNode(value, root);
    }
}


/*****************************************************************************
                        DISPLAY-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The displayInOrder function (user interface) displays the data in the tree
    via an in-order traversal (left -> root -> right) using an iterative
    algorithm.
 */
template <class T>
void BinaryTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message indicates that the tree is
    // empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the data in the tree.
    else
    {
        // Create a stack to hold the nodes in the tree.
        stack<TreeNode *> nodeStack;

        // Declare some necessary variables.
        TreeNode *currentNode = nullptr;    // To hold a node in the tree.

        // Assign currentNode to the root.
        currentNode = root;

        // A loop to display the data in the tree.
        while (!nodeStack.empty() || currentNode)
        {
            // Go as far left as possible and push the node onto the stack
            // on the way.
            while (currentNode)
            {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }

            // Pop the top node off the stack and display its data.
            currentNode = nodeStack.top();
            nodeStack.pop();
            cout << currentNode->data << endl;

            // Move to the right child of currentNode.
            currentNode = currentNode->right;
        }
    }
}

/**
    The displayPreOrder function (user interface) displays the data in the tree
    via a pre-order traversal (root -> left -> right) using an iterative
    algorithm.
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
    // Otherwise, display the data in the tree.
    else
    {
        // Create a stack to hold the nodes in the tree.
        stack<TreeNode *> nodeStack;

        // Declare some necessary variables.
        TreeNode *currentNode = nullptr;    // To hold a node in the tree.

        // Push the root onto the stack.
        nodeStack.push(root);

        // A loop to display the data in the tree.
        while (!nodeStack.empty())
        {
            // Pop the top node off the stack.
            currentNode = nodeStack.top();
            nodeStack.pop();

            // Display the data in the current node.
            cout << currentNode->data << endl;

            // Push the right child of the current node onto the stack if any
            // exists.
            if (currentNode->right) nodeStack.push(currentNode->right);
            if (currentNode->left) nodeStack.push(currentNode->left);
        }
    }
}


/**
    The displayPostOrder function (user interface) displays the data in the
    tree via a post-order traversal (left -> right -> root) using an iterative
    algorithm.
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
    // Otherwise, display the data in the tree.
    else
    {
        // Create to stacks to handle the tree.
        stack<TreeNode *> tempStack;    // To temporarily hold nodes.
        stack<TreeNode *> displayStack; // To hold nodes to display.

        // A variable to hold a node in the tree.
        TreeNode *currentNode = nullptr;

        // Push the root onto tempStack.
        tempStack.push(root);

        // A loop to store nodes in displayStack, which holds nodes in the
        // order to display.
        while (!tempStack.empty())
        {
            // Pop the top node off tempStack.
            currentNode = tempStack.top();
            tempStack.pop();

            // Push the current node onto displayStack.
            displayStack.push(currentNode);

            // Push the left child of currentNode onto tempStack.
            if (currentNode->left) tempStack.push(currentNode->left);

            // Push the right child of currentNode onto tempStack.
            if (currentNode->right) tempStack.push(currentNode->right);
        }

        // Pop nodes off displayStack and display its data.
        while (!displayStack.empty())
        {
            currentNode = displayStack.top();
            displayStack.pop();
            cout << currentNode->data << endl;
        }
    }
}


/*****************************************************************************
                        COUNTING-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The countNode function (helper) counts and returns the number of nodes in
    the tree using an iterative method.
    @param root The root of the tree.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode(const TreeNode *root) const
{
    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int levelSize;      // To hold the number of nodes in a level.
    int numNodes = 0;   // To hold the number of nodes.
    TreeNode *currentNode = nullptr;    // To hold a node.

    // Enqueue the root into the queue.
    if (root) nodeQueue.push(root);

    // A loop to count nodes in the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();

        // Update the number of nodes.
        numNodes += levelSize;

        // For each node in the current level, dequeue it and enqueue its
        // children if any exist.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node if any exist.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the number of nodes.
    return numNodes;
}

/**
    The countNode function (user interface) returns the number of nodes in the 
    tree by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode() const { return this->countNode(root); }

/**
    The countLeaf function (helper) counts and returns the number of leaves in
    the tree using an iterative method.
    @param root The root of the tree.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf(const TreeNode *root) const
{
    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int levelSize;      // To hold the number of nodes in a level.
    int numLeaves = 0;  // To hold the number of leaves.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.

    // Enqueue the root into the queue.
    if (root) nodeQueue.push(root);

    // A loop to count leaves in the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();

        // For each node in the current level, dequeue it, check if it is
        // a leaf, and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Check if currentNode is a leaf.
            if (!currentNode->left && !currentNode->right)
            {
                numLeaves++;
            }
            
            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the number of leaves.
    return numLeaves;
}

/**
    The countLeaf function (user interface) returns the number of leaves in
    the tree by calling its helper function.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf() const { return this->countLeaf(root); }


/*****************************************************************************
                        ACCESSOR-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The height function (helper) determines and returns the height of the tree
    using an iterative method.
    @param root The root of the tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::height(const TreeNode *root) const
{
    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int levelSize;      // To hold the number of nodes in a level.
    int treeHeight = 0; // To hold the height of the tree.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.

    // Enqueue the root into the tree.
    if (root) nodeQueue.push(root);

    // A loop to determine the height of the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes in the queue.
        levelSize = nodeQueue.size();

        // Increment treeHeight;
        treeHeight++;

        // For each node in the queue, dequeue it and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the height of the tree.
    return treeHeight;
}

/**
    The getHeight function (user interface) returns the height of the tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::getHeight() const { return this->height(root); }

/**
    The width function (helper) determines and returns the width of the tree
    using an iterative method.
    @param root The root of the tree.
    @return The width of the tree.
 */
template <class T>
int BinaryTree<T>::width(const TreeNode *root) const
{
    // Create queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int levelSize;      // To hold the number of nodes in a level.
    int treeWidth = 0;  // To hold the width of the tree.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.

    // Enqueue the root into the tree.
    if (root) nodeQueue.push(root);

    // A loop to determine the width of the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();
        
        // Update treeWidth if needed.
        if (levelSize > treeWidth) treeWidth = levelSize;

        // For each node in the queue, dequeue it and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the width of the tree.
    return treeWidth;
}

/**
    The getWidth function (user interface) returns the width of the tree.
    @return The width of the tree.
 */
template <class T>
int BinaryTree<T>::getWidth() const { return this->width(root); }


/*****************************************************************************
                        SEARCHING-RELATED FUNCTIONS
 *****************************************************************************/
/**
    The search function (helper) searches for and returns a pointer to a 
    target value in the tree.
    @param root The root of the tree.
    @param target The target value.
    @return The pointer to the target value.
 */
template <class T>
const T *BinaryTree<T>::search(const TreeNode *root, const T &target) const
{
    // If root is nullptr, then return a null pointer.
    if (root == nullptr)
    {
        return nullptr;
    }
    // If root contain the object whose id is equal to the argument, then
    // return the object in the root.
    if (root->data == target)
    {
        return &(root->data);
    }
    // Else if root contain the object whose id is greater than the argument,
    // then search for the left subtree.
    else if (root->data > target)
    {
        return search(root->left, target);
    }
    // Otherwise, search for the right subtree.
    else
    {
        return search(root->right, target);
    }
}

/**
    The search function (user interface) returns a pointer to the data in a 
    node in the tree.
    @param target The target value.
    @return The pointer to the target value.
 */
template <class T>
const T *BinaryTree<T>::search(const T &target) const
{
    return search(root, target);
}


/*****************************************************************************
                        ASSIGNMENT OPERATOR
 *****************************************************************************/
/**
    The overloaded assignment = operator makes a copies of data in a tree into
    this tree.
    @param otherTree The other tree.
    @return The new copy of the tree.
 */
template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &otherTree)
{
    // If this is a self-assignment, return this.
    if (&otherTree == this)
    {
        return *this;
    }
    
    // Clear the current data in this tree.
    this->clearTree(this->root);

    // Copy the tree.
    this->root = copyTree(otherTree.root);

    // Return this tree.
    return *this;
}

/**
    The copyTree function (helper) makes a copy of a tree and return a pointer
    to it.
    @param otherRoot The root of the other tree.
    @return The root of the newly copied tree.
 */
template <class T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::copyTree(const BinaryTree<T>::TreeNode *otherRoot) const
{
    // If otherRoot is an empty tree, then return a null pointer.
    if (otherRoot == nullptr)
    {
        return nullptr;
    }

    // Copy the root of the other tree.
    TreeNode *newRoot = new TreeNode;
    newRoot->data = otherRoot->data;

    // Copy the left subtree.
    newRoot->left = copyTree(otherRoot->left);

    // Copy the right subtree.
    newRoot->right = copyTree(otherRoot->right);

    // Return the newly copied tree.
    return newRoot;
}
#endif