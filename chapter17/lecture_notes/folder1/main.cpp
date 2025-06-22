#include <iostream>
#include <cstdlib>
using namespace std;

// Declare the node.
struct ListNode
{
    int data;
    ListNode *next;
};

// Function prototypes.
void appendNode(ListNode* &theList, int data);
void prependNode(ListNode* &theList, int data);
int countNodeRecursive(ListNode* theList);
void insertNodeRecursive(ListNode* &theList, int data, int position);
void deleteNodeRecursive(ListNode* &theList, int position);
void displayListRecursive(ListNode *theList);
int searchNodeRecursive(ListNode *theList, int value);

int main()
{
    // New linked list named numberList.
    ListNode *list = nullptr;   // List head.

    // Append some nodes to the list.
    appendNode(list, 25);
    appendNode(list, 27);
    appendNode(list, 30);
    appendNode(list, 1);

    // Display the list.
    cout << "There are " << countNodeRecursive(list) << " elements in the list: ";
    displayListRecursive(list);
    
    // Prepend some nodes.
    cout << "\n\nPrepending some nodes..." << endl;
    prependNode(list, 74);
    prependNode(list, 77);
    
    // Display the list again.
    cout << "There are " << countNodeRecursive(list) << " elements in the list: ";
    displayListRecursive(list);

    // Insert a node at position 3.
    insertNodeRecursive(list, 05, 3);
    cout << "\nInserting 5 at position 3: ";
    displayListRecursive(list);

    // Delete a node at position 3.
    deleteNodeRecursive(list, 3);
    cout << "\nDelete node at position 3: ";
    displayListRecursive(list);

    // Search for the value 25.
    cout << "\nPosition of 25: " << searchNodeRecursive(list, 25) << endl;
    return 0;
}

// theList is the address of the linked list (= head).
void appendNode(ListNode* &theList, int data)   // Add at the end of the list.
{
    // Allocate a new node and store data there, and make it point to NULL.
    ListNode *newNode = new ListNode;
    newNode->data = data;
    newNode->next = nullptr;

    // If theList is empty, then make newNode
    // the first node.
    if (theList == nullptr)
    {
        theList = newNode;
        return;
    }

    // Travel to the end of the list.
    ListNode *nodePtr;      // To travel the list.

    // Position the nodePtr to the head of the list.
    nodePtr = theList;

    // While the nodePtr is not null, then skip it.
    while (nodePtr->next != nullptr)
    {
        // Move to the next node.
        nodePtr = nodePtr->next;
    }

    // Make the last node point to newNode.
    nodePtr->next = newNode;
}

// Function displayList.
void displayListRecursive(ListNode *theList)
{
    // Base case: If there are no nodes in theList
    // then do nothing.
    if (theList == nullptr)
    {
        return;
    } 
    // Recursive step: If the list is not empty, then
    // display the current node and the next node.
    cout << theList->data << " ";
    displayListRecursive(theList->next);
}

// Function prependNode: to insert a node at the beginning of the list.
void prependNode(ListNode* &theList, int data)
{
    // Allocate a new node and store data there.
    ListNode* newNode = new ListNode;
    newNode->data = data;

    // If theList is an empty list, then make the head
    // point to newNode.
    if (theList == nullptr)
    {
        theList = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, make newNode point to the first node and
    // point the head to newNode.
    else
    {
        newNode->next = theList;
        theList = newNode;
    }
}

// Function countNode: to count and return the number of nodes
// in the list.
int countNodeRecursive(ListNode *theList)
{
    // Base case: If theList is empty, then returns 0.
    if (theList == nullptr)
    {
        return 0;
    }
    // Recursive step: Returns 1 plus the number of nodes
    // in the sublist.
    return 1 + countNodeRecursive(theList->next);
}

// Function insertNode: to insert a node at a position.
void insertNodeRecursive(ListNode* &theList, int data, int position)
{
    // If the position is out of the range, then display an error
    // message and exit the program.
    int maxPosition = countNodeRecursive(theList);
    if (position < 0 || position > maxPosition)
    {
        cout << "IndexError: Out-of-range position.\n";
        exit(EXIT_FAILURE);
    }

    // Allocate a new node and store data there.
    ListNode *newNode = new ListNode;
    newNode->data = data;

    // If position is at the beginning of the list, insert
    // newNode there.
    if (position == 0)
    {
        newNode->next = theList;
        theList = newNode;
        return;
    }
    // Recursive step: move forward and insert at position - 1
    insertNodeRecursive(theList->next, data, position - 1);
}

// Function deleteNodeRecursive: to delete a node at a position.
void deleteNodeRecursive(ListNode* &theList, int position)
{
    // If the position is out of the range, then display an error
    // message and exit the program.
    int maxPosition = countNodeRecursive(theList);
    if (position < 0 || position >= maxPosition)
    {
        cout << "IndexError: Out-of-range position.\n";
        exit(EXIT_FAILURE);
    }

    // Base case: If the position is at the beginning of the list.
    if (position == 0)
    {
        ListNode *temp = theList;
        theList = theList->next;
        delete temp;
        return;
    }
    // Recursive step: move to the next node, decrease position
    deleteNodeRecursive(theList->next, position - 1);
}

// Function searchNodeRecursive: to return the position of a node.
int searchNodeRecursive(ListNode *theList, int value)
{
    if (theList == nullptr)
    {
        return -1;
    }

    if (theList->data == value)
    {
        return 0;
    }

    int posInRest = searchNodeRecursive(theList->next, value);

    if (posInRest == -1)
        return -1;
    else
        return 1 + posInRest;
}