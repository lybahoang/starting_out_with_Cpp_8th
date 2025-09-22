/**
    This is a template class for a binary tree.
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

template <class T>
class BinaryTree
{
/***********************************************************************************
                        PRIVATE MEMBER VARIABLES
 ***********************************************************************************/
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

/***********************************************************************************
                        PRIVATE MEMBER FUNCTIONS
 ***********************************************************************************/
private:
    // Insertion helper function.
    void insert(TreeNode *&, TreeNode *&);

    // Deletion helper function.
    void clearTree(TreeNode *&);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);

    // Display helper functions.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

    // Counting helper functions.
    int countNode(TreeNode *) const;
    int countLeaf(TreeNode *) const;
    
    // Accessor helper functions.
    int height(TreeNode *) const;
    int getLevelWidth(TreeNode *, int) const;
    int width(TreeNode *) const;

    // Copying helper function.
    TreeNode *copyTree(const TreeNode *);

/***********************************************************************************
                        PUBLIC MEMBER VARIABLES
 ***********************************************************************************/
public:
    // Constructor and destructor.
    BinaryTree();
    ~BinaryTree();

    // Copy constructor.
    BinaryTree(const BinaryTree &);

    // Insertion function.
    void insertNode(T);

    // Deletion function.
    void remove(T);

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

    // Overloaded assignment operator.
    BinaryTree &operator=(const BinaryTree &);
};

/***********************************************************************************
                        CONSTRUCTORS/DESTRUCTOR
 ***********************************************************************************/
/**
    The constructor creats an empty tree.
 */
template <class T>
BinaryTree<T>::BinaryTree() { root = nullptr; }

/**
    The destructor deletes all nodes in the tree.
 */
template <class T>
BinaryTree<T>::~BinaryTree()
{
    clearTree(root);
    root = nullptr;
}

/**
    The copyTree function copies an existing tree into another tree.
    @param root The root of the other tree.
    @return The root of a new tree.
 */
template <class T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::copyTree(const BinaryTree<T>::TreeNode *root)
{
    // If the other tree is empty, then return nullptr.
    if (root == nullptr)
    {
        return nullptr;
    }

    // Copy the current node.
    TreeNode *newRoot = new TreeNode;
    newRoot->data = root->data;

    // Copy the left subtree.
    newRoot->left = copyTree(root->left);

    // Copy the right subtree.
    newRoot->right = copyTree(root->right);

    // Return newRoot.
    return newRoot;
}

/**
    The copy constructor copies an existing tree into this tree.
    @param other The root of the other tree.
 */
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &other)
{
    this->root = copyTree(other.root);
}


/***********************************************************************************
                        INSERTION-RELATED FUNCTIONS
 ***********************************************************************************/
/**
    The insert function (helper) actually inserts a new node into the tree.
    @param root The root of a subtree.
    @param newNode The new node.
 */
template <class T>
void BinaryTree<T>::insert(TreeNode *&root, TreeNode *&newNode)
{
    // If root is nullptr, then insert newNode there.
    if (root == nullptr)
    {
        root = newNode;
    }
    // Else if the data in root is less than the data in newNode, then inserts
    // newNode into the right subtree of the root.
    else if (root->data < newNode->data)
    {
        insert(root->right, newNode);
    }
    // Else if the data in root is greater than the data in newNode, then inserts
    // newNode into the left subtree of the root.
    else if (root->data > newNode->data)
    {
        insert(root->left, newNode);
    }
    // Otherwise, the data in root and newNode are the same. In this case, newNode is
    // already in the tree, so do nothing.
    else
    {
        return;
    }
}

/**
    The insertNode function (user interface) creates a new node and inserts it into
    the tree.
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


/***********************************************************************************
                        DELETION-RELATED FUNCTIONS
 ***********************************************************************************/
/**
    The clearTree function (helper) deletes all nodes in the tree.
    @param root The root of a tree.
 */
template <class T>
void BinaryTree<T>::clearTree(TreeNode *&root)
{
    // If the tree is not empty, then delete all nodes in the tree.
    if (root)
    {
        // Delete all nodes in the left subtree.
        clearTree(root->left);

        // Delete all nodes in the right subtree.
        clearTree(root->right);

        // Deletes the root node.
        delete root;
        root = nullptr;
    }
}

/**
    The deleteNode function (helper) deletes a node in the tree, whose data is
    specified beforehand.
    @param value The value of the node to be deleted.
    @param root The root of the tree.
 */
