/**
    The program demonstrates a recursive method to determine the width of a tree.
    The method involves two functions:
        1. The getLevelWidth method returns the width of the current level of a tree.
        2. The getTreeWidth method returns the width of a tree.
    The pseudocode of the algorithm for the getTreeWidth method:
        1. Initialize treeWidth to 0.
        2. Get the height of the tree and store into treeHeight.
        3. For each level in the tree (from the deepest level to the root):
            3.1. Get the width of the current level: currentWidth = getLevelWidth(...)
            3.2. If (currentWidth > treeWidth) then treeWidth = currentWidth.
        4. Return treeWidth.
    
    The functions to get the height of the tree have been illustrated in PC4.
    The pseudocode of the algorithm for the getLevelWidth method:
        @param nodePtr The root of a subtree.
        @param desiredLevel The level that we want to get the width.
        1. Initialize levelCount at 0, levelSize at 0, and width to 0.
        2. Create a queue to store nodes in the tree.
        3. Enqueue the root into the tree.
        4. While the queue is not empty, then
            4.1. Increment levelCount.
            4.2. Set levelSize to the size of the queue.
            4.3. If (levelCount equals to desiredLevel), then set width to the
                 size of the queue
            4.4. For each node in the queue, then
                4.4.1 Pop the front node off the queue.
                4.4.2 Enqueue its children into the queue if any exist.
        5. Return width.
 */

#include <iostream>
#include <queue>
using namespace std;

/**
    The TreeNode class represents a node of a tree.
 */
class TreeNode
{
private:
    int value;          // The value in the node.
public:
    TreeNode *left;     // The left child of the node.
    TreeNode *right;    // The right child of the node.

    // Constructor.
    TreeNode(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }

    // Destructor.
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

/**
    The height function returns the number of levels in the tree.
    @param nodePtr The root of a subtree.
    @return The height of the tree.
 */
int height(const TreeNode *nodePtr)
{
    // Create a queue to hold the nodes in the tree.
    queue<const TreeNode *> nodeQueue;

    // Declare some necessary variables.
    int height = 0;     // The height of the tree.
    int levelSize = 0;  // The size of the current level.

    // Enqueue the root in the queue.
    nodeQueue.push(nodePtr);

    // The loop to determine the size of a tree.
    while (!nodeQueue.empty())
    {
        // Get the size of the current level.
        levelSize = nodeQueue.size();

        // Dequeue the front node and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Take the front node in the queue.
            auto *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node into the queue.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }

        // Increment height.
        height++;
    }

    // Return the height.
    return height;
}

/**
    The getLevelWidth function returns the number of nodes in a
    specific level.
    @param nodePtr The root of a subtree.
    @param desiredLevel The level that we want to get the width.
    @return The width of the level.
 */
int getLevelWidth(const TreeNode *nodePtr, int desiredLevel)
{
    // If nodePtr is nullptr, then return 0.
    if (nodePtr == nullptr)
    {
        return 0;
    }

    // Initializes some necessary variables.
    int levelCount = 0;     // To count the level of the tree.
    int levelSize = 0;      // The size of the current level.
    int width = 0;          // The width of the current level.

    // Create a queue to hold nodes in the tree.
    queue<const TreeNode *> nodeQueue;

    // Enqueue the root into the queue.
    nodeQueue.push(nodePtr);

    // The loop to determine the width of the current level.
    while (!nodeQueue.empty())
    {
        // Increment levelCount.
        levelCount++;

        // Get the size of the current level.
        levelSize = nodeQueue.size();

        // If the current level is the one desired, set width to levelSize.
        if (desiredLevel == levelCount)
        {
            width = levelSize;
            break;
        }

        // Dequeue the front node and enqueue its children.
        for (int count = 0; count < levelSize; count++)
        {
            // Take the front node in the queue.
            auto *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue the children of the current node.
            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }
    }

    // Return the width.
    return width;
}

/**
    The getTreeWidth function returns the width of a tree.
    @param nodePtr The root of a subtree.
    @return The width of a tree.
 */
int getTreeWidth(const TreeNode *nodePtr)
{
    int treeWidth = 0;  // To hold the width of the tree.

    // Get the height of the tree.
    int treeHeight = height(nodePtr);

    // A loop to determine the width of the tree.
    for (int level = 1; level <= treeHeight; level++)
    {
        // Get the width of the current level.
        int currentWidth = getLevelWidth(nodePtr, level);

        // Update the width of the tree if needed.
        if (currentWidth > treeWidth) treeWidth = currentWidth;
    }

    // Return the width of the tree.
    return treeWidth;
}

int main()
{
    /** Demo input (Tree width = 4)
                30
              /    \
            18      40
           /  \    /  \
          5   25  35  60
     */

    // Create the root of the tree.
    TreeNode *root = new TreeNode(30);
    
    // Create children of the root.
    TreeNode *rootLeftChild = new TreeNode(18);
    TreeNode *rootRightChild = new TreeNode(40);
    root->left = rootLeftChild;
    root->right = rootRightChild;

    // Create children for the level 3.
    TreeNode *child3_1_L = new TreeNode(5);
    TreeNode *child3_1_R = new TreeNode(25);
    rootLeftChild->left = child3_1_L;
    rootLeftChild->right = child3_1_R;

    TreeNode *child3_2_L = new TreeNode(35);
    TreeNode *child3_2_R = new TreeNode(60);
    rootRightChild->left = child3_2_L;
    rootRightChild->right = child3_2_R;

    // Display the width of the tree.
    cout << "Tree width: " << getTreeWidth(root) << endl;

    // Delete dynamically allocated memory.
    delete root;

    return 0;
}