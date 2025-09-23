/**
    This is a template class for a binary search tree.
 */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class BinaryTree
{
/***********************************************************************************
                        PRIVATE MEMBER VARIABLES
 ***********************************************************************************/
private:
    // A structure for the node in the tree.
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

    // Deletion helper functions.
    void clearTree(TreeNode *&);
    void makeDeletion(TreeNode *&);
    void deleteNode(T, TreeNode *&);

    // Counting helper functions.
    int countNode(TreeNode *) const;
    int countLeaf(TreeNode *) const;
    
    // Accessor helper functions.
    int height(TreeNode *) const;
    int width(TreeNode *) const;

    // Overloaded asignment helper function.
    TreeNode *copyTree(const TreeNode *);

    // Other functions.
    void toQueue(queue<T> &) const;


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

    // Searching function.
    bool searchNode(T) const;

    // Overloaded assignment operator.
    BinaryTree &operator=(const BinaryTree &);

    // Other functions.
    queue<T> toQueue() const;
};

/***********************************************************************************
                        CONSTRUCTORS AND DESTRUCTOR
 ***********************************************************************************/
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
    The copy constructor copies another tree into this tree.
    @param otherTree The other tree to be copied.
 */
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &otherTree)
{
    this->root = copyTree(otherTree.root);
}


/***********************************************************************************
                        INSERTION-RELATION FUNCTIONS
 ***********************************************************************************/
/**
    The insert function (helper) actually inserts a new node into the tree.
    @param root The root of a tree.
    @param newNode The new node to be inserted.
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
    // newNode in its right subtree.
    else if (root->data < newNode->data)
    {
        insert(root->right, newNode);
    }
    // Else if the data in root is greater than the data in newNode, then
    // inserts newNode in its left subtree.
    else if (root->data > newNode->data)
    {
        insert(root->left, newNode);
    }
    // Otherwise, the data in root is equal to the data in newNode. In this case,
    // newNode is already in the tree, so do nothing.
    else
    {
        return;
    }
}

/**
    The insertNode function (user interface) inserts a new node whose data is
    specified into the tree.
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
                        DELETION MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The clearTree function (helper) deletes all nodes in the tree using an iterative
    algorithm.
    @param root The root of the tree.
 */
template <class T>
void BinaryTree<T>::clearTree(TreeNode *&root)
{
    // If the root is nullptr, this means that the tree is empty, and so do nothing.
    if (root == nullptr) return;

    // Create two stacks: One to temporarily hold the nodes and One to hold the nodes
    // in the post-order.
    stack<TreeNode *> tempStack;    // To temporarily hold the nodes.
    stack<TreeNode *> deleteStack;  // To hold the nodes in the post-order.

    // Push the root onto the stack.
    tempStack.push(root);

    // A loop to process the tree.
    while (!tempStack.empty())
    {
        // Pop the top node and push onto deleteStack.
        TreeNode *currentNode = tempStack.top();
        tempStack.pop();
        deleteStack.push(currentNode);

        // Push the right and left children of the current node onto the stack.
        if (currentNode->right) tempStack.push(currentNode->right);
        if (currentNode->left) tempStack.push(currentNode->left);
    }

    // Pop each node in deleteStack and delete it.
    while (!deleteStack.empty())
    {
        TreeNode *currentNode = deleteStack.top();
        deleteStack.pop();
        delete currentNode;
        currentNode = nullptr;
    }
}

/**
    The makeDeletion function (helper) actually deletes a specified node out of the
    tree.
    @param targetNode The node to be deleted.
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&targetNode)
{
    // If the target node is nullptr, then do nothing.
    if (targetNode == nullptr) return;

    // If the target node has no children, then just simply remove the node.
    if (!targetNode->left && !targetNode->right)
    {
        delete targetNode;
        targetNode = nullptr;
    }
    // Else if the target node has only left child, then replace the target node by
    // its left child.
    else if (!targetNode->right && targetNode->left)
    {
        // Save the targetNode.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its left child.
        targetNode = targetNode->left;

        // Delete targetNode.
        delete tempNode;
        tempNode = nullptr;
    }
    // Else if the target node has only right child, then replace the target node by
    // its right child.
    else if (!targetNode->left && targetNode->right)
    {
        // Save the targetNode.
        TreeNode *tempNode = targetNode;

        // Replace targetNode by its right child.
        targetNode = targetNode->right;

        // Delete targetNode.
        delete tempNode;
        tempNode = nullptr;
    }
    // Otherwise, the target node will have two children, then replce the target node
    // by the rightmost node in its left subtree.
    else
    {
        // Search for the rightmost node in the left subtree of the target node and
        // remember its parent at the same time.
        TreeNode *rightmost = targetNode->left;
        TreeNode *parent = targetNode;

        while (rightmost->right)
        {
            parent = rightmost;
            rightmost = rightmost->right;
        }

        // Replace the data in targetNode by the data in rightmost.
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
    The deleteNode function (helper) searches and deletes a node whose value is
    specified out of the tree.
    @param value The value of the node to be deleted.
    @param root The root of the tree.
 */
