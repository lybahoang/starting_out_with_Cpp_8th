#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    /** Demo input:
            30
           /  \
         15    50
        /  \
       5    20
     */

    // Create a tree that looks like the demo.
    BinaryTree<int> tree1;
    tree1.insertNode(30);
    tree1.insertNode(15);
    tree1.insertNode(50);
    tree1.insertNode(5);
    tree1.insertNode(20);

    // Initialize another tree to tree1 (using copy constructor).
    BinaryTree<int> tree2 = tree1;

    // Display the data in the two tree via the in-order traversal.
    cout << "Tree 1: ";
    tree1.displayInOrder();

    cout << "\nTree 2: ";
    tree2.displayInOrder();

    // Modify tree 2.
    tree2.insertNode(100);

    cout << "\nNew tree 2: ";
    tree2.displayInOrder();

    cout << "\nTree 1: ";
    tree1.displayInOrder();

    // Assign tree2 to tree1.
    tree1 = tree2;

    // Display tree1.
    cout << "\nNew tree 1: ";
    tree1.displayInOrder();

    return 0;
}