template <class T>
void BinaryTree<T>::deleteNode(T value, TreeNode *&root)
{
    // If value is less than the data in root, then searches for the target node in
    // the left subtree of the tree.
    if (value < root->data)
    {
        deleteNode(value, root->left);
    }
    // Else if value is greater than the data in root, then searches for the target
    // node in the right subtree of the tree.
    else if (value > root->data)
    {
        deleteNode(value, root->right);
    }
    // Else if the value is equal to the data in root, then delete the root.
    else if (value == root->data)
    {
        makeDeletion(root);
    }
    // Otherwise, the value is not found in the tree and so display a message
    // indicating that the value is not in the tree.
    else
    {
        cout << "Cannot remove: The value is not in the tree." << endl;
    }
}

/**
    The makeDeletion function (helper) actually removes a node from the tree.
    @param targetNode The node to be deleted.
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&targetNode)
{
    // For the sake of safety, even though targetNode cannot be a null pointer since
    // the deleteNode never passes a null pointer into it, I still check for a null
    // pointer in targetNode.
    if (targetNode == nullptr)
    {
        return;
    }
    // If targetNode has no children, then just simply delete it.
    if (!targetNode->left && !targetNode->right)
    {
        delete targetNode;
        targetNode = nullptr;
    }
    // Else if targetNode has only left child, then replace targetNode by its left
    // child.
    else if (!targetNode->right && targetNode->left)
    {
        // Remember the target node.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its left child.
        targetNode = targetNode->left;

        // Delete tempNode.
        delete tempNode;
    }
    // Else if targetNode has only right child, the replace targetNode by its right
    // child.
    else if (!targetNode->left && targetNode->right)
    {
        // Remember the target node.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its right child.
        targetNode = targetNode->right;

        // Delete tempNode.
        delete tempNode;
    }
    // Else: targetNode has two children, then I will replace the target node by the 
    // rightmost node in its left subtree.
    else
    {
        // Search for the rightmost node in the left subtree of the target node and
        // at the same time remember the its parent.
        TreeNode *parent = targetNode;
        TreeNode *rightmost = targetNode->left;
        while (rightmost->right)
        {
            // Remember its parent.
            parent = rightmost;
            // Move to the right.
            rightmost = rightmost->right;
        }
        
        // Replace targetNode by the rightmost node in its left subtree.
        targetNode->data = rightmost->data;

        // Delete the rightmost node.
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
    The remove function (user interface) deletes a node whose value is specified
    out of the tree.
    @param value The value of the node to be deleted.
 */
template <class T>
void BinaryTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating that the tree is
    // empty.
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


/***********************************************************************************
                        DISPLAY-RELATED FUNCTIONS
 ***********************************************************************************/
/**
    The displayInOrder function (helper) displays the data of a tree via the in-order
    traversal (left -> root -> right).
    @param root The root of a tree.
 */
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *root) const
{
    // If the tree is not empty, then display the tree.
    if (root)
    {
        // Display all nodes in the left subtree.
        displayInOrder(root->left);

        // Display the root data.
        cout << root->data << "  ";

        // Display all nodes in the right subtree.
        displayInOrder(root->right);
    }
}

/**
    The displayInOrder function (user interface) displays the data of at tree via the
    in-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message saying that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        displayInOrder(root);
    }
}

/**
    The displayPreOrder function (helper) displays the data of a tree via the 
    pre-order traversal (root -> left -> right).
    @param root The root of a tree.
 */
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *root) const
{
    // If the tree is not empty, then display the tree.
    if (root)
    {
        // Display the root data.
        cout << root->data << "  ";

        // Display all nodes in the left subtree.
        displayPreOrder(root->left);

        // Display all nodes in the right subtree.
        displayPreOrder(root->right);
    }
}

/**
    The displayPreOrder function (user interface) displays the data of at tree via 
    the pre-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message saying that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        displayPreOrder(root);
    }
}

/**
    The displayPostOrder function (helper) displays the data of a tree via the 
    post-order traversal (left -> right -> root).
    @param root The root of a tree.
 */
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *root) const
{
    // If the tree is not empty, then display the tree.
    if (root)
    {
        // Display all nodes in the left subtree.
        displayPostOrder(root->left);
        
        // Display all nodes in the right subtree.
        displayPostOrder(root->right);
        
        // Display the root data.
        cout << root->data << "  ";
    }
}

/**
    The displayPostOrder function (user interface) displays the data of at tree via
    the post-order traversal by calling its helper function.
 */
template <class T>
void BinaryTree<T>::displayPostOrder() const
{
    // If the tree is empty, then display a message saying that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        displayPostOrder(root);
    }
}


/***********************************************************************************
                        COUNTING-RELATED FUNCTIONS
 ***********************************************************************************/