template <class T>
void BinaryTree<T>::deleteNode(T value, TreeNode *&root)
{
    // If the data in root is equal to value, then delete root.
    if (root->data == value)
    {
        makeDeletion(root);
    }
    // Else if the data in root is less than value, then search for the target node
    // in the right subtree.
    else if (root->data < value)
    {
        deleteNode(value, root->right);
    }
    // Else if the data in root is greater than value, then search for the target
    // node in the left subtree.
    else if (root->data > value)
    {
        deleteNode(value, root->left);
    }
    // Otherwise, the value is not found, then display a message indicating that the
    // value is not found.
    else
    {
        cout << "Cannot remove: The value is not found." << endl;
    }
}

/**
    The remove function (user interface) removes a node from the tree.
    @param value The value of the node to be deleted.
 */
template <class T>
void BinaryTree<T>::remove(T value)
{
    // If the tree is empty, then display a message indicating that the tree is empty
    if (root == nullptr)
    {
        cout << "Cannot remove: The tree is empty." << endl;
    }
    // Otherwise, delete nodes.
    else
    {
        deleteNode(value, root);
    }
}


/***********************************************************************************
                        DISPLAY MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The displayInOrder function (user interface) displays the data in the tree via
    the in-order traversal (left -> root -> right) using an iterative algorithm.
 */
template <class T>
void BinaryTree<T>::displayInOrder() const
{
    // If the tree is empty, then display a message showing that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        // Create a stack to hold the nodes in the tree.
        stack<TreeNode *> nodeStack;

        // Initialize currentNode to the root.
        TreeNode *currentNode = root;

        // A loop to process of the tree.
        while (!nodeStack.empty() || currentNode)
        {
            // Go as far left as possible.
            while (currentNode)
            {
                // Push currentNode onto the stack.
                nodeStack.push(currentNode);

                // Move to the left child of currentNode.
                currentNode = currentNode->left;
            }

            // Pop the top node off the stack and assign it to currentNode.
            currentNode = nodeStack.top();
            nodeStack.pop();

            // Display the data in currentNode.
            cout << currentNode->data << "  ";

            // Set currentNode to its right child.
            currentNode = currentNode->right;
        }
    }
}

/**
    The displayPreOrder function (user interface) displays the data in the tree via
    the pre-order traversal (root -> left -> right) using an iterative algorithm.
 */
template <class T>
void BinaryTree<T>::displayPreOrder() const
{
    // If the tree is empty, then display a message showing that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        // Create a stack to hold the nodes in the tree.
        stack<TreeNode *> nodeStack;

        // Create a variable to hold a node.
        TreeNode *currentNode = nullptr;

        // Push the root onto the stack.
        nodeStack.push(root);

        // A loop to process the tree.
        while (!nodeStack.empty())
        {
            // Pop the top node off the stack and assign to currentNode.
            currentNode = nodeStack.top();
            nodeStack.pop();

            // Display the current node.
            cout << currentNode->data << "  ";

            // Push the right child of currentNode onto the stack if exists.
            if (currentNode->right) nodeStack.push(currentNode->right);

            // Push the left child of currentNode onto the stack if exists.
            if (currentNode->left) nodeStack.push(currentNode->left);;
        }
    }
}

/**
    The displayPostOrder function (user interface) displays the data in the tree via
    the post-order traversal (left -> right -> root) using an iterative algorithm.
 */
