#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an IntBinaryTree object.
    IntBinaryTree myTree;
    
    // Display the value in the tree.
    myTree.displayInOrder();

    // Insert the tree with some values (Take a look at figure1.png)
    myTree.insertNode(25);
    myTree.insertNode(14);
    myTree.insertNode(36);
    myTree.insertNode(8);
    myTree.insertNode(18);
    myTree.insertNode(15);
    myTree.insertNode(27);
    myTree.insertNode(41);
    myTree.insertNode(30);
    myTree.insertNode(26);
    myTree.insertNode(45);
    myTree.insertNode(1);
    myTree.insertNode(10);

    // Display the tree via inorder traversal.
    cout << "Display the tree via inorder traversal, which is\n";
    cout << "to display the tree in ascending order:\n";
    myTree.displayInOrder();

    // Remove the node that holds the value 27 in the tree (See figure2.png)
    myTree.remove(27);
    
    // Display the tree again via inorder traversal.
    cout << "\nAfter deleting the value 27:\n";
    myTree.displayInOrder();

    // Check if the value 27 is in the tree.
    cout << "\nIs 27 in the tree now? ";
    cout << (myTree.searchNode(27) ? "Yes" : "No") << endl;

    return 0;
}