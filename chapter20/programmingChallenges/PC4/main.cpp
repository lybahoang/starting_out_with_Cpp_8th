#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    /** Demo input:
                12
               /  \
              8    18
             / \
            5   11
     */

    // Create a tree that looks the the demo.
    BinaryTree<int> tree;

    // Put data into the tree.
    tree.insertNode(12);
    tree.insertNode(8);
    tree.insertNode(18);
    tree.insertNode(5);
    tree.insertNode(11);

    // Display the number of nodes, leaves, and the height of the tree.
    cout << "Number of nodes: " << tree.countNode() << endl;
    cout << "Number of leaves: " << tree.countLeaf() << endl;
    cout << "Height: " << tree.getHeight() << endl;

    return 0;
}