template <class T>
void BinaryTree<T>:: displayPostOrder() const
{
    // If the tree is empty, then display a message showing that the tree is empty.
    if (root == nullptr)
    {
        cout << "Cannot display: The tree is empty." << endl;
    }
    // Otherwise, display the tree.
    else
    {
        // Create two stacks: One to temporarily process the tree and One to hold
        // the nodes in post-order.
        stack<TreeNode *> tempStack;
        stack<TreeNode *> displayStack;

        // Push the root onto tempStack.
        tempStack.push(root);

        // A variable to hold a node.
        TreeNode *currentNode = nullptr;

        // A loop to process the tree.
        while (!tempStack.empty())
        {
            // Pop the top node off tempStack and push it onto displayStack.
            currentNode = tempStack.top();
            tempStack.pop();
            displayStack.push(currentNode);

            // Push the right child of currentNode onto tempStack if exists.
            if (currentNode->right) tempStack.push(currentNode->right);

            // Push the left child of currentNode onto tempStack if exists.
            if (currentNode->left) tempStack.push(currentNode->left);

        }

        // Display the values in the tree in post-order.
        while (!displayStack.empty())
        {
            // Pop the top node off displayStack.
            currentNode = displayStack.top();
            displayStack.pop();

            // Display the data in currentNode.
            cout << currentNode->data << "  ";
        }
    }
}


/***********************************************************************************
                        COUNTING-RELATED MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The countNode function (user interface) counts and returns the number of nodes in
    a tree using an iterative method.
    @param root The root of the tree.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode(TreeNode *root) const
{
    // If the tree is empty, then return 0.
    if (root == nullptr) return 0;

    int numNodes = 0;                 // To hold the number of nodes.
    int levelSize;                    // To hold the number of nodes in a level.
    TreeNode *currentNode = nullptr;  // To hold a node in the tree.

    // Create a queue to hold nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue the root into the queue.
    nodeQueue.push(root);

    // A loop to count the number of nodes in the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();

        // Update the number of nodes.
        numNodes += levelSize;

        // For each current node in the queue, dequeue it and enqueue its children.
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
    The countNode function (user interface) returns the number of nodes in the tree
    by calling its helper function.
    @return The number of nodes in the tree.
 */
template <class T>
int BinaryTree<T>::countNode() const { return countNode(root); }

/**
    The countLeaf function (helper) counts and returns the number of leaves in the
    tree via an iterative algorithm.
    @param root The root of the tree.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf(TreeNode *root) const
{
    // If the tree is empty, then return 0.
    if (root == nullptr) return 0;

    // Declare some necessary variables.
    int numLeaves = 0;                  // To hold the number of leaves.
    int levelSize;                      // To hold the number of nodes in a level.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue the root into the queue.
    nodeQueue.push(root);

    // A loop to count the number of leaves in the tree.
    while (!nodeQueue.empty())
    {
        // Get the number of nodes of the current level.
        levelSize = nodeQueue.size();

        // For each node in the current level, dequeue it, check if it is a leaf, and
        // enqueue its children if any exist.
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
            else
            {
                if (currentNode->left) nodeQueue.push(currentNode->left);
                if (currentNode->right) nodeQueue.push(currentNode->right);
            }
        }
    }

    // Return the number of leaves.
    return numLeaves;
}

/**
    The countLeaf function (user interface) returns the number of leaves in the tree
    by calling its helper function.
    @return The number of leaves in the tree.
 */
template <class T>
int BinaryTree<T>::countLeaf() const { return countLeaf(root); }


/***********************************************************************************
                        ACCESSOR-RELATED MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The height function (helper) determines and returns the height of the tree.
    @param root The root of the tree.
    @return The number of levels in the tree.
 */
