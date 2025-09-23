#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

int main()
{
    /** Demo input
            40
           /  \
         25    70
        /  \
       10  30
     */

    // Create a tree that looks like the demo.
    BinaryTree<int> tree1;
    tree1.insertNode(40);
    tree1.insertNode(25);
    tree1.insertNode(70);
    tree1.insertNode(10);
    tree1.insertNode(30);

    // Display tree1.
    cout << "tree1: ";
    tree1.displayInOrder();
    cout << "\nNumber of nodes: " << tree1.countNode() << endl;
    cout << "Number of leaves: " << tree1.countLeaf() << endl;
    cout << "Height: " << tree1.getHeight() << endl;
    cout << "Width: " << tree1.getWidth() << endl;

    // Get a queue containing the values of a tree in ascending order.
    queue<int> queue1;
    queue1 = tree1.toQueue();

    // Display the values in queue1.
    cout << "queue1: ";
    while (!queue1.empty())
    {
        int value = queue1.front();
        queue1.pop();

        cout << value << "  ";
    }

    return 0;
}