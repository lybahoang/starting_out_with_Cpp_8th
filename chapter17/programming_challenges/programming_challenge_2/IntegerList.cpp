#include "IntegerList.h"
#include <iostream>
using namespace std;

// Destructor.
// The destructor is going to delete all the nodes
// in the list.
IntegerList::~IntegerList()
{
    ListNode *nodePtr;  // To traverse the list.
    ListNode *nextNode; // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {
        // Save the pointer of the next node to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Position nodePtr to the next node.
        nodePtr = nextNode;
    }
}

// Operation: IntegerList::appendNode.
void IntegerList::appendNode(const int &num)
{
    ListNode *newNode;      // The new node.
    ListNode *nodePtr;      // To traverse the list.

    // Create a new node and store num in the node.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, then make
    // the newNode the first node.
    if (!head)
    {
        head = newNode;
    }
    // Otherwise, insert newNode at the end of the list.
    else
    {
        // Initialize nodePtr to the head of the list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

// Operation: IntegerList::insertNode.
void IntegerList::insertNode(const int &num)
{
    ListNode *newNode;      // A new node.
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // The previous node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list, then
    // make newNode the first node.
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousPtr to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr->next != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st node in the list,
        // then insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        // Otherwise, insert after previous node.
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Operation: IntegerList::deleteNode
void IntegerList::deleteNode(const int &num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // To point to the previous node.

    // If the list is empty, do nothing.
    if (!head)
    {
        return;
    }
    
    // Determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Position nodePtr to the head of the list.
        nodePtr = head;

        // Skip all nodes whose value member is not
        // equal to num.
        while (nodePtr->next != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}


// Operation: IntegerList::print
void IntegerList::print() const
{
    ListNode *nodePtr;  // To traverse the node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, display the
    // value of the node.
    while (nodePtr)
    {
        // Display the value in the node.
        cout << nodePtr->value << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}