template <class T>
int BinaryTree<T>::height(TreeNode *root) const
{
     // If the tree is empty, then return 0.
    if (root == nullptr) return 0;

    // Declare some necessary variables.
    int levelSize;              // To hold the number of nodes in the current level.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.
    int treeHeight = 0;         // To hold the height of the tree.

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue the root into the queue.
    nodeQueue.push(root);

    // A loop to determine the height of the tree.
    while (!nodeQueue.empty())
    {
        // Increment the tree height.
        treeHeight++;

        // Get the number of nodes in the current level.
        levelSize = nodeQueue.size();

        // For each node in the queue, dequeue it and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Dequeue the front node.
            currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of currentNode if any exist.
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
int BinaryTree<T>::getHeight() const { return height(root); }

/**
    The width function (helper) determines and returns the width of the tree.
    @param root The root of the tree.
    @return The width of the tree.
 */
template <class T>
int BinaryTree<T>::width(TreeNode *root) const
{
     // If the tree is empty, then return 0.
    if (root == nullptr) return 0;

    // Declare some necessary variables.
    int levelSize;      // To hold the number of nodes in the current level.
    int treeWidth = 0;  // To hold the width of the tree.
    TreeNode *currentNode = nullptr;    // To hold a node in the tree.

    // Create a queue to hold the nodes in the tree.
    queue<TreeNode *> nodeQueue;

    // Enqueue the root into the queue.
    nodeQueue.push(root);

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

            // Enqueue the children of currentNode if any exist.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the width of the tree.
    return treeWidth;
}

/**
    The getWidth function (user interface) returns the width of the tree by calling
    its helper function.
    @return The width of the tree.
 */
template <class T>
int BinaryTree<T>::getWidth() const { return width(root); }


/***********************************************************************************
                        SEARCHING-RELATED MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The searchNode function (user interface) returns true if a value is in the tree
    and false otherwise.
    @param value The value to be searched.
    @return true if value is in the tree and false otherwise.
 */
template <class T>
bool BinaryTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;   // To traverse the tree.
    // If the tree is empty, then return false.
    if (nodePtr == nullptr)
    {
        return false;
    }
    // If the value in nodePtr is the desired value, then return true.
    if (nodePtr->data == value)
    {
        return true;
    }
    // Else if the value in nodePtr is less than the desired value, then search for
    // the value in the right subtree.
    if (nodePtr->data < value)
    {
        nodePtr = nodePtr->right;
    }
    // Else, search for the value in the left subtree.
    else
    {
        nodePtr = nodePtr->left;
    }
}

/***********************************************************************************
                        ASSIGNMENT-RELATED MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The overloaded assignment = operator copies another tree into this tree.
    @param otherTree The other tree.
    @return This tree.
 */
template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &otherTree)
{
    // If otherTree and this tree is the same (self-assignment), then do nothing.
    if (this == &otherTree) *this;

    // Clear the old data of this tree to get ready for a copy.
    this->clearTree(this->root);

    // Copy the other tree into this tree.
    this->root = copyTree(otherTree.root);
}

/**
    The copyTree function (helper) copies another tree in the tree.
    @param otherTree The other tree.
    @return The pointer to the new copied tree.
 */
template <class T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::copyTree(const BinaryTree<T>::TreeNode *otherTree)
{
    // If the otherTree is empty, then return nullptr.
    if (otherTree == nullptr) return nullptr;

    // Copy the root of the other tree.
    TreeNode *newRoot = new TreeNode;
    newRoot->data = otherTree->data;
    
    // Copy the left subtree.
    newRoot->left = copyTree(otherTree->left);

    // Copy the right subtree.
    newRoot->right = copyTree(otherTree->right);

    // Return the new tree.
    return newRoot;
}


/***********************************************************************************
                        OTHER MEMBER FUNCTIONS
 ***********************************************************************************/
/**
    The toQueue function (helper) accepts a referece ot a queue and stores values in
    the tree into the queue in ascending order via an iterative algorithm.
    @param outputQueue The queue that holds values in the tree in ascending order.
 */
template <class T>
void BinaryTree<T>::toQueue(queue<T> &outputQueue) const
{
    // If the tree is empty, then do nothing.
    if (root == nullptr) return;

    // Create a stack to hold nodes in the tree.
    stack<TreeNode *> nodeStack;

    // A variable to hold a node in the tree.
    TreeNode *currentNode = nullptr;
    
    // Set currentNode to the root.
    currentNode = root;

    // A loop to process the tree and add values into the queue.
    while (!nodeStack.empty() || currentNode)
    {
        // Go as far left as possible and push nodes onto the stack on the way.
        while (currentNode)
        {
            // Push the current node onto the stack.
            nodeStack.push(currentNode);

            // Move to the left child of currentNode.
            currentNode = currentNode->left;
        }

        // Pop the top node off the stack and enqueue its value to the queue.
        currentNode = nodeStack.top();
        nodeStack.pop();
        outputQueue.push(currentNode->data);

        // Move to the right child of the current node.
        currentNode = currentNode->right;
    }
}

/**
    The toQueue function (user interface) returns a queue containing values in the
    tree in ascending order.
    @return The queue containing the values in the tree in ascending order.
 */
template <class T>
queue<T> BinaryTree<T>::toQueue() const
{
    // Create a queue.
    queue<T> outputQueue;

    // Store values in the tree into the queue in ascending order.
    toQueue(outputQueue);

    // Return the queue.
    return outputQueue;
}
#endif