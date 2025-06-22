#include "IntegerList.h"
#include <iostream>
using namespace std;

// Destructor.
IntegerList::~IntegerList()
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *nextNode;     // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list,
    // save the next node and delete nodePtr.
    while (nodePtr)
    {
        // Save the next node to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

// Operation IntegerList::appendNode
void IntegerList::appendNode(int value)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // A new node.

    // Allocate a new node, store value there, and
    // make it point to a nullptr.
    newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;

    // If there are no nodes in the list, then make
    // newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr at the head of the list to
        // start traversing the list.
        nodePtr = head;

        // Search for the end of the list.
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Append newNode.
        nodePtr->next = newNode;
    }
}

// Operation IntegerList::insertNode
void IntegerList::insertNode(int value)
{
    ListNode *nodePtr;      // To move through the list.
    ListNode *newNode;      // To point to a new node.
    ListNode *previousNode; // To point to the previous node.

    // Allocate a new node and store value there.
    newNode = new ListNode;
    newNode->value = value;

    // If there are no nodes in the list, then make
    // newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
        head->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is less than value.
        while (nodePtr != nullptr && nodePtr->value < value)
        {
            // Make previousNode point to the nodePtr.
            previousNode = nodePtr;

            // Move to the next node.
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // then make newNode the first node.
        if (previousNode == nullptr)
        {
            // Make the head point to the new node.
            head = newNode;

            // Make the next node of the head to be the nodePtr.
            head->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Operation IntegerList::deleteNode
void IntegerList::deleteNode(int value)
{
    ListNode *previousNode;     // To point to the previous node.
    ListNode *nodePtr;          // To traverse the list.

    // If there are no nodes in the list, then
    // do nothing.
    if (head == nullptr)
    {
        return;
    }

    // If the first node is the one to delete.
    if (head->value == value)
    {
        // Save the next node to nodePtr.
        nodePtr = head->next;

        // Delete the first node.
        delete head;

        // Point the head to nodePtr.
        head = nodePtr;
    }

    // Otherwise, find the node to delete.
    else
    {
        // Position nodePtr at the head of the list to
        // start traversing the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is not equal to
        // value.
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            // Make previousNode point to the current node.
            previousNode = nodePtr;

            // Make nodePtr point to the next node.
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, then
        // make previousNode point to the node after 
        // nodePtr and delete nodePtr.
        if (nodePtr != nullptr)
        {
            // Make previousNode point to the node after nodePtr.
            previousNode->next = nodePtr->next;

            // Delte nodePtr.
            delete nodePtr;
        }
    }
}

// Operation IntegerList::reverse
void IntegerList::reverse()
{
    // If there are no nodes in the list, then do nothing.
    if (head == nullptr)
    return;
    
    ListNode *previousNode;     // To point to the previouse node.
    ListNode *currentNode;      // To point to the current node.
    ListNode *nextNode;         // To point to the next node.
    
    // Initialize previousNode to a null pointer.
    previousNode = nullptr;

    // Position currentNode to the head of the list.
    currentNode = head;

    // While currentNode is not at the end of the list.
    while (currentNode != nullptr)
    {
        // Position nextNode to be the node after the head.
        nextNode = currentNode->next;

        // Make the currentNode point to the previous node.
        currentNode->next = previousNode;

        // Make previousNode point to the current node.
        previousNode = currentNode;

        // Make currentNode point to nextNode to continue the loop.
        currentNode = nextNode;
    }

    // Make the head point to the last node.
    head = previousNode;
}

/***
 * Operation search: The function searches for a value stored
 * in searchValue. It returns the position of the node containing
 * the value. If searchValue is not found, it returns -1.
 */
int IntegerList::search(int searchValue)
{
    int index = 0;          // Loop counter.
    bool isFound = false;   // A flag.

    // If there are no nodes in the list, then return -1.
    if (head == nullptr)
        return -1;

    // A variable to move through the list.
    ListNode *nodePtr;

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {
        // If the value in nodePtr is equal to searchValue.
        if (nodePtr->value == searchValue)
        {
            isFound = true;
            break;
        }
        // Otherwise, increment the loop counter and move
        // to the next node.
        index++;
        nodePtr = nodePtr->next;
    }

    // If the searchValue is not found, return -1.
    if (!isFound)
        return -1;
    // Otherwise, return the position of the node.
    return index;
}

// Operation IntegerList::displayNode
void IntegerList::displayList() const
{
    ListNode *nodePtr;  // To traverse the list.

    // Initalize nodePtr to the head of the list.
    nodePtr = head;

    // While nodePtr is not a null pointer, display
    // the value of the node.
    while (nodePtr != nullptr)
    {
        // Display the value of the node.
        cout << nodePtr->value << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}