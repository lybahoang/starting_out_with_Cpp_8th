#include "NumberList.h"

// Function NumberList::appendNode
void NumberList::appendNode(double num)
{
    ListNode *newNode;  // To point to a new node.
    ListNode *nodePtr;  // To move through the list.

    // Allocate a new mode and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list,
    // make newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    else    // Otherwise, insert newNode at end.
    {
        // Inititalize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}


// Function NumberList::displayList
void NumberList::displayList() const
{
    ListNode *nodePtr;  // To move through the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}


// Function NumberList::insertNode
void NumberList::insertNode(double num)
{
    ListNode *newNode;      // A new node.
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // The previous node.

    // Allocate a new mode and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else    // Otherwise, insert newNode.
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    // Otherwise, insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


// Function NumberList::deleteNode
void NumberList::deleteNode(double num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode;  // To point to the previous node.

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
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value member is 
        // not equal to num.
        while (nodePtr != nullptr && nodePtr->value != num)
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

// Destructor.
NumberList::~NumberList()
{
    ListNode *nodePtr;  // To traverse the list.
    ListNode *nextNode; // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr to the next node.
        nodePtr = nextNode;
    }
}