/**
    The countNode function (helper) counts and returns the number of nodes in the
    tree using a recursive method.
    @param root The root of a tree.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode(TreeNode *root) const
{
    // If root is nullptr, then return 0.
    if (root == nullptr)
    {
        return 0;
    }
    // Count the number of nodes in the left subtree.
    int totalLeftNodes = countNode(root->left);

    // Count the number of nodes in the right subtree.
    int totalRightNodes = countNode(root->right);

    // Return the number of nodes.
    return totalLeftNodes + totalRightNodes + 1;
}

/**
    The countNode function (user interface) returns the number of nodes in the tree
    by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode() const { return countNode(root); }

/**
    The countLeaf function (helper) returns the number of leaves in the tree using a
    recursive algorithm.
    @param root The root of the tree.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf(TreeNode *root) const
{
    // If root is nullptr, then return 0.
    if (root == nullptr) return 0;
    
    // If root is a leave, then return 1.
    if (!root->left && !root->right) return 1;

    // Otherwise, get the number of leaves in the left subtree and the right subtree
    // of the tree.
    int leftLeaves = countLeaf(root->left);
    int rightLeaves = countLeaf(root->right);

    // Return the number of leaves.
    return leftLeaves + rightLeaves;
}

/**
    The countLeaf function (user interface) returns the number of leaves in the tree
    by calling its helper function.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf() const { return countLeaf(root); }


/***********************************************************************************
                        ACCESSOR-RELATED FUNCTIONS
 ***********************************************************************************/
/**
    The height function (helper) determines and returns the number of levels in the
    tree using a recursive algorithm.
    @param root The root of a tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::height(TreeNode *root) const
{
    // If root is nullptr, then return 0.
    if (root == nullptr) return 0;

    // Get the height of the left and right subtrees of root.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Return the height.
    return max(leftHeight, rightHeight) + 1;  
}

/**
    The getHeight function (user interface) returns the height of the tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::getHeight() const { return height(root); }

/**
    The width function (helper) determines and returns the width of the tree.
    @param root The root of a tree.
    @return The maximum width of the tree.
 */
template <class T>
int BinaryTree<T>::width(TreeNode *root) const
{
    // If root is nullptr, then return 0.
    if (root == nullptr) return 0;
    
    // Declare some needed variables.
    int treeWidth = 0;
    int levelWidth = 0;

    // Get the height of the tree.
    int treeHeight = height(root);

    for (int levelCount = 0; levelCount < treeHeight; levelCount++)
    {
        // Get the width of the current level.
        levelWidth = getLevelWidth(root, levelCount);

        // Update the width of the tree if needed.
        if (treeWidth < levelWidth) treeWidth = levelWidth;
    }

    // Return the width of the tree.
    return treeWidth;
}

/**
    The getLevelWidth function (helper) determines and returns the width of a
    specified level in the tree.
    @param root The root of the tree.
    @param targetLevel The level to return the width.
    @return The width of the level.
 */
template <class T>
int BinaryTree<T>::getLevelWidth(TreeNode *root, int targetLevel) const
{
    // If root is nullptr, then return 0.
    if (root == nullptr) return 0;

    // Intialize some necessary variables.
    int levelSize = 0;      // To hold the number of nodes in the current level.
    int levelCount = 0;     // To count the level.
    int width = 0;          // The width of the target level.

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue the root into nodeQueue.
    nodeQueue.push(root);

    // A loop to determine the width of the target level.
    while (!nodeQueue.empty())
    {
        // Increment levelCount.
        levelCount++;

        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();

        // If the current level is the target level, set width to levelSize.
        if (levelCount == targetLevel)
        {
            width = levelSize;
            break;
        }

        // For each node in the current level, dequeue it and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the front node's children if any exist.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.puhs(currentNode->right);
        }
   }

   // Return the width of the target level.
   return width;
}

/**
    The getWidth function (user interface) returns the width of the tree by calling
    its helper function.
    @return The maximum number of nodes in a level in the tree.
 */
template <class T>
int BinaryTree<T>::getWidth() const { return width(root); }


/***********************************************************************************
                        OVERLOADED OPERATIONS
 ***********************************************************************************/
/**
    The overloaded assignment = operator copies data from an existing tree and return
    this copy.
    @param other The other tree.
    @return The new copy of the other tree.
 */
template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &other)
{
    // If the two trees are distinct (to avoid self-assignment), then copy the tree.
    if (this != &other)
    {
        // Delete old data in this tree.
        this->clearTree(this->root);
        
        // Copy the tree.
        this->root = copyTree(other.root);
    }
    
    // Return the copy of the other tree.
    return *this;
}
#endif