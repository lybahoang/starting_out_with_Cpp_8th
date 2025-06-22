#include "IntegerList.h"
#include <iostream>
using namespace std;

// Copy constructor.
IntegerList::IntegerList(const IntegerList &other)
{
    ListNode *otherCurrentNode;  // To traverse the other list.
    ListNode *currentNode;       // To traverse the current list.
    ListNode *newNode;           // A new node.
    
    // If the other list is empty, then make the head
    // point to a null pointer.
    if (other.head == nullptr)
    {
        this->head = nullptr;
    }
    // Otherwise, copy all nodes.
    else
    {
        // Initialize otherCurrentNode to the head of the other list.
        otherCurrentNode = other.head;

        // Copy the first node.
        newNode = new ListNode;
        newNode->value = otherCurrentNode->value;
        newNode->next = nullptr;
        this->head = newNode;

        // Initialize the currentNode to the first node.
        currentNode = this->head;

        // Move to the next node.
        otherCurrentNode = otherCurrentNode->next;

        // Copy all nodes.
        while (otherCurrentNode != nullptr)
        {
            newNode = new ListNode;
            newNode->value = otherCurrentNode->value;
            newNode->next = nullptr;
            currentNode->next = newNode;
            otherCurrentNode = otherCurrentNode->next;
        }
    }
}

// Destructor.
IntegerList::~IntegerList()
{
    ListNode *nodePtr;  // To traverse the list.
    ListNode *nextNode; // To point to the next node.

    // Initialize nodePtr to the head of the list.
    nodePtr = head;

    // Delete all nodes.
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the nodePtr.
        delete nodePtr;

        // Position nodePtr to the next node.
        nodePtr = nextNode;
    }
}


// Operation: IntegerList::appendNode
void IntegerList::appendNode(int num)
{
    ListNode *nodePtr;  // To traverse the list.
    ListNode *newNode;  // A new node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, make
    // the newNode the first node.
    if (head == nullptr)
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


// Operation: IntegerList::insertNode
void IntegerList::insertNode(int num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // To point to the previous node.
    ListNode *newNode;      // A new node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list, then
    // make newNode as the first node.
    if (head == nullptr)
    {
        head = newNode;
        head->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Initialize nodePtr to the head of the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr->next != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the node appears as the 1st node, make
        // newNode as the first node.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        // Otherwise, insert node after the previous node.
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


// Operation: IntegerList::deleteNode
void IntegerList::deleteNode(int num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // To point to the previous node.

    // If there are no nodes, do nothing.
    if (head == nullptr)
    {
        return;
    }
    
    // Determine if the first node is the one to delete.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Intialize nodePtr to the head of the list.
        nodePtr = head;

        // Skip all nodes whose value member is not
        // equal to num.
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
    }

    // If nodePtr is not at the end of the list,
    // link the previous node to the node after
    // nodePtr and delete nodePtr.
    if (nodePtr != nullptr)
    {
        previousNode = nodePtr->next;
        delete nodePtr;
    }
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