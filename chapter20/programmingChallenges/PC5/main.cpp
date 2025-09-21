#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    /** Demo input (Tree width = 4)
                30
              /    \
            18      40
           /  \    /  \
          5   25  35  60
           \     /      \
            12  32      70
     */

    // Create the tree like the demo input.
    BinaryTree<int> tree;
    tree.insertNode(30);
    tree.insertNode(40);
    tree.insertNode(18);
    tree.insertNode(5);
    tree.insertNode(25);
    tree.insertNode(35);
    tree.insertNode(60);
    tree.insertNode(12);
    tree.insertNode(32);
    tree.insertNode(70);

    // Display the tree via the inorder traversal.
    tree.displayInOrder();
    
    // Display the information of the tree.
    cout << "\nNumber of nodes: " << tree.countNode() << endl;
    cout << "Number of leaves: " << tree.countLeaf() << endl;
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Width: " << tree.getWidth() << endl;

    return 0;
}