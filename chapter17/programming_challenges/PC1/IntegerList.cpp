#include "IntegerList.h"
#include "iostream"
using namespace std;


// Linked list operation: LinkedNode::appendNote
void IntegerList::appendNode(int value)
{
    LinkedNode* nodePtr;    // To move through the list.
    LinkedNode* newNode;    // The new node.

    // Create a new node.
    newNode = new LinkedNode;

    // Store data in the new node.
    newNode->value = value;
    newNode->next = nullptr;

    // If there are no nodes in the list, then
    // make the new node the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    // Else, find the last node and add the new node to
    // the end of the list.
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while(nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Add the new node to the end of the list.
        nodePtr->next = newNode;
    }
}

// Linked list operation: IntegerList::insertNode
void IntegerList::insertNode(int value)
{
    LinkedNode *newNode;        // A new node.
    LinkedNode *previousNode;   // The previous node.
    LinkedNode *nodePtr;        // To traverse the list.

    // Allocate a new node and store value there.
    newNode = new LinkedNode;
    newNode->value = value;
    
    // If there are no nodes in the list, then make
    // the new node the first node.
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else    // Otherwise, insert newNode.
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than value.
        while (nodePtr != nullptr && nodePtr->value < value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If the new node is to be the 1st in the list
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    // Otherwise, insert after the previousNode.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Linked list operation: IntegerList::deleteNode
void IntegerList::deletingNode(int value)
{
    LinkedNode *nodePtr;        // To traverse the list.
    LinkedNode *previousNode;   // To point to the previous node.

    // If the list is empty, do nothing.
    if (head == nullptr)
    {
        return;
    }

    // Determine if the first node is the one.
    if (head->value == value)
    {   
        // Initalize nodePtr to the next node.
        nodePtr = head->next;
        // Delete the first node.
        delete head;
        // Assign the nodePtr to the head.
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value member is not
        // equal to value.
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr != nullptr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// Destructor.
IntegerList::~IntegerList()
{
    LinkedNode *nodePtr;    // To traverse the list.
    LinkedNode *nextNode;   // To point to the next node.

    // Position the nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

// Function IntegerList::displayList
void IntegerList::displayList() const
{
    LinkedNode *nodePtr;    // To traverse the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr != nullptr)
    {
        // Display the value in the node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }

}