#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    // Create a BinarySearchTree for double data type.
    BinarySearchTree<double> myTree;

    // Insert into the tree some values.
    myTree.insertNode(30.9);
    myTree.insertNode(25.9);
    myTree.insertNode(60.8);
    myTree.insertNode(18.8);
    myTree.insertNode(27.7);
    myTree.insertNode(70.1);

    /**
                30.9
                /  \
            25.9    60.8
            /  \        \
        18.8    27.7     70.1
     */

    // Display the tree via postorder traversal.
    cout << "Postorder:\n";
    myTree.displayPostOrder();

    // Display the tree via preorder traversal.
    cout << "\nPreorder:\n";
    myTree.displayPreOrder();

    // Display the tree via inorder traversal.
    cout << "\nInorder:\n";
    myTree.displayInOrder();

    return 0;
}