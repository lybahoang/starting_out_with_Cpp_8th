#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an IntBinaryTree object.
    IntBinaryTree myTree;

    // Insert into the tree some values.
    myTree.insertNode(25);
    myTree.insertNode(50);
    myTree.insertNode(27);
    myTree.insertNode(18);
    myTree.insertNode(5);
    myTree.insertNode(30);

    // Display the number of leaves (= 2).
    cout << "Number of leaves: " << myTree.countLeaf() << endl;

    return 0;
}