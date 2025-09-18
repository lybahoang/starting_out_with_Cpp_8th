#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a BinarySearchTree for doubles.
    BinarySearchTree<double> myDoubleTree;

    // Insert into the tree some values.
    myDoubleTree.insertNode(25.9);
    myDoubleTree.insertNode(30.9);
    myDoubleTree.insertNode(5.1);
    myDoubleTree.insertNode(27.1);

    // Display the number of nodes in the tree.
    cout << "Number of nodes: " << myDoubleTree.countNode() << endl;
    
    // Display the data in the tree via the inorder traversal.
    myDoubleTree.displayInOrder();

    return 0;
}